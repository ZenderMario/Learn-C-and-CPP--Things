#include <stdio.h>

int main()
{
	//指向const指针和本身为const指针

	//C语言解释下标
	char ch[10] = "hello";
	//2[ch]合法, 被解释成 *( 2 + (ch) )
	//putchar(1[ch]); --> e
	//但影响阅读
	


	//C语言数组名和指针可以转化, 但也有不同
	//1 : const区别
	//2 : 数组名使用会比指针使用效率低一些
	//
	//for( ...; ... ; i++)
	//	  ch[i]
	//
	//for( ...; ...; ptr++)
	//	  *ptr ...
	// 
	// 上述指针运算在编译时会计算偏移大小
	// 前者每次都会计算 i * sizeof(char)
	// 后者只计算 1 * sizeof (char) (ptr++)
	// 尽量减少指针运算
	// 可采取编译时确定的量提高运行速率
	// 如 ptr < &ch[con] -- con为常量 两者均为已确定量
	//

	//C语言和C++处理指针也有不同
	//C语言允许将const指针赋给非const,前提程序员保证正确性,  而C++则直接报错

	return 0;
}