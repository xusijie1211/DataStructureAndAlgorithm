#include "stdio.h"

int Fbi(int i)  /* 쳲������ĵݹ麯�� */
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
	return Fbi(i - 1) + Fbi(i - 2);  /* ����Fbi���Ǻ����Լ��������ڵ����Լ� */
}  

int main()
{
	int i;
	int a[40];  
	printf("������ʾ쳲��������У�\n");
	a[0]=0;
	a[1]=1;
	printf("%d ",a[0]);  
	printf("%d ",a[1]);  
	for(i = 2;i < 40;i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
	printf("\n");
	
	printf("�ݹ���ʾ쳲��������У�\n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
	return 0;
}

