#include <stdio.h>
#include <stdlib.h>

struct Book
{
	char ch[18];
	int a;
};


struct Bit
{
	char ch : 1;
	_Bool a : 2;

	unsigned int : 0;
	//强迫使下一个字段与下一个unsigned int对齐

	int   b : 2;

};
//C语言位字段
// 用于在位级别处理数据
//每个类型有各自对齐特性(自然字节
//如果一个字节上未填满, 且有更高对齐的字段, 将发生强制对齐
// 
// long double double float
// long int short char
// 位运算常常不可移植
// 用位字段访问内存
//
int main()
{

    /////////////////////////////////////////////////

    //C用malloc(calloc)和 free来管理动态内存分配
    //两者如执行正常都返回内存块地址，否则返回NULL
    //所以检查分配状态很有必要
    //calloc()把开辟内存块位都设置为0,但不一定具体变量为0
    //
    //第三个函数realloc(void * ptr, size_t new_size)
    //用于改变已经开辟内存块大小
    //增加在尾部，原有内存不变
    //减少在尾部，原有内存不变。如不能正常减少则开辟一个新内存块，复制原来内容并返回指针
    //原来指针也不能再使用
    //第一个参数是NULL则和malloc行为一致
    




	//----------------------------------------------------
	printf("%zu ", sizeof(struct Book));
	//c语言用结构标识符必须 struct X a;
	//C语言存储结构采用对齐(自然字节处理更快速)
	//4的整数(int大小
	//所以最大化利用内存先声明对齐严格的变量
	//如
	//struct 
	// {
	//		int a;
	//		char [18]; 
	// };
	// 输出为22
	//----------------------------------------------------


	//----------------------------------------------------
	//C语言伸缩数组
	//struct Book
	//{
	//	int a;
	//	char b[];
	//};
	//
	//struct Book * pb = (struct Book*)malloc(sizeof(struct Book) + sizeof(char) * 10);
	//
	//fgets(pb->b, 10, stdin);
	//printf("%s", pb->b);*/
	// 
	// 实际应用时应该用malloc分配内存
	// 
	//----------------------------------------------------

	printf("%zu", sizeof(struct Bit));

	return 0;
}

