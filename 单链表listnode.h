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
linklist list_get(linklist H, int pos);//找到某个位置的前一个结点
int list_insert(linklist H, data_t value, int pos);
linklist list_delete(linklist H,int pos);
linklist list_free(linklist H);
