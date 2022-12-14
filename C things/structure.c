#include <stdio.h>

int main()
{

    /////////////////////////////////////////////////

    //和C++不同C语言采用不同的方式表示名称
    //C++采用名称空间，即类和结构、函数放在一起，而C是全部标签放在一起，结构联合    	
    //放一块，而C++可以通过名称空间区分名称
    //所以C结构里面声明的结构可以直接在外部用
    //而C++需加上作用域限定符

    
    /////////////////////////////////////////////////

    //C语言结构内存分配较特殊，会对齐处理，使之处理更迅速
    //禁止编译器跳过一些字节满足对齐要求
    //所有结构起始位置必须是结构中边界要求最严格数据类型要求的位置
    //如
    struct Align
    {
	char a;
	int b;
	char c;
    };
    printf("%zd", sizeof(struct Align));
    //结果Align占12个字节
    //所以要求设计时考虑对其减少损失
    
    /////////////////////////////////////////////////
   

    //C语言结构也可以实现C++类似的友元形式
    //但访问控制不太行
    

    /////////////////////////////////////////////////
    
    //C语言位字段
    //位段声明需用(或升级为)int, signed int, 或unsigned int
    //一般用unsigned int 存储



     
    /////////////////////////////////////////////////
}
