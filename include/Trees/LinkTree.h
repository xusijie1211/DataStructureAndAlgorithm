#ifndef _LINKSTREE_H_
#define _LINKSTREE_H_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */



typedef char TElemType;
TElemType Nil=' '; /* 字符型以空格符为空 */

typedef struct BiTNode  /* 结点结构 */
{
   TElemType data;		/* 结点数据 */
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
}BiTNode,*BiTree;

int BiTreeDepth(BiTree T);

#endif