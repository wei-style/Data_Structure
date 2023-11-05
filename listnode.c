#include "listnode.h"

linklist list_create(void)
{
	linklist H;
	H = (linklist)malloc(sizeof(listnode));
	if (H == NULL)
	{
		printf("list created fail");
		return NULL;
	}
	memset(H, 0, sizeof(listnode));
	H->data = NULL;
	return H;
}

int list_insert_tail(linklist H, data_t value)
{
	if (H == NULL)
	{
		printf("list is ilegal,cannot insert\n");
		return -1;
	}
	//创立新结点用来存放数据
	linklist q;
	q = list_create();
	q->data = value;
	//找到最后的结点，最后的结点中next储存的是NULL
	linklist p;
	p = H;
	while (p->next!= NULL)
	{
		p = p->next;
	}
	//找到最后一个结点后，让这个结点的next指向新创建的节点，这样就实现了尾部插入
	p->next = q;
	q->next = NULL;
	return 1;
}
int list_show(linklist H)
{
	if(H==NULL)
	{
		printf("list is ilegal");
		return -1;
	}
	while (H->next != NULL)
	{
		printf("%d ", H->next->data);
		H = H->next;
	}
	printf("\n");
	return 0;
}
linklist list_get(linklist H, int pos)
{
	if (H == NULL)
	{
		printf("list is ilegal\n");
		return NULL;
	}
	if (pos < -1)//假设表头为第-1个结点
	{
		printf("pos is ilegal\n");
		return NULL;
	}
	//开始遍历这个链表,寻找pos这个位置的结点

	int i = -1;//从表头开始遍历，每后移一位i+1，i代表的就是结点位置
	while (i < pos)
	{
		H = H->next;
		if(H==NULL)//如果查找到表尾依然没找到pos对应的结点，则返回空指针
		{
			printf("pos is ilegal\n");
			return NULL;
		}
		i++;
	}
	return H;
}
linklist list_insert(linklist H, data_t data, int pos)
{
	if (H == NULL)
	{
		printf("list is ilegal\n");
		return NULL;
	}
	//创建新结点存放数据
	linklist p;
	p = list_create();
	p->data = data;
	//找到要插入位置的前一个结点的指针
	linklist q = list_get(H, pos - 1);
	//如果找不到这个指针说明pos不合法
	if (q == NULL)
	{
		printf("pos is ilegal\n");
			return NULL;
	}
	//找到这个指针后
	//让新结点中的next指向pos的下一个结点
	p->next = q->next;
	//让pos前一个结点的next指向新结点
	q->next = p;
	return p;

}
int list_delete(linklist H, int pos)
{
	if (H == NULL)
	{
		printf("list is ilegal\n");
		return -1;
	}
	linklist q;
	q = list_get(H,pos - 1);//找到要删除结点的前一个结点
	//找不到说明这个结点不合法
	if (q == NULL)
	{
		return -1;
	}
	//找到这个节点后
	linklist p;
	p = q->next;//储存要删除结点的指针
	q->next = q->next->next;//让前一个结点指向要删除结点的下一个结点
	free(p);//删除要删除的结点
	p = NULL;
	return 0;
}