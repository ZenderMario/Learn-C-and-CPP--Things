#include <stdio.h>
#include <stdarg.h>

double average(int n, ...)
{

	//C���Զ�����һϵ�����ͺ�Ԥ�����ʵ�ֿɱ����
	//�����ڲ����б�����...��ʾ�ɱ����
	//��va_list������������
	// ��va_start( va_list, a)���ʿɱ����, ���е�һ��������va_list���ͱ���, �ڶ����ǿɱ����ǰһ������
	// ��va_arg( va_list, double)��ȡ�ɱ����, ���е�һ��������va_list���ͱ���, �ڶ���������ȡ�ɱ����������(һЩ����������ǰ�����ȷ�������ȡ���� --printf)
	// ��va_arg( va_list)����ʹ�ú�Ŀɱ����, ����
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