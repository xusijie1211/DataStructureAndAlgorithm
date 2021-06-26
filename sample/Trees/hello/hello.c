/*
 * @Author: your name
 * @Date: 2021-06-23 17:35:57
 * @LastEditTime: 2021-06-24 18:44:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /DataStructureAndAlgorithm/Trees/hello/hello.c
 */
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <BiSortTree/libBiSortTrees.h>
int main(void)
{	
	int i;
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T=NULL;
	
	for(i=0;i<10;i++)
	{
		InsertBST(&T, a[i]);
	}
	PrintBiTree(T);
	InOrderTraverse(T);
	DeleteBST(&T,93);
	DeleteBST(&T,47);
	printf("本样例建议断点跟踪查看二叉排序树结构");
	return 0;
}