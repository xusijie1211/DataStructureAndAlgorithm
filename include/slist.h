#ifndef _SLIST_H_
#define _SLIST_H_

typedef int data_t;
typedef struct Node
{
	data_t data;
	struct Node *next;
}Node;
typedef struct Node *LinkList;

#endif