/**
 * Copyright(C) 2016 Ruijie Network Inc. All rights reserved.
 *
 * wd_ctrl.c
 * Original Author: yejx@ruijie.com.cn, 2016-6-16
 *
 * 喂狗芯片使能与喂狗控制程序
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <wd_ctrl.h>

int wd_log_level = WD_NONE;

static void wd_show_usage(char *program)
{
    printf("Usage: %s [-d level] "
        "[enable | disable | feed | read]\n", program);
    printf("  Default level is 0.\n");
    printf("  Default operation is to show this help.\n");
}

int main(int argc, char *argv[])
{
    char *opt;
    char *program = argv[0];

    if (argc == 1) {
        wd_show_usage(program);
    } else {
        opt = *(++argv);
        if (!strcmp(opt, "-d")) {
            opt = *(++argv);
            wd_log_level = atoi(opt);
            wd_printf(WD_DETAIL, "%s debug level changed to %d\n", program, wd_log_level);
            opt = *(++argv);
        }
        wd_printf(WD_DEBUG, "WD Operation: %s\n", opt);
        if (!strcmp(opt, "enable")) {
            wd_ctrl(WD_ENABLE);
        } else if (!strcmp(opt, "disable")) {
            wd_ctrl(WD_DISABLE);
        } else if (!strcmp(opt, "feed")) {
            wd_ctrl(WD_TOUCH);
        } else if (!strcmp(opt, "read")) {
            wd_ctrl(WD_RDTIME);
        } else {
            wd_show_usage(program);
            return 1;
        }
    }
    return 0;
}

