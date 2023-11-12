#include "Queue.h"

sequeue* queue_create()
{
	sequeue* sq;
	sq = (sequeue*)malloc(sizeof(sequeue));
	if (sq == NULL)
	{
		printf("ERROR:%s\n", strerror(errno));
		return NULL;
	}
	memset(sq->data, 0, sizeof(sq->data));//等价于(*sq).data
	sq->front = 0;
	sq->rear = 0;
	return sq;

}
int enqueue(sequeue* sq, datatype x)
{	//判断队列是否是满
	assert(sq);
	if ((sq->rear + 1) % N == sq->front)//对N取余是防止存入数据时发生数组越界，如果超过数组的大小，则会去数组前端对数据进行覆盖，实现循环队列
	{//尾下标如果再加一取余等于头下标，说明尾和头之间只空了一个数据，标识队列已满
		printf("sequeue is full\n");
		return -1;
	}
	sq->data[sq->rear] = x;
	sq->rear = (sq->rear + 1) % N;
	return 0;
}
datatype dequeue(sequeue* sq)
{
	assert(sq);
	datatype ret;
	ret = sq->data[sq->front];
	sq->front = (sq->front + 1) % N;

	return ret;
}
int queue_empty(sequeue* sq)
{
	assert(sq);
	return sq->front == sq->rear ? 1 : 0;
}
int queue_full(sequeue* sq)
{
	assert(sq);
	if ((sq->rear + 1) % N == sq->front)
	{
		return 1;//满了返回1
	}
	else return 0;//没满返回0
}
int queue_clear(sequeue* sq)
{
	assert(sq);
	sq->front = sq->rear = 0;
	return 0;
}
sequeue* queue_free(sequeue* sq)
{
	assert(sq);
	free(sq);
	sq = NULL;
	return NULL;
}
