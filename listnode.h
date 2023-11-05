#pragma once
#include "stdio.h"
#include "string.h"
#include "stddef.h"
#include "stdlib.h"
#include "assert.h"
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node* next;
}listnode,* linklist;

linklist list_create(void);
int list_insert_tail(linklist H,data_t value);
int list_show(linklist H);
linklist list_get(linklist H, int pos);//找到链表中某个结点，返回指向该结点的指针
linklist list_insert(linklist H, data_t data, int pos);//链表中任意位置插入
int list_delete(linklist H, int pos);