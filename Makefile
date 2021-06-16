#CROSS_COMPILE = arm-linux-
CROSS_COMPILE = 
AS		= $(CROSS_COMPILE)as
LD		= $(CROSS_COMPILE)ld
CC		= $(CROSS_COMPILE)gcc
CPP		= $(CC) -E
AR		= $(CROSS_COMPILE)ar
NM		= $(CROSS_COMPILE)nm

STRIP		= $(CROSS_COMPILE)strip
OBJCOPY		= $(CROSS_COMPILE)objcopy
OBJDUMP		= $(CROSS_COMPILE)objdump

export AS LD CC CPP AR NM
export STRIP OBJCOPY OBJDUMP

CFLAGS := -Wall -O2 -g			# 编译标志
CFLAGS += -I $(shell pwd)/include		# 编译时头文件位置

LDFLAGS := -lm				# 链接时库文件

export CFLAGS LDFLAGS

TOPDIR := $(shell pwd)
export TOPDIR

TARGET := show_file

#################################################
# 添加需要包含的子目录文件
obj-y += main.o
obj-y += display/
obj-y += draw/
obj-y += encoding/
obj-y += fonts/

all:
	make -C ./ -f $(TOPDIR)/Makefile.build  #切换到-C指定的目录，使用-f指定的Makefile文件【这里就是递归进各个子目录生成built-in.o再生成根目录的built-in.o】
	$(CC) $(LDFLAGS) -o $(TARGET) built-in.o


clean:
	rm -f $(shell find -name "*.o")
	rm -f $(TARGET)
distclean:
	rm -f $(shell find -name	"*.o")
	rm -f $(shell find -name "*.d")
	rm -f $(TARGET)