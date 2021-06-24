/*
 * @Author: your name
 * @Date: 2021-06-24 18:24:23
 * @LastEditTime: 2021-06-24 18:45:49
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /DataStructureAndAlgorithm/Trees/libBiSortTree/libBiSortTrees.h
 */
#ifndef _LIBBISORTTREES_H_
#define _LIBBISORTTREES_H_

#include <trees/libtree_link.h>

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p);
Status InsertBST(BiTree *T, int key);
Status DeleteBST(BiTree *T,int key);

#endif
