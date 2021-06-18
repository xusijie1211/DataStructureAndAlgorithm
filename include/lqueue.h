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

#endif