#ifndef _LQUEUE_H_
#define _LQUEUE_H_

typedef int data_t;

typedef struct node_t
{
    data_t data;
    struct node_t *next;

} linknode_t, *linklist_t;

typedef struct
{
    linklist_t front, rear;
} linkqueue_t;
int ClearLinkqueue(linkqueue_t *queue);//清空队列
int DestroyLinkqueue(linkqueue_t *queue);//销毁队列
int EmptyLinkqueue(linkqueue_t *queue);//判定队列是否为空
int EnQueue(linkqueue_t *queue, data_t x);//入队
int DeQueue(linkqueue_t *queue, data_t *x);//出队
int VisitQueue(linkqueue_t *queue);//遍历队列
linkqueue_t *CreateEmptyLinkqueue();//创建空队列
#endif