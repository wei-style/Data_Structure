#include "listnode.h"
linklist list_create(void)
{
	linklist L;
	L = (linklist)malloc(sizeof(listnode));
	if (L == NULL)
	{
		printf("list create failed\n");
		return L;
	}
	
	L->data = 0;
	L->next = NULL;//头节点，假设没有其他节点，那它就不指向其他节点
	return L;
}

int list_tail_insert(linklist H, data_t value)
{//申请新内存
	linklist P; 
	if (H == NULL)
	{
		printf("list is not exit");
		return -1;
	}
	if ((P =(linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc fialed, cannot insert new elements\n");
		return -1;
	}
	//为节点内的数据赋值
	P->data = value;
	P->next = NULL;
	//找到上一个尾节点
	linklist q;
	q = H;//从表头开始往后找，尾节点的next都是空，找到指向空节点的指针就行
	while (q->next != NULL)
	{
		q = q->next;//将下一个节点的地址赋予q，也就是开始判断下一个节点的next是不是空
	}
	//更新尾节点
	q->next=P;
	return 0;
}

int list_show(linklist H)
{
	if (H == NULL)
	{
		printf("list if empty,cannot show it");
		return -1;
	}
	if (H->next == NULL)
	{
		printf("This list is empty,there is nohing to be show\n");
		return -1;
	}

	linklist p;
	p = H;
	while (p->next != NULL)
	{
		printf("%d ", p->next->data);
		p = p->next;
	}
	printf("\n");
	return 0;
}
