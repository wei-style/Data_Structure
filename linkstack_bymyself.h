#pragma once
#include "stdlib.h"
#include "assert.h"
#include "stdio.h"
typedef int data_t;
typedef struct stack
{
	data_t data;
	struct stack* next;
}liststack,*linkstack;

linkstack stack_create();
int stack_push(linkstack s, data_t value);
data_t stack_pop(linkstack s);
int stack_empty(linkstack s);
data_t stack_pop(linkstack s);
linkstack stack_free(linkstack s);
