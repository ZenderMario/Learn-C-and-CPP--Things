#include <stdio.h>

void to_binary(int a)
{
	if( a >= 2)
		to_binary(a / 2);
	printf("%d", a % 2);
}

void print_strnum(int a)
{


	if (a >= 10)
		print_strnum(a / 10);
	printf("%d", a % 10);
}

int main3()
{

	//�����������ֵݹ����ڴ���������
	//
	//��������λ�ó����෨,�����������(�����λ)��ʼ��ӡ
	//��ӡ���������λ���γ���

	//�ݹ�Ҳ�ɷ�Ϊ�׵ݹ��β�ݹ�
	// β�ݹ����ѭ��ʵ��(��ִ�д����������)
	//����ʹ��


	return 0;
}