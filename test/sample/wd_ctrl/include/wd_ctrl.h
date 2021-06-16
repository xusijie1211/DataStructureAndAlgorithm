/**
 * Copyright(C) 2016 Ruijie Network Inc. All rights reserved.
 *
 * wd_ctrl.h
 * Original Author: yejx@ruijie.com.cn, 2016-6-16
 *
 * 喂狗芯片使能与喂狗控制程序头文件
 */
#ifndef _WD_CTRL_H_
#define _WD_CTRL_H_

#include <stdio.h>
#include <stdlib.h>

#define WD_DISABLE 0
#define WD_ENABLE  1
#define WD_TOUCH   2
#define WD_RDTIME  3

#define WD_NONE   0
#define WD_ERR    1
#define WD_WARN   2
#define WD_INFO   3
#define WD_DETAIL 4
#define WD_DEBUG  5

extern int wd_log_level;

#define wd_printf(level, fmt, ...)  \
    do {    \
        if (wd_log_level >= (level))    \
            printf("Watchdog<%d> " fmt, level, ##__VA_ARGS__); \
    } while (0)

extern void wd_ctrl(int operate);

#endif /* _WD_CTRL_H_ */
