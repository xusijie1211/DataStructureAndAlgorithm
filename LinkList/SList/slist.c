//注意：该文件操作的单链表为带头结点单链表，头结点数据为-1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <log.h>
#include <slist.h>


int GetElem(LinkList L,int i,data_t *data)//读取单链表的第i个元素
{
	int j;
	LinkList p;
	p = L;
	j = 1;
	while(p && j<i)
	{
		p = p->next;//让p指向下一个节点
		j++;
	}
	if(!p || j>i)
	{
		printf("第%d个位置不存在！\n",i);
		return ERROR;
	}
	*data = p->data;
	return OK;
}

int ListInsert(LinkList *L,int i,data_t e)//插入新节点，使其成为第i个节点
{
	int j;
	LinkList p,s;
	p=*L;
	j=1;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}
	if(!p || j>i)
	{
		printf("第%d个位置不存在！\n",i);
		return ERROR;
	}
	s=(LinkList)malloc(sizeof(Node));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

int ListDelete(LinkList *L,int i,data_t *e)//删除第i个位置节点，数据由e获得
{
	int j;
	LinkList p,q;
	p=*L;
	j=1;
	while(p->next && j<i)
	{
		p=p->next;
		j++;
	}
	if(!(p->next) || j>i)
	{
		printf("第%d个位置不存在！\n",i);
		return ERROR;
	}
	q=p->next;
	p->next=q->next;
	*e=q->data;
	free(q);
	return OK;
}

void CreateListHead(LinkList *L,int n)//创建链表（头插法）
{
	LinkList p, tmp;
	int i;
	srand(time(NULL));//初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->data = -1;
	(*L)->next = NULL;//创建空链表
    printf("L地址:0x%p\n", *L);    
    printf("L->next地址:0x%p\n", &((*L)->next));   
    printf("L->next地址:0x%p\n", ((*L)->next));
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
        printf("p地址:0x%p\n", p);    
        printf("p->next地址:0x%p\n", &(p->next));   
        printf("p->next地址:0x%p\n", p->next);

		p->data = rand()%100+1;
#if 0
		p->next = (*L)->next;
		(*L)->next = p;
#else
        tmp = (*L)->next;
		(*L)->next = p;
		p->next = tmp;
#endif
    printf("L地址:0x%p\n", *L);    
    printf("L->next地址:0x%p\n", &((*L)->next));   
    printf("L->next地址:0x%p\n", ((*L)->next));    
	}
}

void CreateListTail(LinkList *L,int n)//创建链表（尾插法）
{
	LinkList p,r;
	int i;
	srand(time(NULL));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->data = -1;
	r = *L;
	for(i=0;i<n;i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100+1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

// int ClearList(LinkList *L)//销毁链表
// {
// 	LinkList p,q;
// 	p=(*L)->next;
// 	while(p)
// 	{
// 		q=p->next;
// 		free(p);
// 		p=q;
// 	}
// 	(*L)->next=NULL;
// 	return OK;
// }

int ListReverse(LinkList L)//练习1：单链表反序
{
	if(!L)
	{
		printf("单链表反序操作错误！\n");
		return ERROR;
	}
	LinkList p,q;
	p=L->next;//记录头指针
	L->next=NULL;
	while(p!=NULL)
    {
        q=p;
        p=p->next;
        q->next=L->next;
        L->next=q;
    }
	return OK;
}

int PrintList(LinkList L)//遍历打印整个链表
{
    LinkList p=L;
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
LinkList Adjmax(LinkList h)//练习2：寻找最大元素对
{
	LinkList p, p1, q;
	int m0, m1;
	p = h->next;
	p1 = p;
	if(p1 == NULL)
		return  p1;     //表空返回//
	q = p->next;
	if(q == NULL)
		return  p1;      //表长=1时的返回//
	m0 = p->data + q->data;         //相邻两结点data值之和//
	while (q->next  !=  NULL)
	{
		p = q;
		q = q->next;     //取下一对相邻结点的指针//
		m1 = p->data + q->data;
		if(m1 > m0)
		{
			p1 = p;
			m0 = m1;
		}
	}//取和为最大的第一结点指针//
	return p1;
}

LinkList FindMiddleValue(LinkList h)
{
	LinkList p, q;
	int flag = 0;;
	p = q = h;

    while (p != NULL)
	{
        printf("p = %p\n", p);
        if (p->next  == NULL && p->next->next == NULL) {
            flag = 1;
            break;
        }
        p = p->next->next;
        q = q->next;
	}//取和为最大的第一结点指针//

    if (flag == 1) {
        printf("中间值为:%d \n", q->data);
    } else {
        printf("中间值1为:%d \n", q->data);
        printf("中间值2为:%d \n", q->next->data);
    }

	return q;  
}
int main()
{
	
    LinkList head1,head2;
    int i=5;
    data_t data=12;
    printf("头插法创建链表head1：\n");
    CreateListHead(&head1,1);
    PrintList(head1);
    FindMiddleValue(head1);
    /*
    printf("尾插法创建链表head2：\n");
    CreateListTail(&head2,15);
    PrintList(head2);
    printf("插入head1第%d个位置，数据为%d\n",i,data);
    ListInsert(&head1,i,data);
    printf("插入后链表为：\n");
    PrintList(head1);
    i=8;
    ListDelete(&head1,i,&data);
    printf("删除head1第%d个位置，删除数据为%d\n",i,data);
    printf("删除后链表为：\n");
    PrintList(head1);
	LinkList adjmax = Adjmax(head1);
    printf("Adjmax data is %d, Adjmax data next data is %d\n",adjmax->data,adjmax->next->data);
	ListReverse(head1);
	printf("将head1反序：\n");
	PrintList(head1);
    if(ClearList(&head1)==OK)
    {
        printf("head1已被成功删除！\n");
    }
    if(ClearList(&head2)==OK)
    {
        printf("head2已被成功删除！\n");
    }
	*/
    return 0;
}
