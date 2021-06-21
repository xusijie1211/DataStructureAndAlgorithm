#ifndef _LQUEUE_H_
#define _LQUEUE_H_
#include <Trees/LinkTree.h>

typedef BiTree data_t;

typedef struct node_t
{
	data_t data;
	struct node_t *next;

} linknode_t, *linklist_t;

typedef struct
{
	linklist_t front, rear;
} linkqueue_t;

int EnQueue(linkqueue_t *queue, data_t x);//入队
int EmptyLinkqueue(linkqueue_t *queue);//判定队列是否为空
linkqueue_t *CreateEmptyLinkqueue();//创建空队列
int VisitQueue(linkqueue_t *queue);
int EnQueue(linkqueue_t *queue, data_t x);//入队
int DeQueue(linkqueue_t *queue, data_t *x);//出队
#endif