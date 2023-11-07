#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef int data_t;
typedef struct node 
{
	data_t data;
	struct node* next;

}listnode,*linkstack;

linkstack stack_create();
int stack_push(linkstack s,data_t value);
data_t stack_pop(linkstack s);
int stack_empty(linkstack s);
data_t stack_top(linkstack s);//返回栈顶的元素值
int stack_free(linkstack s);
