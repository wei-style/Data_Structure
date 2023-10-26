#define NULL ((void *)0)
#include "sqlist.h"
void test_insert();
int main()
{
	test_insert();
	return 0;
}


void test_insert()
{
	sqlink L;
	L = list_create();
	if (L == NULL)
		return ;

	int i = 0;
	for (i = 0; i < N / 2; i++)
	{
		insert(L, N / 2 - i - 1, 0);
	}
	list_free(L);

}
