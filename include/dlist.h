#ifndef _DLIST_H_
#define _DLIST_H_

#define OK 1
#define ERROR 0

typedef int data_t;
typedef struct DulNode
{
	data_t data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode,*DuLinkList;

#endif