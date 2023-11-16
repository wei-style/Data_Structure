#include "linkstack.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
linkstack stack_create()
{
	linkstack s;
	s = (linkstack)malloc(sizeof(liststack));
	assert(s);
	s->data = 0;
	s->next = NULL;
	return s;
}

int stack_empty(linkstack s)
{
	if (s == NULL)
	{
		printf(" s is NULL\n");
		return 1;
	}
	if (s->next == NULL)
	{
		printf("s is empty\n");
		return 1;
	}
	return 0;
}
int stack_push(linkstack s, data_t value)
{

	linkstack p;
	p = stack_create();
	p->next = s->next;
	s->next = p;
	p->data = value;
	return 0;
}
data_t stack_pop(linkstack s)
{	
	linkstack p;
	p = s->next;
	s->next = p->next;
	int ret = p->data;
	free(p);
	p= NULL;
	return ret;
}
linkstack stack_free(linkstack s)
{
	return NULL;
}
