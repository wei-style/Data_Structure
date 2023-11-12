#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "assert.h"
#include "errno.h"
typedef int datatype;//队列中数据类型
#define N 64
typedef struct
{
	datatype data[N];//用数组作为队列的储存空间
	int front, rear;//指示队列头位置和尾位置，约定rear指示队尾元素的下一个位置，front指示队头元素，他们都是数组下标
}sequeue;//顺序队列类型定义

sequeue* queue_create();
int enqueue(sequeue* sq, datatype x);
datatype dequeue(sequeue* sq);
int queue_empty(sequeue* sq);
int queue_full(sequeue* sq);
int queue_clear(sequeue* sq);
sequeue* queue_free(sequeue* sq);


