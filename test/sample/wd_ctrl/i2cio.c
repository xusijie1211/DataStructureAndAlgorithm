#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <wd_ctrl.h>
#include <i2c.h>
#include <i2c-dev.h>

#define I2C_DEV_PATH_LEN    32

#define I2C_BUS_READ    0x1
#define I2C_BUS_WRITE   0x2

#define WD_I2C_BUS      9
#define WD_DEV_ADDR     0x37
#define WD_DEV_REG      0x35

#define CHIP_ID_ADDR1   0x5A
#define CHIP_ID_ADDR2   0x5B
#define VENDOR_ID_ADDR1 0x5D
#define VENDOR_ID_ADDR2 0x5E

#define CHIP_ID_HIGH    0x03
#define CHIP_ID_LOW     0x00
#define VENDOR_ID_1     0x19
#define VENDOR_ID_2     0x34

#define WD_DEFAULT_TIMEOUT  0x23    /* 35s */
#define WD_TIMEOUT_MASK     0x7F
#define WD_ENABLE_PIN       (1 << 7)

static int get_i2c_register(int file,  
                            unsigned int addr,  
                            unsigned int reg,  
                            unsigned int *val) {  
    unsigned char inbuf, outbuf;  
    struct i2c_rdwr_ioctl_data packets;  
    struct i2c_msg messages[2];  
  
    /* 
     * In order to read a register, we first do a "dummy write" by writing 
     * 0 bytes to the register we want to read from.  This is similar to 
     * the packet in set_i2c_register, except it's 1 byte rather than 2. 
     */  
    outbuf = reg;  
    messages[0].addr  = addr;  
    messages[0].flags = 0;  
    messages[0].len   = sizeof(outbuf);  
    messages[0].buf   = &outbuf;  
  
    /* The data will get returned in this structure */  
    messages[1].addr  = addr;  
    messages[1].flags = I2C_M_RD;  
    messages[1].len   = sizeof(inbuf);  
    messages[1].buf   = &inbuf;  
  
    /* Send the request to the kernel and get the result back */  
    packets.msgs      = messages;  
    packets.nmsgs     = 2;  
    if(ioctl(file, I2C_RDWR, &packets) < 0) {  
        wd_printf(WD_ERR, "Unable to send data: %s\n", strerror(errno));
        return -1;  
    }  
    *val = inbuf;  
  
    return 0;  
}

static int set_i2c_register(int file,  
                            unsigned int addr,  
                            unsigned int reg,  
                            unsigned int value) {  
  
    unsigned char outbuf[2];  
    struct i2c_rdwr_ioctl_data packets;  
    struct i2c_msg messages[1];  
  
    messages[0].addr  = addr;  
    messages[0].flags = 0;  
    messages[0].len   = sizeof(outbuf);  
    messages[0].buf   = outbuf;  
  
    /* The first byte indicates which register we'll write */  
    outbuf[0] = reg;  
  
    /*  
     * The second byte indicates the value to write.  Note that for many 
     * devices, we can write multiple, sequential registers at once by 
     * simply making outbuf bigger. 
     */  
    outbuf[1] = value;  
  
    /* Transfer the i2c packets to the kernel and verify it worked */  
    packets.msgs  = messages;  
    packets.nmsgs = 1;  
    if(ioctl(file, I2C_RDWR, &packets) < 0) {  
        wd_printf(WD_ERR, "Unable to send data: %s\n", strerror(errno));
        return -1;  
    }

    return 0;
}

static inline char *get_i2c_bus_dev(int i2c_bus)
{
    char *i2c_dev;
    static char dev_path[I2C_DEV_PATH_LEN];

    i2c_dev = dev_path;
    snprintf(dev_path, I2C_DEV_PATH_LEN, "/dev/i2c-%d", i2c_bus);
    return i2c_dev;
}

static char *wd_get_bus_dev(void)
{
    int i;
    int fd, ret;
    char *wd_bus_dev;
    char *i2c_bus_dev;
    unsigned int value;

    wd_bus_dev = NULL;
    for (i = 0; ; i++) {
        wd_printf(WD_DEBUG, "Detect I2C bus %d\n", i);
        i2c_bus_dev = get_i2c_bus_dev(i);
        fd = open(i2c_bus_dev, O_RDONLY);
        if (fd < 0) {
            /* open failed, stop detecting */
            wd_printf(WD_DEBUG, "Failed to open i2c bus %d: %s\n", i, strerror(errno));
            break;
        }

        /**
         * check if chip ID & vendor ID is right.
         * 1. check vendor ID 1
         * 2. check vendor ID 2
         * 3. check chip ID 1 (high byte)
         * 4. check chip ID 2 (low byte)
         */
        ret = get_i2c_register(fd, WD_DEV_ADDR, VENDOR_ID_ADDR1, &value);
        if (ret < 0 || value != VENDOR_ID_1) {
            /* vendor ID 1 unmatch, continue detecting next. */
            continue;
        }
        wd_printf(WD_DEBUG, "bus %d read vendor ID 1 0x%02X\n", i, value);
        ret = get_i2c_register(fd, WD_DEV_ADDR, VENDOR_ID_ADDR2, &value);
        if (ret < 0 || value != VENDOR_ID_2) {
            /* vendor ID 2 unmatch, continue detecting next. */
            continue;
        }
        wd_printf(WD_DEBUG, "bus %d read vendor ID 2 0x%02X\n", i, value);

        ret = get_i2c_register(fd, WD_DEV_ADDR, CHIP_ID_ADDR1, &value);
        if (ret < 0 || value != CHIP_ID_HIGH) {
            /* chip ID High byte unmatch, continue detecting next. */
            continue;
        }
        wd_printf(WD_DEBUG, "bus %d read chip ID 1 0x%02X\n", i, value);
        ret = get_i2c_register(fd, WD_DEV_ADDR, CHIP_ID_ADDR2, &value);
        if (ret < 0 || value != CHIP_ID_LOW) {
            /* chip ID Low byte unmatch, continue detecting next. */
            continue;
        }
        wd_printf(WD_DEBUG, "bus %d read chip ID 2 0x%02X\n", i, value);

        wd_printf(WD_DEBUG, "Detected watchdog bus ID: %d\n", i);
        wd_bus_dev = i2c_bus_dev;
        break;
    }

    return wd_bus_dev;
}

void wd_ctrl(int operate)
{
    char *i2c_bus_dev;
    int fd, ret;
    unsigned int value;
    
    i2c_bus_dev = wd_get_bus_dev();
    fd = open(i2c_bus_dev, O_RDWR);
    if (fd < 0) {
        wd_printf(WD_ERR, "open i2c bus %d: %s\n", WD_I2C_BUS, strerror(errno));
        return;
    }

    switch (operate) {
    case WD_DISABLE:
        ret = get_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, &value);
        if (ret < 0)
            goto error;
        value &= ~WD_ENABLE_PIN;
        ret = set_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, value);
        if (ret < 0)
            goto error;
        wd_printf(WD_INFO, "Watchdog disabled.\n");
        break;
    case WD_ENABLE:
        ret = get_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, &value);
        if (ret < 0)
            goto error;

        /* enable watchdog & reset the time */
        value |= WD_ENABLE_PIN;
        value &= ~WD_TIMEOUT_MASK;
        value |= WD_DEFAULT_TIMEOUT;
        ret = set_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, value);
        if (ret < 0)
            goto error;
        wd_printf(WD_INFO, "Watchdog enabled.\n");
        break;
    case WD_TOUCH:
        ret = get_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, &value);
        if (ret < 0)
            goto error;

        /* reset the time */
        value &= ~WD_TIMEOUT_MASK;
        value |= WD_DEFAULT_TIMEOUT;
        ret = set_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, value);
        if (ret < 0)
            goto error;
        wd_printf(WD_DETAIL, "Watchdog feeds once.\n");
        break;
    case WD_RDTIME:
        ret = get_i2c_register(fd, WD_DEV_ADDR, WD_DEV_REG, &value);
        if (ret < 0)
            goto error;
        printf("Watchdog status: %s\n", (value & WD_ENABLE_PIN ? "enable" : "disable"));
        printf("Watchdog timeout left: %d seconds\n", value & WD_TIMEOUT_MASK);
        break;
    default:
        wd_printf(WD_ERR, "Unknown operation %d!\n", operate);
        break;
    }

error:
    close(fd);
    wd_printf(WD_DEBUG, "Finish to control watchdog.\n");
}

