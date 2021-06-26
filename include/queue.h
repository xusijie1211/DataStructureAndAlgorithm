#ifndef _QUEUE_H_
#define _QUEUE_H_
#define MAXSIZE 20
typedef int data_t;
typedef struct
{
    data_t data[MAXSIZE];
    int front;//队头位置
    int rear;//队尾位置
}SqQueue;

#endif