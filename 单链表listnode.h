#include "stdio.h"
#include "stddef.h"
#include "stdlib.h"
#include "string.h"
typedef int data_t;
struct node
{
	data_t data;
	struct node* next;
};
typedef struct node  listnode;
typedef struct node* linklist;

linklist list_create(void);
int list_tail_insert(linklist H, data_t value);//head头节点
int list_show(linklist H);
