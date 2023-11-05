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
	//�����½�������������
	linklist q;
	q = list_create();
	q->data = value;
	//�ҵ����Ľ�㣬���Ľ����next�������NULL
	linklist p;
	p = H;
	while (p->next!= NULL)
	{
		p = p->next;
	}
	//�ҵ����һ���������������nextָ���´����Ľڵ㣬������ʵ����β������
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
	if (pos < -1)//�����ͷΪ��-1�����
	{
		printf("pos is ilegal\n");
		return NULL;
	}
	//��ʼ�����������,Ѱ��pos���λ�õĽ��

	int i = -1;//�ӱ�ͷ��ʼ������ÿ����һλi+1��i����ľ��ǽ��λ��
	while (i < pos)
	{
		H = H->next;
		if(H==NULL)//������ҵ���β��Ȼû�ҵ�pos��Ӧ�Ľ�㣬�򷵻ؿ�ָ��
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
	//�����½��������
	linklist p;
	p = list_create();
	p->data = data;
	//�ҵ�Ҫ����λ�õ�ǰһ������ָ��
	linklist q = list_get(H, pos - 1);
	//����Ҳ������ָ��˵��pos���Ϸ�
	if (q == NULL)
	{
		printf("pos is ilegal\n");
			return NULL;
	}
	//�ҵ����ָ���
	//���½���е�nextָ��pos����һ�����
	p->next = q->next;
	//��posǰһ������nextָ���½��
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
	q = list_get(H,pos - 1);//�ҵ�Ҫɾ������ǰһ�����
	//�Ҳ���˵�������㲻�Ϸ�
	if (q == NULL)
	{
		return -1;
	}
	//�ҵ�����ڵ��
	linklist p;
	p = q->next;//����Ҫɾ������ָ��
	q->next = q->next->next;//��ǰһ�����ָ��Ҫɾ��������һ�����
	free(p);//ɾ��Ҫɾ���Ľ��
	p = NULL;
	return 0;
}