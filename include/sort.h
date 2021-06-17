#ifndef _SORT_H_
#define _SORT_H_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAX_LENGTH_INSERT_SORT 7 /* 用于快速排序时判断是否选用插入排序阙值 */

typedef int Status; 


#define MAXSIZE 10000  /* 用于要排序数组个数最大值，可根据需要修改 */
typedef struct
{
    int r[MAXSIZE+1];    /* 用于存储要排序数组，r[0]用作哨兵或临时变量 */
    int length;            /* 用于记录顺序表的长度 */
}SqList;

#define INFO(...)                                                               \
    do {                                                                     \
        fprintf(stderr,"%s:%s:%d: ", __FILE__, __func__, __LINE__);         \
        fprintf(stderr,__VA_ARGS__);                                         \
        fprintf(stderr,"\n");                                                \
    } while (0);

#define DEBUG(...)                                                       \
do {                                                                     \
    fprintf(stderr,"%s:%s:%d: ", __FILE__, __func__, __LINE__);         \
    fprintf(stderr,__VA_ARGS__);                                         \
    fprintf(stderr,"\n");                                                \
} while (0);
#endif