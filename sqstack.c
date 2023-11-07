#include "sqstack.h"

sqstack* stack_create(int len)
{
	sqstack* s;
	//采用malloc申请出sqstack这个结构体s的空间
	if ((s = (sqstack*)malloc(sizeof(sqstack))) == NULL)
	{
		printf("malloc sqstack failed\n");
		return NULL;
	}
	//采用malloc分配出len长度的data空间
	if ((s->data = (data_t*)malloc(len * sizeof(data_t)))== NULL)
	{
		printf("malloc data failed\n");
		return NULL;
	 }
	memset(s->data, 0, len * sizeof(data_t));
	s->maxlen = len;
	s->top = -1;//栈顶的位置,记录里面数据栈顶的下标
	return s;
}
int stack_push(sqstack* s, data_t value)//入栈
{
	if (s == NULL)
	{
		printf("s is NULL\n");
		return -1;
	}
	if(s->top == s->maxlen - 1)
	{
		printf("stack is full\n");
		return -1;
	}
	s->top++;
	s->data[s->top] = value;
	return 0;
}
int stack_empty(sqstack* s)
{
	if (s == NULL)
	{
		printf("s is NULL\n");
		return -1;
	}
	return (s->top == -1)?1:0;//返回1代表空
}
int stack_full(sqstack* s)
{
	if (s == NULL)
	{
		printf("s is NULL\n");
		return -1;
	}
	return 	(s->top == s->maxlen - 1 )? 1 : 0;//返回1代表满
	
}
data_t stack_pop(sqstack* s)//出栈
{
	s->top--;
	return (s->data[s->top + 1]);

}
data_t stack_top(sqstack* s)
{
	return s->data[s->top];
}
int stack_clear(sqstack* s)
{
	if (s == NULL)
	{
		printf("s is NULL\n");
		return -1;
	}
	s->top = -1;//让栈顶回到最初的位置，之前的数据全部舍弃
	return 0;
}
int stack_free(sqstack* s)
{
	if (s == NULL)
	{
		printf("s is NULL\n");
		return -1;
	}
	if (s->data != NULL)
	{
		free(s->data);
	}
	free(s);
	s = NULL;
	return 0;
}
