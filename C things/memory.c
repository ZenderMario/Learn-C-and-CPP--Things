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
	//ǿ��ʹ��һ���ֶ�����һ��unsigned int����

	int   b : 2;

};
//C����λ�ֶ�
// ������λ����������
//ÿ�������и��Զ�������(��Ȼ�ֽ�
//���һ���ֽ���δ����, ���и��߶�����ֶ�, ������ǿ�ƶ���
// 
// long double double float
// long int short char
// λ���㳣��������ֲ
// ��λ�ֶη����ڴ�
//

int main2()
{
	
	//----------------------------------------------------
	printf("%zu ", sizeof(struct Book));
	//c�����ýṹ��ʶ������ struct X a;
	//C���Դ洢�ṹ���ö���(��Ȼ�ֽڴ��������)
	//4������(int��С
	//������������ڴ������������ϸ�ı���
	//��
	//struct 
	// {
	//		int a;
	//		char [18]; 
	// };
	// ���Ϊ22
	//----------------------------------------------------


	//----------------------------------------------------
	//C������������
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
	// ʵ��Ӧ��ʱӦ����malloc�����ڴ�
	// 
	//----------------------------------------------------

	printf("%zu", sizeof(struct Bit));

	return 0;
}