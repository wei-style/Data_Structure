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
linklist list_get(linklist H, int pos)
{
if(H==NULL)
{
	printf("list is ilegal,cannout get the list\n");
	return -1;
}
if (pos == -1)
{
	return H;
}
linklist q;//用来从表头开始遍历
q = H;
int i=-1;//假设表头为-1的位置
while (i < pos)
{
	q = q->next;
	if (q == NULL)
	{
		printf("this pos is ilegal\n");
		return NULL;
	}
	i++;
}
return q;
}
int list_insert(linklist H, data_t value, int pos)
{	//创建一个新节点用来存放新数据
	linklist q = list_create();
	if (q == NULL)
	{
		printf("pos is ilegal\n");
		return -1;
	}
	if (q == NULL)
	{
		printf("list insert failed\n");
		return -1;
	}
	q->data = value;
	//找到pos对应节点的前一个节点
	linklist p = list_get(H, pos - 1);
	//让pos指向下一个节点
	q->next=p->next;
	//让pos之前的节点指向pos节点
	p->next = q;
	return 0;
}
int list_delete(linklist H, int pos)
{
	linklist p;

	if (H == NULL)
	{
		printf("list is NULL\n");
		return -1;
	}
	p = list_get(H, pos-1);//找到前一个的地址
	if (p == NULL)
	{
		return -1;
	}
	if (p->next == NULL)//判断语句一定要是==，如果是=那就成赋值语句了
	{
		printf("delete pos is invalid\n");
		return -1;
	}
	linklist q;
	q = p->next;
	p->next = q->next;
	printf("free: %d\n", q->data);
	free(q);
	q = NULL;
	return 0;
}

linklist list_free(linklist H)
{
	linklist p;
	p = H;
	printf("free:");
	if (H == NULL)
	{
		return NULL;
	}
	while (H != NULL)
	{
		p = H;
		printf("%d ",(H)->data);
		(H) = (H)->next;
		free(p);
	}
	puts("");
	return NULL;
}
