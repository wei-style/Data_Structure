#include "sqlist.h"
#include "stdlib.h"//malloc函数
#include "stddef.h"//定义NULL
#include "string.h"//memset
#include "stdio.h"
sqlink list_create(void)//创建好后返回线性表的指针
{//申请内存，将数据放在堆上，这样可以让其他函数也能使用这些数据，除非自己释放掉内存
	sqlink L;//声明一个指针，用来接受malloc的起始地址
	L =(sqlink)malloc(sizeof(sqlist));//返回值是指向系统分配的空间的起始地址（void*），然后将他强制类型转换成sqlink类型的指针
	//如果创建失败
	if(L==NULL)
	{
		printf("list malloc failed\n");
		return L;//这里返回的是空
	}
	//创建成功后，对顺序表初始化，由于malloc申请的内存里面的值都是随机值，所以要手动初始化
	memset(L, 0, sizeof(sqlist));//第一个参数是起始地址，第二个参数是要填入的数，第三个参数是从起始地址开始往后的字节数，
	L->last = -1;//last表示有效数据的下标，由于下标不可能为-1，所以它表示数组中没有有效值
	//声明的是结构体指针，所以要用结构体指针来访问last
	return L;
}

//置空表
int list_clear(sqlink L)
{
	if (L == NULL)
		return -1;
	else
	{
		memset(L, 0, sizeof(sqlist));
		L->last = -1;
	}
	return 0;//一般的函数都是成功返回0，失败返回-1
}
/*
* list_empty:Is list empty?
* para L:list
* @ret 1--empty 0--not empty
*/
//判断线性表是否为空
int list_empty(sqlink L)
{
	if (L->last == -1)
		return 1;
	else
	return 0;
}
//求表长
int list_length(sqlink L)
{
	if (L->last == -1)
		return -1;
	else
	return L->last + 1;
}
//定位表中元素
int locate(sqlink L, data_t value)
{//将每个元素都与输入参数做对比
	int i = 0;
	for (i = 0; i <= L->last; i++)
	{
		if (L->data[i] == value)
			return i;//如果在表中找到这个数，就返回他的位置，如果有多个元素和他相同，返回第一个位置就行
	}
	return -1;
}
//插入
int insert(sqlink L, data_t value, int pos)
{	//检查线性表满没有
	if (L->last == N - 1)
	{
		printf("list is full\n");
		return -1;
	}
	//检查参数
	if (pos < 0 || pos>((L->last) + 1))
	{
		printf("pos is invalid\n");
		return -1;
	}
	//移动表的内容
	int i;
	for (i = L->last; i >= pos; i--)//从后往前移动
	{
		L->data[i + 1] = L->data[i];
	}
	//更新last
	L->data[pos] = value;
	(L->last)++;
	return 0;
}

int list_show(sqlink L)
{
	if (L == NULL)
	{
		printf("invalid list\n");
		return -1;
	}
	else if (L->last == -1)
	{
		printf("list is empty\n");
		return 0;
	}
	else
	{
		int i;
		for (i = 0; i <= L->last; i++)
			printf("%d ", L->data[i]);
	}
	puts("");//换行
	return 0;
}

int list_free(sqlink L)
{
	if (L == NULL)
	{
		return -1;
	}
	free(L);
	L = NULL;//释放内存后L仍然指向这块空间，令其等于NULL可以避免后续再对其进行访问
	printf("free list done\n");
	return 0;
}
//删除表中元素
int list_delete(sqlink L, int pos)
{	//判断是否是空表
	if(L->last==-1)
	{
		printf("list is empty\n");
		return -1;
	}
	//检查这个删除的位置是否满足表中的有效数据位
	if (pos<0 || pos>L->last)
	{
		printf("delete is invalid\n");
		return -1;
	}
	//删除元素后面的元素要向前移动
	int i;
	for(i=pos+1;i<=L->last;i++)
	{
		L->data[i-1] = L->data[i];//data[pos]的值自动的被覆盖
	}
	//更新表的成员数
	L->last--;
	return 0;
}
//求两个表的并集
int list_merge(sqlink L1, sqlink L2)
{
	int ret;
	//依次取L2中的元素
	int i = 0;
	while (i <= L2->last)
	{
		//检查取出的元素是否在L1中（循环进行）
		ret=list_locate(L1, L2->data[i]);//判断L2中的元素在不在L1中
		//如果不在L1中就将其插入L1（循环进行）
		if (ret == -1)//没找到,也就是两个表中有不同的元素
		{
			if(list_insert(L1, L2->data[i], L1->last+1)==-1)//将不同的元素插入L1的最后面，如果插入失败会返回-1，表示表已经满了 
			{
				printf("list %s is full\n", L1);
				return -1;
			}
		}
		i++;
	}
	return 0;
}
//删除线性表中的重复元素
int list_purge(sqlink L)
{
	int i = 1;
	if (L->last == 0)
		return 0;
	int j;
	//一次取元素i，i从1开始到last，判断
	while (i <= L->last)
	{
		j = i - 1;
		while(j>=0)
		{
			if (L->data[i] == L->data[j])
			{
				list_delete(L, i);
				break;
			}
			else
			{
				j--;
			}
		}
		if(j<0)
		{
			i++;
		}
	}
	return 0;
}
