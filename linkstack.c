#include "linkstack.h"

linkstack stack_create()
{
	linkstack s;
	if ((s = (linkstack)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	s->data = 0;
	s->next = NULL;
	return s;
}
int stack_push(linkstack s, data_t value)
{
	if (s == NULL)
	{
		printf("s is NULL \n");
		return -1;
	}
	linkstack k;
	k = stack_create();
	if (k == NULL)
	{
		return -1;
	}
	k->data = value;
	k->next = NULL;
	k->next = s->next;
	s->next = k;
	return 0;
}
data_t stack_pop(linkstack s)
{
	linkstack p;
	data_t t;
	p = s->next;
	s->next = p->next;
	t = p->data;
	free(p);
	p = NULL;
	return t;
}
int stack_empty(linkstack s)
{
	if (s == NULL)
	{
		return -1;
	}
	return s->next == NULL ? 1 : 0;
}
data_t stack_top(linkstack s)//返回栈顶的元素值
{
	return s->next->data;
}

int stack_free(linkstack s)
{
	linkstack p;
	if (s == NULL)
	{
		printf("s is NULL\n");
		return NULL;
	}
	while (s != NULL)
	{
		p = s;
		s = s->next;
		printf("free: %d\n", p->data);
		free(p);
	}
	return NULL;
}
