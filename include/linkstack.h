#ifndef _QUEUE_H_
#define _QUEUE_H_

#define OK 1
#define ERROR 0
typedef int data_t;
typedef struct StackNode
{
	data_t data;
	struct StackNode *next;
}LinkStack;

#endif