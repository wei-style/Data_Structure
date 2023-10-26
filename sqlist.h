typedef int data_t;//typedef 后面跟以后类型，在编译时进行处理
#define N 128//define是宏操作，编译时直接展开不做处理
struct sqlist_t
{
	data_t data[N];
	int last;
};

typedef struct sqlist_t sqlist;//将struct sqlist_t定义为sqlist，这样sqlist就成了新的变量类型，可以用于定义参数，简化书写
//重定义之前如果要定义一个变量需要写为 struct sqlist_t a;在重定义后写为 sqlist a;简化书写
typedef struct sqlist_t* sqlink;
//重定义之前如果要定义一个变量需要写为 struct sqlist_t* p;在重定义后写为 sqlink p;简化书写
/*
他们可以简化为
typedef struct{
	data_t data[N];
	int last;
};sqlist,*sqlink
*/

//定义线性表的创建
sqlink list_create();//创建好后返回线性表的指针
//置空表
int list_clear(sqlink L);
//判断线性表是否为空
int list_empty(sqlink L);
//求表长
int list_length(sqlink L);
//定位表中元素
int locate(sqlink L,data_t value);
//插入
int insert(sqlink L, data_t value, int pos);
//打印线性表(遍历）
int list_show(sqlink L);
//销毁线性表
int list_free(sqlink L);


