/*
 * @Author: your name
 * @Date: 2021-06-24 18:24:23
 * @LastEditTime: 2021-06-26 10:00:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /DataStructureAndAlgorithm/Trees/libBiSortTree/libBiSortTrees.h
 */
#ifndef _LIBAVLTREES_H_
#define _LIBAVLTREES_H_

#include <trees/libtrees.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码，如OK等 */ 
void R_Rotate(BiTree *P);
void L_Rotate(BiTree *P);
void LeftBalance(BiTree *T);
void RightBalance(BiTree *T);
Status InsertAVL(BiTree *T,int e,Status *taller);
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p);
Status InsertBST(BiTree *T, int key);
Status DeleteBST(BiTree *T,int key);

#endif
