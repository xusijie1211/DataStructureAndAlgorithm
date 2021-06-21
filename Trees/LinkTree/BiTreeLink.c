#include "string.h"
#include "stdio.h"    
#include "stdlib.h"    
#include "math.h"  
#include "time.h"
//#include <Trees/LinkTree.h>
#include <log.h>
#include "pqueue.h"
#include <math.h>
#include<string.h>
/* 用于构造二叉树********************************** */
int tree_index=1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;

Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
/* ************************************************ */



/* 构造空二叉树T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* 有左孩子 */
			DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
		if((*T)->rchild) /* 有右孩子 */
			DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
		free(*T); /* 释放根结点 */
		*T=NULL; /* 空指针赋0 */
	}
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T。 */
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;
	
	/* scanf("%c",&ch); */
	ch=str[tree_index++];

	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(0);
		(*T)->data=ch; /* 生成根结点 */
		CreateBiTree(&(*T)->lchild); /* 构造左子树 */
		CreateBiTree(&(*T)->rchild); /* 构造右子树 */
	}
 }

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return ' ';
	else
		return T->data;
}

/* 初始条件: 二叉树T存在，p指向T中某个结点 */
/* 操作结果: 返回p所指结点的值 */
TElemType Value(BiTree p)
{
	return p->data;
}

/* 给p所指结点赋值为value */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 前序递归遍历T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	PreOrderTraverse(T->lchild); /* 再先序遍历左子树 */
	PreOrderTraverse(T->rchild); /* 最后先序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 中序递归遍历T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* 中序遍历左子树 */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
	InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序递归遍历T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); /* 先后序遍历左子树  */
	PostOrderTraverse(T->rchild); /* 再后序遍历右子树  */
	printf("%c",T->data);/* 显示结点数据，可以更改为其它对结点操作 */
}
int weizhi = 0;
int power(int base, int powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

void printfgeshi(int dep, int i)
{
	int j;
	char buf[100];
	sprintf(buf, "%*s|", power(2,dep)/2, "");
	printf("power(2,dep) = %d\n", power(2,dep));
	for(j = 0; j< power(2,dep); j++) {
		sprintf(buf, "^");
	}
	sprintf(buf, "|");	
	printf("buf = %s\n", buf);
}
void PrintTrees(int dep, int num, int data[])
{
	DEBUG("num = %d, data = %d", num, data);
	weizhi++;

	DEBUG("weizhi = %d   %ld\n", weizhi, power(2,2));
	if (num == 1) {
		printf("%*s%d\n", power(2,dep), "",data[0]);
		printfgeshi(dep, num);	
	}else{
		if (weizhi == 1) {
			printf("%*s%3d%*s\n", power(2,dep)/2, "",data, power(2,dep), "*");	
		}else{
			printf("%*s%d%*s\n", power(2,dep),"", data, power(2,dep), "*");			
		}
	}

}

BiTree  CreatEmptyTree()
{
	BiTree T=(BiTNode *)malloc(sizeof(BiTNode));
	if(!T)
		exit(0);
	T->data='#'; /* 生成根结点 */
	T->lchild = NULL;
	T->rchild = NULL;
	return T;
}

int func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (func(n-1)*2+2);
}

void LayerOrderBiTree(BiTree root)
{
	char a=0;
	int i = 0, j= 0;
	BiTree *T;

	int dep = BiTreeDepth(root);
	int curLayerCount = 0; //当前层中的节点数
	int nextLayerCount = 0; //下一层中的节点数
	linkqueue_t *queue = CreateEmptyLinkqueue();
	EnQueue(queue, root);
	curLayerCount++;
	BiTree p;
	int flag[50] = {0};
	int flag_old[50] = {0};
	int flag_painer = 0;
	//printf("%*s", func(dep-2), "");
	while (OK == DeQueue(queue, &p))
	{
		j++;
		curLayerCount--;
		if (j == 1) {
	   	 	printf("%*s", func(dep-i-1), "");
		}else{
	   	 	printf("%*s", func(dep-i), "");			
		}
		printf("%c ", p->data);
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
			j = 0;
			i++;
			curLayerCount = nextLayerCount;
			nextLayerCount = 0;
			printf("\n");
		}
		if (i > dep-1)
		{
			break;
		}
	}
}


/****
                               100
 *                |^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^| 
                 100                                     100 
 *       |^^^^^^^^^^^^^^^^^^^|                   |^^^^^^^^^^^^^^^^^^^| 
        100                 100                 100                 100
    |^^^^^^^^^|         |^^^^^^^^^|         |^^^^^^^^^|         |^^^^^^^^^| 
    00       00       100       100       100       100       100       100 
 |^^^^^^|   |^^^^^|   |^^^^^|   |^^^^^|   |^^^^^|   |^^^^^|   |^^^^^|   |^^^^^|
100   100 100   100 100   100 100   100 100   100 100   100 100   100 100   100 

                              00          
              00                              00   
      00    
  |^^^^^^^^           00              00              00
  00      00      00      00      00      00      00      00 
|^^^^|  |^^^^^^|
00  00  00  00  00  00  00  00  00  00  00  00  00  00  00  00  
 */


/*
————————————————
版权声明：本文为CSDN博主「yuxiyu!」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/yubo_725/article/details/49978043
*/
int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	printf("*****************");
//	StrAssign(str,"ABDH#K###E##CFI###G#J##");
	StrAssign(str,"ABDG##H###CE#I##F##");
	CreateBiTree(&T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("二叉树的根为: %c\n",e1);

/*
	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
*/
	LayerOrderBiTree(T);
	ClearBiTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("树空，无根\n");
	
	return 0;
}
