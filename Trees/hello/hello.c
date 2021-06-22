#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <Trees/pqueue.h>
/* 用于构造二叉树********************************** */
int tree_index=1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;
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
	PrintBiTree(T);
//	ClearBiTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("树空，无根\n");
	
	return 0;
}
