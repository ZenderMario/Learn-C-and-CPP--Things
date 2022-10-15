#include <stdio.h>
#include <stdarg.h>

double average(int n, ...)
{

	//C语言定义了一系列类型和预处理宏实现可变参数
	//首先在参数列表里用...表示可变参数
	//用va_list类型声明变量
	// 用va_start( va_list, a)访问可变参数, 其中第一个参数是va_list类型变量, 第二个是可变参数前一个参数
	// 用va_arg( va_list, double)获取可变参数, 其中第一个参数是va_list类型变量, 第二个是欲获取可变参数的类型(一些函数可能用前面参数确定后面获取类型 --printf)
	// 用va_arg( va_list)处理使用后的可变参数, 结束
	// 
	//

	va_list var_arg;
	va_start(var_arg, n);

	double aver = 0.;
	for (int i = 0; i < n; i++)
		aver += va_arg(var_arg, double);

	return aver / n;

}

int main4()
{
	printf("%lf", average(3, 10., 20., 35.));



	return 0;
}