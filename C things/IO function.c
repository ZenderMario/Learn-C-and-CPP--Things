#include <stdio.h>

int main()
{

    /////////////////////////////////////////////////

    //perror发送错误消息
    //perror(const char * m)
    
    //exit()	--> <stdlib.h>
    //三种预定义参数
    //EXIT_SUCCESS
    //EXIT_FAILURE
    //noreturn -->不再返回main()直接退出
    

    /////////////////////////////////////////////////
    
    //流的概念,把输入输出看成是字节流从一个设备到另一个设备
    //绝大部分是缓冲流
    //先写到缓冲区再一起刷新发送
    //FILE 被设置成一个结构(流)
    //记载当前文件位置指示器,错误和文件结尾指示器,缓冲区开始
    //所有的stdio.h使用相同的缓冲区,所以从上一次读取完的位置继续

    //常用printf scanf
    //牢记转换符和修饰符
    //如*在printf可以延迟制定参数, *scanf()可以跳过某些项
    //scnaf()返回值为输出项数
    //
    //getchar() putchar()
    //gets()(禁用), puts()(后加换行)
    
    //文件IO
    //
    //声明FILE *指针指向文件
    //FILE * fopen(const char * fname,const char * fmt) 用fmt指示模式打开文件
    //fclose(FILE *)
    //
    //r 只读 没有则返回NULL
    //w 只写 会擦除文件 
    //a 追加 会擦除文件
    //读写条件下会创建两个缓冲区
    //即打开一个流
    //
    //
    //r+ 更新模式 可以读写
    //w+ 更新模式 会擦除
    //a+ 更新模式 会擦除,从尾添加
    //
    //上面加b 如 rb --> 二进制模式
    //
    //
    //
    //区分模式是为了不同条件下读取文件保证一致
    //因为文本模式可能会做一些转换(\r\n -> \n)
    //所以尽量配对使用读写函数
    //
    //
    //
    //int getc(FILE *)
    //	  putc(int ch, FILE *)
    //
    //fprintf(FILE *, const char * fmt, ...)
    //fscanf( FILE *, const char * fmt, ...)
    //
    //fgets( char * buf, FILE * , size_t len)
    //fputs(const char * bug, FILE * )
    //其中fgets()会读取换行符所以可以检查是否读取一行
    //
    //fseek(FILE *, long offset, mode)
    //第一个参数是函数指针, 第二个是偏移量(long), 第三个是偏移模式,确定起点
    //SEEK_CUR文件开始
    //SEEK_SET当前
    //SEEK_END文件末尾
    //一切正常则返回0 异常-1
    //long ftell(const FILE *)返回fp指向文件long值,
    
    //fseek()仍有缺陷,如long值限制
    //fgetpos(FILE *, fpos_t *)把当前fp位置放在fpos_t所指示变量
    //fsetpos(FILE *, const fpos_t *)设置位置
    

    //其它文件IO函数
    //int ungetc(int ch)将ch放回输入流中
    //int fflush( FILE *)    将fp指向文件缓冲区刷新,全部发送到文件中
    //int setvbuf( FILE *, char * buf, int mode, size_t size)
    //创建供IO使用的缓冲区,未文件执行操作前调用,fp指向文件,buf新缓冲区(NULL的话
    //则会新建), size是缓冲区大小, 
    //三种模式
    //_IOFBF全缓冲
    //_IOLBF行缓冲
    //_IONBF无缓冲
    
    //size_t fwrite(const void * restrict ptr, size_t size, size_t num, FILE * restirct fp)
    //二进制IO
    //ptr指示写入位置, size写入数据块大小, num数目,fp文件
    //fread()同
    //返回值是写入/读取项数
    //
    //feof(fp) 文件结尾返回非零否则0
    //ferror(fp) 文件读写错误返回非零否则0
    //void clearerr( FILE *)对FILE *指示文件重置错误标志
    
    //临时文件	FILE *tmpfile( void);创建一个临时文件,程序终止时自动删除
    //以wb+模式打开,可用于二进制和文本数据
    //char * tmpnam( char * name);指定临时文件名字
    //具体来说, tmpnam()可以生成TMP_MAX个不同变量名, 其中字符不超过L_tmpnam个
    
    //两个操作函数
    //int remove(const char * file)
    //int rename(const char * f1, const char * f2)
    //尽量在被调用前操作

    return 0;

}
