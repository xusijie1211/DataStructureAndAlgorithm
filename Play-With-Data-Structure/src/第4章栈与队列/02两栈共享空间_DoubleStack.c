#include "stdio.h"	
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status; 

typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */


/* ��ջ�����ռ�ṹ */
typedef struct 
{
		SElemType data[MAXSIZE];
		int top1;	/* ջ1ջ��ָ�� */
		int top2;	/* ջ2ջ��ָ�� */
}SqDoubleStack;


Status visit(SElemType c)
{
		printf("%d ",c);
		return OK;
}

/*  ����һ����ջS */
Status InitStack(SqDoubleStack *S)
{ 
		S->top1=-1;
		S->top2=MAXSIZE;
		return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(SqDoubleStack *S)
{ 
		S->top1=-1;
		S->top2=MAXSIZE;
		return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqDoubleStack S)
{ 
		if (S.top1==-1 && S.top2==MAXSIZE)
				return TRUE;
		else
				return FALSE;
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqDoubleStack S)
{ 
		return (S.top1+1)+(MAXSIZE-S.top2);
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
		if (S->top1+1==S->top2)	/* ջ������������push��Ԫ���� */
				return ERROR;	
		if (stackNumber==1)			/* ջ1��Ԫ�ؽ�ջ */
				S->data[++S->top1]=e; /* ����ջ1����top1+1�������Ԫ�ظ�ֵ�� */
		else if (stackNumber==2)	/* ջ2��Ԫ�ؽ�ջ */
				S->data[--S->top2]=e; /* ����ջ2����top2-1�������Ԫ�ظ�ֵ�� */
		return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
		if (stackNumber==1) 
		{
				if (S->top1==-1) 
						return ERROR; /* ˵��ջ1�Ѿ��ǿ�ջ����� */
				*e=S->data[S->top1--]; /* ��ջ1��ջ��Ԫ�س�ջ */
		}
		else if (stackNumber==2)
		{ 
				if (S->top2==MAXSIZE) 
						return ERROR; /* ˵��ջ2�Ѿ��ǿ�ջ����� */
				*e=S->data[S->top2++]; /* ��ջ2��ջ��Ԫ�س�ջ */
		}
		return OK;
}

Status StackTraverse(SqDoubleStack S)
{
		int i;
		i=0;
		while(i<=S.top1)
		{
				visit(S.data[i++]);
		}
		i=S.top2;
		while(i<MAXSIZE)
		{
				visit(S.data[i++]);
		}
		printf("\n");
		return OK;
}

int main()
{
		int j;
		SqDoubleStack s;
		int e;
		if(InitStack(&s)==OK)
		{
				for(j=1;j<=5;j++)
						Push(&s,j,1);
				for(j=MAXSIZE;j>=MAXSIZE-2;j--)
						Push(&s,j,2);
		}

		printf("ջ��Ԫ������Ϊ��");
		StackTraverse(s);

		printf("��ǰջ��Ԫ���У�%d \n",StackLength(s));

		Pop(&s,&e,2);
		printf("������ջ��Ԫ�� e=%d\n",e);
		printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));

		for(j=6;j<=MAXSIZE-2;j++)
				Push(&s,j,1);

		printf("ջ��Ԫ������Ϊ��");
		StackTraverse(s);

		printf("ջ����%d(1:�� 0:��)\n",Push(&s,100,1));

		
		ClearStack(&s);
		printf("���ջ��ջ�շ�%d(1:�� 0:��)\n",StackEmpty(s));
		
		return 0;
}