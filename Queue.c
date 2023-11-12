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
	memset(sq->data, 0, sizeof(sq->data));//�ȼ���(*sq).data
	sq->front = 0;
	sq->rear = 0;
	return sq;

}
int enqueue(sequeue* sq, datatype x)
{	//�ж϶����Ƿ�����
	assert(sq);
	if ((sq->rear + 1) % N == sq->front)//��Nȡ���Ƿ�ֹ��������ʱ��������Խ�磬�����������Ĵ�С�����ȥ����ǰ�˶����ݽ��и��ǣ�ʵ��ѭ������
	{//β�±�����ټ�һȡ�����ͷ�±꣬˵��β��ͷ֮��ֻ����һ�����ݣ���ʶ��������
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
		return 1;//���˷���1
	}
	else return 0;//û������0
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
