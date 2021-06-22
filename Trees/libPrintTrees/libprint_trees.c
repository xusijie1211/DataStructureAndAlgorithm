/*
 * @Author: your name
 * @Date: 2021-06-22 19:08:47
 * @LastEditTime: 2021-06-22 20:23:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /DataStructureAndAlgorithm/Trees/libLinkTree/BiTreeLink.c
 */
#include "string.h"
#include "stdio.h"    
#include "stdlib.h"    
#include <math.h> 
#include "time.h"
#include <log.h>
//#include "pqueue.h"
#include<string.h>
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

int EnQueue(linkqueue_t *queue, data_t x)//入队
{
	linknode_t *node_new;
	int ret;

	if (!queue)
	{
		printf("EnQueue Error\n");
		return ERROR;
	}

	node_new = (linknode_t *)malloc(sizeof(linknode_t));
	node_new->data = x;
	node_new->next = NULL;

	ret = EmptyLinkqueue(queue);
	if(ret == OK) {
		queue->front = queue->rear = node_new;
	}
	else
	{
		queue->rear->next = node_new;
		queue->rear = node_new;
	}
	return OK;
}

int DeQueue(linkqueue_t *queue, data_t *x)//出队
{
	linknode_t *node_remove;

	if(!queue)
	{
		printf("DeQueue Error\n");
		return ERROR;
	}	
	if(EmptyLinkqueue(queue)==OK)
    {
        printf("queue is Empty\n");
        return ERROR;
    }
	node_remove = queue->front;
	queue->front = node_remove->next;

	if (NULL == queue->front) {
		queue->rear = NULL;
	}
	(*x) = node_remove->data;
	free(node_remove);

	return OK;
}

int DestroyLinkqueue(linkqueue_t *queue)//销毁队列
{
	if (queue)
	{
		ClearLinkqueue(queue);
		free(queue);
		return OK;
	}
	else
	{
		printf("DestroyLinkqueue Error\n");
		return ERROR;
	}
}

linkqueue_t *CreateEmptyLinkqueue()//创建空队列
{
	linkqueue_t *queue;

	queue = (linkqueue_t *)malloc(sizeof(linkqueue_t));
	if (NULL == queue)
	{
		perror("Create Empty LinkQueue Error");
		return NULL;
	}
	queue->rear = queue->front = NULL;	
	return queue;
}

int EmptyLinkqueue(linkqueue_t *queue)//判定队列是否为空
{
	if (!queue)
	{
		printf("EmptyLinkqueue Error\n");
		return -1;
	}

	return queue->front == NULL ? OK : ERROR;
}


int power(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

int func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (func(n-1)*2+2);
}

void PrintBiTree(BiTree root)
{
	char a   = 0;
	int i    = 0; //当前层次计数
	int flag = 0; //标记是否为当前层的第一个元素
	BiTree *T;
	int curLayerCount  = 0; //当前层中的节点数
	int nextLayerCount = 0; //下一层中的节点数
	int depth;
	linkqueue_t *queue;
	BiTree p;

	depth = BiTreeDepth(root);
	queue = CreateEmptyLinkqueue();
	EnQueue(queue, root);
	curLayerCount++;

	printf("******************二叉树结构******************\n");	
	printf("*");
	while (OK == DeQueue(queue, &p))
	{
		flag++;
		curLayerCount--;
		if (flag == 1) { /* 左子树的间距 */
	   	 	printf("%*s", func(depth-i-1), "");
		}else{
	   	 	printf("%*s", func(depth-i), "");			
		}
		printf("%02c", p->data);
		if (p->lchild)
		{
			EnQueue(queue, p->lchild);
			nextLayerCount++;
		}else{
			T = CreatEmptyTree();
			EnQueue(queue, T);
			nextLayerCount++;
		}
		if (p->rchild)
		{
			EnQueue(queue, p->rchild);
			nextLayerCount++;
		}else{
			T = CreatEmptyTree();
			EnQueue(queue, T);
			nextLayerCount++;
		}
		if (curLayerCount == 0)//一层已经遍历完毕
		{
			flag = 0;
			i++;
			curLayerCount = nextLayerCount;
			nextLayerCount = 0;
			printf("\n");
			printf("*");
		}
		if (i > depth-1)
		{
			break;
		}
	}
	printf("********************************************\n");		
}
