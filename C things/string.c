#include <stdio.h>
#include <string.h>

int main()
{

    //////////////////////////////////////////////////////////////////////
    //if( strlen("hel") - strlen("column") >= 0)
    //	putchar('\a');    //永远不要这样写
    //两个unsigned int的值永远为unsigned int
    //所以结果恒为0
    
    //////////////////////////////////////////////////////////////////////
   
    //字符串都以空字符结尾，所以程序员应保证内存不会出错
    
    //常见字符串函数
    //
    //char * strcpy( char * dest, const char * source)
    //char * strncpy( char * dest, const char * source, size_t len)
    //如果后者额小于前者则多出用NULL填充
    //如果后者大于len则仅复制len个字符，所以不一定是字符串
    //
    //char * strcat( char * dest, const char * source)
    //char * strncat( char * dest, const char * source, size_t len)
    //最多复制n个字符，最后加上NULL
    //不会处理内存溢出，strncat()也不一定保证安全
    //
    //
    //int strcmp( const char * s1, const char * s2)
    //int strncmp( const char * s1, const char * s2, size_t len)
    //
    //前两个函数返回第一个指针，尽量都用带限制的版本，前者容易出错
    //strcmp()返回两个字符串是否想等， 字符码在前则返回负数
    //printf("%d", strncmp("hello", "loose", 4)); --> -4 in Linux Ubuntu

    
    //////////////////////////////////////////////////////////////////////

    
    //字符串查找函数
    //
    //char * strchr( const char * str, int ch)
    //char * strrchr( const char * str, int ch) -->反向查找
    //
    //
    //char * strpbrk( const char * str, const char * group)
    //查找后者任一字符在str指向字符串首次出现位置（类似C++中 string::find_first_of()
    //
    //char * strstr(const char * s1, const char * s2)
    //返回后者（子串）在前者首次出现位置， 否则返回NULL
    //
    //
    //size_t strspn(const char * s, const char * group)
    //返回后者所有字符在前者开头连续字符中出现的次数
    //printf("%zd", strspn( "25142, 330, Smith, J , 239-4123", "0123456789")); --> 5
    //而strcspn()则对后者任一在前者出现最早字符前面前者所有的次数计数
    //
    //

    //printf("%zd", strcspn("hello world!", "llo"));

    //////////////////////////////////////////////////////////////////////
    
    //字符串中常常包含几个单独部分，彼此分隔。有时为了处理可以将其抽取出来
    //
    //char * strtok(const char * s1, const char *group)
    //将group指定的分隔符定位到s1所在标记，以指针返回
    //若第一个参数不为NULL则查找参数中第一个标记并保存将标记处位置设为NULL
    //第一个参数为NULL时从保存标记开始继续查找并保存
    //同时会改变原字符串，所以应通过副本处理
    //strtok()保存静态局部变量，所以不能同时处理两个字符串

    //char ch[] = "hello world!\nI am the computer of this  computer!\nnice to meet to you";

    //char * token;
    //for( token = strtok(ch, "\n"); token != NULL; token = strtok(NULL, "\n"))
    //{	
    //	fputs(token, stdout);
    //	putchar(' ');
    //}
    //puts(ch);



    //////////////////////////////////////////////////////////////////////
    
    //字符操作
    //都使用一个整形参数，返回整形值表示真或假
    //
    //iscntrl()控制字符
    //isspace()
    //isdigit()
    //isxdigit
    //islower()
    //isupper()
    //isalpha()
    //isalnum()字符数字
    //ispunct()标点符号
    //isgraph()任何图形字符
    //isprint()可打印字符

    //toupper()
    //tolower()
    
    //////////////////////////////////////////////////////////////////////
    
    //内存操作
    //由于字符串由NULL结尾，所以上面字符串处理不能处理内部含NULL的情况
    //C语言和C++一样可以把任何类型指针赋给void * 但C++需要强制类型转换逆向
    //
    //
    //void * memcpy( void * dst, const void * src, size_t length);
    //void * memmove( void * dst, const void * src, size_t length);
    //viud * memcmp( const void * dst, const void * src, size_t length);
    //void * memchr( const void * dst, int ch, size_t length);
    //void * ememset( void * a, int ch, size_t length);
    //
    //每一个都包含要处理的字节数,但和前面函数不同，不会遇到NULL就停止
    //
    //
    //切记处理的是字节数而不是项数（void *不能在运算
    //memmove()和memcpy()差不多，但前者先创建一个临时变量再复制，可用于自身复制（如后面字符串前移）
    //memset()把a起始位置开始length个字节替换为ch
    


    //////////////////////////////////////////////////////////////////////







    //////////////////////////////////////////////////////////////////////
    return 0;

}

