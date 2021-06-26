/*
 * @Author: your name
 * @Date: 2021-06-23 17:35:57
 * @LastEditTime: 2021-06-26 10:03:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /DataStructureAndAlgorithm/Trees/libtrees/libtree_link.h
 */
#ifndef _LIBTREES_H_
#define _LIBTREES_H_

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */



typedef int TElemType;
//TElemType Nil=' '; /* 字符型以空格符为空 */

typedef struct BiTNode  /* 结点结构 */
{
   TElemType data;		/* 结点数据 */
   int bf; /*  结点的平衡因子 */ 
   struct BiTNode *lchild,*rchild; /* 左右孩子指针 */
}BiTNode,*BiTree;

int BiTreeDepth(BiTree T);
void DestroyBiTree(BiTree *T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
void CreateBiTree(BiTree *T);
TElemType Root(BiTree T);
TElemType Value(BiTree p);
void Assign(BiTree p,TElemType value);
void PreOrderTraverse(BiTree T);
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T);


#endif