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
linklist list_get(linklist H, int pos);//�ҵ�������ĳ����㣬����ָ��ý���ָ��
linklist list_insert(linklist H, data_t data, int pos);//����������λ�ò���
int list_delete(linklist H, int pos);