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
linklist list_free(linklist H)
{
	linklist p;
	p = H;
	if (H == NULL)
	{
		printf("H is ilegal\n");
		return NULL;
	}
	printf("free: ");
	while (H->next != NULL)
	{
		H = H->next;
		printf("%d ", p->data);
		free(p);
		p = H;	
	}
	return NULL;
}
int list_reverse(linklist H)//链表翻转，表头不变，其他元素倒序排列
{
	if (H == NULL)
	{
		printf("H is ilegal\n");
		return -1;
	}
	if (H->next->next == NULL)
	{
		return 0;//只有一个元素不需要翻转
	}
	linklist p, q,r;
	p = H->next;//这是原始链表第一个结点的指针
	q = p->next;//这是原始链表第二个结点的指针
	p->next = NULL;//将原始链表的第一个结点与后续结点断开
	//从第二个结点开始，依次将所有结点都放入表头与第一个结点之间
	while (q != NULL)
	{
		r = q->next;//储存需要倒置的结点的下一个结点信息
		//将q结点放在表头与第一个节点之间
		q->next = p;
		H->next = q;
		//将此时的第一个结点更新
		p = q;
		//准备倒置下一个结点
		q =r;
	}
	return 0;
}
//求相邻两个结点和的最大值,返回其中第一个结点的指针
linklist list_adjmax(linklist H)
{
	data_t sum_hold,sun_new;
	linklist p,r;
	if (H == NULL)
	{
		printf("H is ilegal\n");
		return NULL;
	}
	if (H->next == NULL)
	{
		printf("there is only one junction\n");
		return NULL;
	}
	if (H->next->next == NULL)//只有两个结点时，直接返回第一个结点的指针就行
	{
		return H->next;
	}
	p = H->next->next;//第二个节点的地址
	H = H->next;//第一个结点的地址
	r = H;//用于记录最大值出现的位置
	sum_hold =0;
	sun_new = 0;
	while (p!=NULL)
	{
		sun_new = H->data + p->data;
		if(sum_hold<sun_new)
		{
			sum_hold = sun_new;
			r = H;
		}
		H = H->next;
		p = p->next;
	}
	printf("adjmax=%d\n", r->data);
	return r;
}
//合并两个顺序链表,返回H1的指针
linklist list_merge(linklist H1, linklist H2)
{
	if (H1 == NULL)
	{
		printf("H1 is ilegal\n");
		return NULL;
	}
	if (H2 == NULL)
	{
		printf("H2 is ilegal\n");
		return NULL;
	}
	linklist r;
	r = H1; 
	

}

