# **IO**

C++ IO 是一门强大的工具, 几乎每个程序都使用了输入和输出. 同时 C++为了实现这些功能, 用了很多高级特性, 如类, 派生继承, 模板, 重载和虚函数等. 但通过一些标准定义的类, 可以快速学习 C++输入输出功能.

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [**IO**](#io)
  - [**1 C++输入输出**](#1-c输入输出)
    - [**1.1 C++ IO 框架**](#11-c-io-框架)
    - [**1.2 C++ iostream 头文件**](#12-c-iostream-头文件)
    - [**1.3 重定向**](#13-重定向)
  - [**2 cout 输出**](#2-cout-输出)
    - [**2.1 << 运算符**](#21-运算符)
    - [**2.2 拼接输出**](#22-拼接输出)
    - [**2.3 cout 格式化输出**](#23-cout-格式化输出)
      - [**2.3.1 控制计数系统**](#231-控制计数系统)
      - [**2.3.2 调整字段宽度**](#232-调整字段宽度)
      - [**2.3.3 填充字符**](#233-填充字符)
      - [**2.3.4 浮点数打印**](#234-浮点数打印)
      - [**2.3.5 setf()**](#235-setf)
      - [**2.3.6 标准控制符**](#236-标准控制符)
  - [**3 cin 输入**](#3-cin-输入)
    - [**3.1 cin 检查输入**](#31-cin-检查输入)
    - [**3.2 cin 流状态**](#32-cin-流状态)
      - [**3.2.1 设置状态**](#321-设置状态)
      - [**3.2.2 I/O和异常**](#322-io和异常)
      - [**3.2.3 流状态判断**](#323-流状态判断)
    - [**3.3 其它istream类方法**](#33-其它istream类方法)
      - [**3.3.1 get()**](#331-get)
      - [**3.3.2 get(), getline(), ignore()**](#332-get-getline-ignore)
      - [**3.3.3 意外字符输入**](#333-意外字符输入)
      - [**3.3.4 其它istream函数**](#334-其它istream函数)
  - [**4 文件读写**](#4-文件读写)
      - [**4.1 流状态检查**](#41-流状态检查)
    - [**4.2 打开多个文件**](#42-打开多个文件)
    - [**4.3 打开二进制文件**](#43-打开二进制文件)
    - [**4.4 文件随机存取**](#44-文件随机存取)
  - [**5 内核格式化**](#5-内核格式化)

<!-- /code_chunk_output -->

## **1 C++输入输出**

<br/>

&emsp;&emsp;比较其他语言, 如 BASIC 等, 将输入输出语句看成语言的组成部分, 即关键字. 而 C++仅使用了标准类库( iostream 和 fstream)实现输入输出功能. ~~只要想, 可以使用 cout 作为变量名称 .~~实际上输入输出类是一组模板, 如下面 ostream, 在名称空间 std 中, 提供了对宽字符的支持(wchar_t). : basic_istream< charT, traits&lt;charT> >. 后一个模板参数提供了诸如比较针对不同类型字符的操作.

### **1.1 C++ IO 框架**

&emsp;&emsp;由于 C++要想程序输出字符, 和 C 类似, C++将输入输出看成更宏观上的字节流, 即组成数据的字节从一个设备流向另一个设备. 在此过程, C++类( cout) 将数据解释成字符形式的字节发送到程序, 即字节通过类流向程序. 所以 C++处理输入将类和文件( 程序)以及程序( 文件)关联起来.

&emsp;&emsp;在 C++程序最终显示字符前, 流中的字节先被送到缓冲区中. 缓冲区是作为中介的临时存储区, 内存通常较大. 因为 C++程序可能经常性进行输入输出操作, 因此集中性发送字节比较高效. 一般缓冲区有完全缓冲( 缓冲区满发送字节流)和行缓冲( 遇到换行符刷新字节流)对缓冲区进行刷新. 也有一些特殊情况, 如输入前刷新缓冲区 和 无缓冲缓冲区.

### **1.2 C++ iostream 头文件**

&emsp;&emsp;C++对流进行管理是通过标准类库中定义的一组类, 简化了对流和缓冲区的操作. 如:

|   类名    |                      说明                      |
| :-------: | :--------------------------------------------: |
| streambuf |      为缓冲区提供内存, 提供一些缓冲区方法      |
| ios_base  |                  流的一般特征                  |
|    ios    | 基于 ios_base, 包含了一个指向 streambuf 的指针 |
|  ostream  |               ios 派生, 提供输出               |
|  istream  |               ios 派生, 提供输入               |
| iostream  |      派生 ostream, istream, 输入输出均有       |

iostream 定义了 8 个流对象, 均在 std 空间中.

- cin 对应标准输入流, 通常关联到标准输入( 键盘), 但可以通过重定向改变, 下同. 有 wcin 对象.
- cout 对应标准输出流, 通常关联到标准输出( 屏幕), 但可以通过重定向改变. 有 wcout 对象.
- cerr 关联标准错误流, 通常关联标准输出. 但没有被缓冲, 即可以直显示. wcerr.
- clog 关联标准错误流, 但被缓冲. 有 wclog.

以上定义对象均说明了对象和流关联--输出以为字节先被发送到对象管理的缓冲区再被显示.

### **1.3 重定向**

<br/>

重定向不是 C++提供, 而是由操作系统操控的命令, 可以将程序的标准输入( 标准输出)关联到文件上.

```
$ 1.txt > count.exe

```

即意味将 1.txt 重定向为 count 程序的标准输入( 从文件中读取数据).但不够灵活, 可用下面 C++文件流操作类 fstream 控制文件输入输出.

## **2 cout 输出**

<br/>

&emsp;&emsp;如前所提 C++将数据先解释成字符字节流再向缓冲区发送, 所以 ostream 类任务之一就是将数据内部表示的二进制转化为同义字符流. 可通过重载等功能实现.

### **2.1 << 运算符**

<br/>

&emsp;&emsp;ostream 对基本类型进行重载, 可以直接显示这些数据. 所以对于基本类型数据, ostream 类将找到合适的函数重载调用实现. 对于 char \*等类型也是如此.

```C++

    int i = 10;
    int * a = &i;
    cout << a;

```

会直接显示 i 的地址. 而

```C++

    char str[] = "hello world!";
    cout << str;

```

会显示 str 指向的字符串, 而不是其地址( 数组名解释为地址).

### **2.2 拼接输出**

<br/>

&emsp;&emsp;ostream 通过引用和返回值实现拼接调用 cout 及其相关成员函数.

```C++

cout << a << b;
//-->   (cout << a) << b;

```

一些 ostream 成员和方法.

- put() 显示字符, 已被模板化可适用于 wchar_t. 可拼接.
- write() 显示字符串, 同样模板化. 可拼接. 第一个参数是字符串地址, 第二个是显示前 n 个字符.
- fflush 控制符, 可直接用 cout 输出, 类似 endl, 用于刷新缓冲区. 实际上是函数, 但 cout 对其重载.

### **2.3 cout 格式化输出**

<br/>

默认情况下有以下情况格式化输出:

- char, 若为可打印字符, 则被容纳为一个字符的字段中
- 数值类型, 十进制显示在包含正负号和数字字符字段中
- 字符串, 被显示在字符串宽度字段中

对于浮点数稍有不同:

- 老式: 浮点类型显示为带 6 位小数, 尾端 0 不显示. (显示位数和储存精度没有关系. ) 数字以定点表示还是科学计数法取决于其值. 字段宽度正好容纳数字和负号.
- 新式: 浮点类型显示为带 6 位小数, 尾端 0 不显示. (显示位数和储存精度没有关系. ) 数字以定点表示还是科学计数法取决于其值. 具体来说, 当指数大于 6 或 小于-5 将使用科学计数法. 字段宽度正好容纳数字和负号. 默认行为对应%g 说明符 C 库函数 printf()

因为字段宽度等于其长度, 所以显示时应手动加上间隔符.

#### **2.3.1 控制计数系统**

<br/>

&emsp;&emsp;ostream 从 ios 类派生而来, 后者又从 ios_base 派生. 后者有一些成员中位描述了计数系统和字段宽度, 可以通过控制符( manipulator)控制 cout 具体输出显示格式. 通过 ios_base 成员函数, 可以控制字段宽度和成员函数, 因此可以用于派生类 ostream.

```C++

    //上面用到了ios_base中控制符 fflush
    //可以这样用
    cout << fflush;
    //或
    fflush( cout);
    //实际上是函数, 但上一种形式更加清楚

    //ios_base中计数系统控制符 dec, hex, oct

    cout << dec; //输出格式设置为10进制



```

#### **2.3.2 调整字段宽度**

<br/>

```C++

    //原型
    int width();
    int width( int i);

    //第一种形式返回当前字段格式
    //第二种设置字段位i, 并返回以前字段宽度
    //而且wid()只影响一个元素, 然后回复默认


    cout.width( 10);
    cout << 10;
    //结果将右对齐显示        10
    //用空格填充空字段以及右对齐均是默认设置, 可以更改

```

#### **2.3.3 填充字符**

```C++

    cout.fill( '*');
    //将填充字符设为 '*'
    //并且一直有效

```

#### **2.3.4 浮点数打印**

<br/>

```C++

    //默认C++输出小数不带0输出并且

    cout << 15.0;
    //输出15

    //可以强制输出小数点

    cout.setf( ios_base::showpoint);
    cout.precision( 6);
    //上面设置强制输出小数点 showpoint是ios_base定义的静态常量, 需加作用域访问
    //设置输出精度为6, 其中包含整数部分

```

#### **2.3.5 setf()**

<br/>

&emsp;&emsp;成员函数 setf()控制了小数点显示时其它格式选项. ios_base 类有一个保护的数据成员, 其中各位( 标记)控制着格式输出. 打开一个标记称为设置标记( 可通过位运算实现). 上面的 hex, dec, oct 就是标记. setf()提供了函数处理位运算的方式.
&emsp;&emsp;setf()有两个原型:

```C++

    fmtflags setf( fmtflags);
    //fmtflags是bitmask类型的typedef, 用于存储格式标记
    //参数是个标记, 用于指明设置哪一位
    //因为设置位较麻烦, 所以引入一些代表位值的常量

```

|      位值常量       |         含义         |
| :-----------------: | :------------------: |
| ios_base::boolalpha |    输出 bool 符号    |
| ios_base::showbase  |     输出基数前缀     |
| ios_base::showpoint |      输出小数点      |
| ios_base::uppercase | 对于十六进制大写前缀 |
|  ios_base::showpos  |       正数加+        |

**bitmask 类型是一种用于存储各个位值的类型, 可以是整形, 枚举, 也可以是 STL bitset 容器. 每一位都是可以访问的.**

这些常量都是 ios_base 类定义的静态常量, 必须加上作用域解析运算符. 修改一直有效知道覆盖为止.

下面是 setf()第二种原型:

```C++

    fmtflags setf( fmtflags, fmtflags);
    //这种形式用于设置多位格式选项
    //第一个参数和第一种形式一样, 包含了所需设置的fmtflags值. 第二个参数指出要清除第一个参数哪些位.
    //因为如果想设置某些位, 需要关闭另一个位然后再打开这些位
    //即第一个参数用于指出打开的位, 第二个参数是要清除其它的位

    setf( ios_base::hex, ios_base::basefield);
    //basefield是一个位组合, 表示用哪个基数输出
    //相当于cout << hex;


```

| 第二参数              | 第一参数             | 含义                       |
| --------------------- | -------------------- | -------------------------- |
| ios_base::basefield   | ios_base::dec        | 基数 10                    |
|                       | ios_base::oct        | 基数 8                     |
|                       | ios_base::hex        | 基数 16                    |
| ios_base::floatfield  | ios_base::fixed      | 定点计数                   |
|                       | ios_base::scientific | 科学计数                   |
| ios_base::adjustfield | ios_base::left       | 左对齐                     |
|                       | ios_base::right      | 右对齐                     |
|                       | ios_base::internal   | 符号或前缀左对齐, 值右对齐 |

```C++

    //定点表示类似于C中%f说明符
    cout.setf( ios_base::fixed, ios_base::floatfield);
    //类似于cout.setf( ios_base::showpoint)
    //C++显示位数指的是小数位数

    //如果向左对齐
    ios_base::fmtflags old = cout.setf( ios_base::left, ios_base::adjustfield);

    //恢复以前设置
    cout.setf( old, ios_base::adjustfield);


    //调用setf()的影响可以用unsetf()消除

    cout.setf( ios_base::boolalpha);
    cout.unsetf( ios_base::bollalpha);
    //重新设其位为0

    //对于浮点数显示, 没有专门标记用于指示方式
    //C++在两位均设置或均无设置采用默认方式, 否则采取标记方式
    //一种方法采取默认方式
    cout.setf( 0, ios_base::floatfield);
    //第二个参数清空位, 而第一个不设置任何位

    //或者是
    cout.unsetf( ios_base::floatfield);

```

#### **2.3.6 标准控制符**

因为 setf()需要频繁设置位, 所以控制符更友好和简洁. 下面是一些标准控制符:

- boolalpha
- noboolalpha
- showbase
- noshowbase
- showpoint
- noshowpoint
- showpos
- noshowpos
- uppercase
- nouppercase
- internal
- left
- right
- dec
- hex
- oct
- fixed
- scientific

**此外对于上面width()等函数, ostream类也有一系列控制符. 如**
```C++

    cout << 3.0 << setw(2) << setprecision(2);

```

## **3 cin 输入**

<br/>

cin 将标准输入看成字节流, 同样也对基本类型进行重载. 输入时将一些字节字符转换为相应的数据. 这些运算符函数称为格式化输入函数, 因为可以将输入数据转换为目标指定格式. 如:

```C++
istream & operator>>( int &);
```

cin 也对 char\* 等类型重载了运算符, 但要保证相应地址可以存放字符串.

此外, cin 还支持 cout 基数控制符, 负责将相应基数数字转化成十进制数据.

```C++
cin >> hex;
```

### **3.1 cin 检查输入**

<br/>

不同版本运算符函数检查输入相似, 均跳过空白, 直到遇到非空白字符, 对 char 等类型也是如此. ( scanf()不同), 然后读取相应类型的数据. cin 对应的标准输入流是缓冲的.

### **3.2 cin 流状态**

<br/>

cin 和 cout 均有一个描述流状态的数据成员( 从 ios_base 处继承). 流状态( 被定义为 iostate 类型, 也是一种 bitmask 类型)有三个 ios_base 元素组成: eofbit, badbit 或 failbit, 每种元素都是一位. 当 cin 到达文件尾时, 它将设置 eofbit; 当 cin 未能读取到与其字符, 将设置 failbit. I/O 失败也可能将 failbit 设置为 1. 在一些无法判断的失败破坏流时, badbit 元素将被设置. 当全部 3 个状态位都设置为 0 时, 说明一切顺利. 程序可以检查流状态来决定下一步措施.

| 成员                    | 说明                                                                                                      |
| ----------------------- | --------------------------------------------------------------------------------------------------------- |
| eofbit                  | 到达文件尾, 可用 eof()检测                                                                                |
| badbit                  | 流被破坏, 如文件读取错误, 可用 bad()检测                                                                  |
| failbit                 | 未能读取合适字符或输出未能写入预期字符, 可用 fail()检测( 在eofbit 和 failbit被设置时均返回true)           |
| goodbit                 | 流正常, 可用 good()检测                                                                                   |
| rdstate()               | 返回流状态                                                                                                |
| exceptions()            | 返回一个位掩码, 用于指示哪些标记导致异常                                                                  |
| exceptions( iostate ex) | 设置哪些状态将导致 clear()引发异常. 如果 eofbit 设置, 则 clear()调用则引发异常                            |
| clear(iostate s)        | 将流状态设置为s; s默认值为0( goodbit), 如果( restate() & exceptions()) != 0, 则引发异常basic_ios::failure |
| setstate( iostate s)    | 调用clear( restate() \| s). 这将设置s中设置的位的流状态位, 其他流状态位不变.                              |


#### **3.2.1 设置状态**

<br/>

&emsp;&emsp;上表中两种方法clear()和setstate()都可以重置状态, 但行为不同. clear()将状态设置位它的参数, 所以clear()调用默认参数将清空所有位, 即good()为真.  同样clear(eofbit)将设置eofbit, 其它位将被清除.
&emsp;&emsp;而setstate()方法只影响参数中已经设置的位, 即setstate( eofbit)将设置eofbit, 同时其它位不变. 

对于程序来说, 怎样设置流状态取决于所执行的任务, 输入不匹配可以及时调整.

#### **3.2.2 I/O和异常**

<br/>

上表还有一个函数exceptions()及其重载形式. 其返回一个位字段, 用于指示哪些位会导致异常抛出, 通常默认值是0, 即不会引发异常. 但重载版本可以指定异常位. 在cin使用clear()或setstate()修改流状态后, 会执行exceptions()通过返回值比较是否异常位被设置从而引发异常. cin将抛出一个ios_base::failure类型的异常( 有std::exception类继承而来).

```C++
    cin.exceptions( ios_base::eofbit | ios_base::failbit);
    //将eofbit 和 failbit 设置成引发异常的位

    cin.clear( ios_base::eofbit);
    //将引发异常

```

#### **3.2.3 流状态判断**

<br/>

只有在流状态良好( 所有位均为0)情况下, cin作为测试条件才返回true.

```C++
while( cin>> input)
{
    ...
}

```

&emsp;&emsp;设置流状态后将导致流对后面所有输入都关闭, 直到位被清除. 所以流在被设置位后仍希望能够读取输入, 就需要先清空位, ***然后对缓冲区中剩余非法输入清理***, (cin.get()).

### **3.3 其它istream类方法**

<br/>

#### **3.3.1 get()**

<br/>

&emsp;&emsp;cin两个成员函数get() 和 getline() 读取单个和整行. 因为其不能转换输入, 只是读取字符, 因此被成为非格式化输入函数.

```C++

    //get()有两个版本, 第一个版本将char变量作为参数, 将读取字符赋给它, 包括空白
    char ch;
    cin.get( ch);

    //第二个版本将读取字符作为返回值返回
    //类似于getchar()
    ch = cin.get();

    //相对于cin >> ch, 前者能够读取空白, 而cin则直接略过
    while( ch != '\n')
    {
        cin >> ch;
        ...
    }
    //程序并不会停止!!!

    //如果cin.get(char & ch)读到了EOF则不会赋给参数值, 且会调用 setstate( failbit),
    if( cin >> ch)
    {
        ...
    }
    //直接判定位false

    //但cin.get()返回形式会返回EOF, 符号常量
```


#### **3.3.2 get(), getline(), ignore()**

<br/>

&emsp;&emsp;get()读取字符串版本和getline()特征标类似:

```C++

    istream & get( char * ,int);
    istream & getline( char * ,int);

    istream & get( char * ,int, char);
    istream & getline( char * ,int, char);

    //第一种版本将读取字符串放入char *, 最多读取n - 1个字符, 并在最后放上'\0'
    //第二种版本还存储了一个表示结尾的字符, 
    //两种版本都读取最大字符后停止, 结束符不同

    //get()和getline()差异在于, 前者将换行符仍存于输入流中, 而后者读取并丢弃

```

#### **3.3.3 意外字符输入**

<br/>

&emsp;&emsp;同>>读取会改变输入流状态, get和getline也会影响. 这两个函数在遇到文件尾时设置eofbit, 流被破坏时设置badbit, 另外两种情况是五输入以及输入到达最大字符数.

&emsp;&emsp;上述方法在不能抽取字符时将存储空字符, 并通过setstate()设置failbit. 一种情况是遇到EOF, 对get()可能是输入一个空行.

```C++

    char temp[80];
    while( cin.get( temp, 80)) //在读取空行后停止
    {
        ...
    }
    //而getline()却不会设置failbit, 因为其将读取换行符, 所以getline() 还需检测首字符是否为空

    //另一种情况是读取最大字符
    char str[30];
    while( cin.getline( str, 30))
    {
        ...
    }
    //getline()将在读取文件尾, 遇到换行符, 最大字符数时停止
    //没有读取字符时设置failbit
    //但超过最大字符数时将设置failbit


```

#### **3.3.4 其它istream函数**

<br/>

&emsp;&emsp;istream还提供了一些其它函数, 如read, peek(), gcount(), 和putback().

read()函数通常和write()函数合用, 经常用于文件读写. 可以读取指定数目的字节, 并将其存储在指定位置中. 例如: 

```C++

    char str[30];
    cin.read( str, 30);
```
将从标准输入中读取30个字节放入str数组. 和getline() 与get()不同, 并不在末尾加上空字符, 因此对于标准输入可能不太好用. 该方法返回istream &, 可以拼接.

peak()函数返回输入中下一个字符, 但并不抽取, 即能够仅查看.

```C++

    char str[30];

    while( cin.peek() != '\n' ) //避免空行
        cin.get( str, 30);
    //之后需要处理换行符

```
gcount()返回最后一次以非格式化方式读取字符数.

putback()函数将第一个字符插入到输入字符串中, 被插入的字符将是下一次读取的字符. 和peek()等函数结合可以很灵活判断输入.

## **4 文件读写**

<br/>

~~终于到文件~~

&emsp;&emsp;因为程序使用栈内存, 并不能做到保存数据, 所以应用文件I/O写入到计算机系统文件. 文件本身时操作系统管理的一系列字节, 跟踪其位置, 大小等细节. 但不需要从系统层面上掌控, 我们需要的是怎么样将程序同文件联系在一起, 怎么样去读写. 前面提到的重定向可以做到关联程序和文件, 但其来自操作系统, 不能保证其功能, 而且局限较大. C++通过文件IO提供了访问文件的功能.

&emsp;&emsp;本质上C++处理标准输入和文件方式相似, 都是通过对象将文件流同程序结合起来, 但用的是oftream 和 ifstream类对象. 两者都是从iostream类派生而来, 因此可以使用前面提到方法, 如<< 和>>运算符, 但文件IO操作更加复杂, 需要手动指定一些参数, 如读写模式等.

&emsp;&emsp;C++处理文件IO方式, 想要写入首先要创建osfream对象, 并使用ostream方法, 如<<或write()方法; 想要读取首先要创建ifstream对象, 并使用istream方法, 如>> 和read()方法. C++在fstream头文件定义了多个类用于输入输出. C++还有一个fstream, 用于同步文件IO.

```C++

    //创建对象关联文件
    ofstream fcout; //means file cout
    fcout.open("jar.txt");
    //也可以用构造函数创建对象时打开文件 jar.txt

    //可以这样写入数据
    fcout << "Hello world!" << endl;
    //ostream是ofstream的基类, 可以使用其方法

    //和ostream一样, ofstream使用缓冲输入, 因此在创建对象时将为缓冲区分配内存
    //此时缓冲区做到了效率充分利用

    //同理, 读取文件类似
    ifstream fcin( "jar.txt");
    //构造函数打开

    string str;
    getline( fcin, str);
    //cin.getline()并没有string形式, 需用友元函数形式

    //当对象过期时, 对象将自动释放内存, 断开文件链接. 也可以显式关闭文件
    fcout.close();
    fcin.close();
    //这样显式关闭并不会删除缓冲区, 仅断开了与文件连接
    

```

#### **4.1 流状态检查**

<br/>

&emsp;&emsp;C++文件类从ios_base继承了表示流的成员和方法. 如试图打开一个不存在的文件时将设置failbit位, 而ifstream继承于istream, 所以可以直接当作判定条件. 而新版C++提供了一个成员函数用于判断是否打开文件--is_open()方法.

```C++
    if( !fcin)
    {
        ...
    }

    //新式
    if( !fcin.is_open())
    {
        ...
    }
```
### **4.2 打开多个文件**

<br/>

&emsp;&emsp;可以用ofstream类声明多个对象, 打开多个文件, 同时管理. 如打开一个欲读取的文件, 打开两个欲写入的文件. 而有种工具可以提供一些便利.

```C++
    //命令行参数是在输入命令时输入的参数, 可以用于指定文件
    //如果想要程序计算文件中出现的单词数, 可以这样写
    //filecount file1 file2 file3
    //其中filecount是程序名,file1, file2, file3是传送给程序的文件名
    //对此C和C++提供了一种特殊形式的main函数
    int main( int argc, char * argv[])
    {
        ...
    }
    //其中, argc是传入参数数量, argv[]是传送给程序字符串数组
    //可以这样用
    for( int i = 0; i < argc; i++)
    {
        cout << argv[i] << ' ' << endl;
    }

```

&emsp;&emsp;正如类一样控制访问权限, 文件打开也有相应的模式规定是读还是取.

```C++
    ifstream fin( "hellofile", mode1);

    //ios_base定义了一个openmode类, 用于表示文件打开模式. 与fmtflags和iostate类型一样, 也是bitmask类型.可以选择多个常量来指定模式
    //同时C++做出一些调整, 可以与C兼容

```

| 模式常量         | 含义                       |
| ---------------- | -------------------------- |
| ios_base::in     | 打开文件,读取              |
| ios_base::out    | 打开文件,写入              |
| ios_base::ate    | 打开文件,移至文件尾        |
| ios_base::app    | 打开文件,移动到文件尾,追加 |
| ios_base::trunc  | 如果文件存在, 则截断文件   |
| ios_base::binary | 打开二进制文件             |

前面ofstream 和 ifstream open()方法都有默认参数. fout.open()默认为 ios_base::out | ios_base::trunc, fin.open()默认是ios_base::in. 使用位运算符混合模式使用.

个人理解前三种打开方式不同, 后三种是一种打开修饰. 

**truce标记会截断以前文件内容, 虽然会降低空间风险, 但丢失了以前内容.**可以显式指定open()参数.

```C++

    fstream fout( "hellofile", ios_base::out | ios_base::app);
    //追加模式打开文件
    //几种组合可以形成C中文件打开模式
```

### **4.3 打开二进制文件**

<br/>

&emsp;&emsp;fstream对象在打开文件时, 默认是文本模式. C++对象在向文件中读写数据时,首先要先将数据转化成相应字符再进行读写. 而二进制模式ios_base::binary则直接不进行转换, 将二进制数据直接写入文件, 因此直接打开文件是乱码. 在前一此过程中c++会进行一些转换如\r\n --> \n, 而二进制模式则是直接写入. 一种优点是迅速, 另一条是保持了相应的精度.
&emsp;&emsp;二进制模式时配套read()和write()方法更方便.

```C++
    struct Person
    {
        char name[10];
        int num;
    }student[10];

    ofstream fout( "hellofile", ios_base::out | ios_base::app | ios_base::binary);

    //>>运算符形式
    for( int i = 0; i < 10; i++)
    fout << student[i].name << student[i].num << endl;

    //write()形式

    fout.write( (char *)student, sizeof( Person) * 10);
    //二进制文本模式 + write() 方法迅速处理数据
    //但第一的参数必须是char *
    //该函数不进行任何转换, 只是复制字节
    //和C中fwrite()函数类似

```

**上述程序赋值了Person结构中字符数组, 因此可以再次读取并显示. 而对string对象则不是. 因为string对象仅存储了指向字符串的指针, 复制地址字节毫无用处.**


### **4.4 文件随机存取**

<br/>
&emsp;&emsp;因为文件打开模式一种是从头读, 另一种从尾读, 读写不是很方便.所以随机存取应运而生. 

&emsp;&emsp;fstream头文件中定义了fstream类, 即可以同时管理文件输入输出. 派生自iostream, 拥有两个缓冲区及其管理指针. 因此文件模式应该是 in | out | binary

```C++

    //fstream有两种seek函数
    //一为seekg()用于移动输入文件
    //一为seekp()用于移动输出文件
    fstream file( "hellofile", ios_base::in | ios_base::out | ios_base::binary);

    //可以用file进行读和写

    //随即移动函数
    basic_istream<charT, traits> & seekg( off_type, ios_base::seekdir);
    basic_istream<charT, traits> & seekg( pos_type);

    //相当于下面两个函数
    istream& seekg( streamoff, ios_base::seekdir);
    istream& seekg( streamoff);

```

第一个原型定位到距离第二个参数指定位置字节的偏移量, 第二个原型定位到离文件开头特定距离的位置. 移动单位均为字节.

**早期C++seekg()方法实现比较简单, 是一些标准类型( int)的typedef. 而可移植标准则对于有些系统无法提供足够信息, 因此streampos和streamoff允许是类类型. 上面seekg()函数原型目前是模板, 用于通用数据表示( 宽字符)等. 作为pos_type和off_type的char具体化, 如果应用于wistream类型也适用.**

```C++
    //第一种原型第二参数有三种
    //ios_base::beg
    //ios_base::cur
    //ios_base::end


```

&emsp;&emsp;第二个原型中, streampos类型值定位到文件中位置, 可以是类, 但必须有接收一个整形的构造函数. 其值代表文件中距离开头绝对位置( 以字节为单位, 第一个字节编号为0). 若想检查当前位置, 则可以使用tellg()方法( 输入流), 和tellp()( 方法).

**遇到EOF后即使随机移动到文件头, 也不能再读取, 应该用clear()或setstate()清空位重新设置流状态**


## **5 内核格式化**

<br/>

&emsp;&emsp;如前所述, iostream 和 fstream 提供了和标准IO以及文件IO相关的操作, 但对string不太方便. 对于string对象格式化信息等方法称为内核格式化. ( string的 sstream族取代了char的strstream.h支持).

&emsp;&emsp;头文件sstream定义了ostringstream类和istringstream类用于上述方法, 均从相应stream类继承而来, 所以可以使用相应方法. 对于插入抽取操作, 字符也是进入缓冲区, 在需要情况下, 该对象使用动态内存分配增大缓冲区. ostringsream有一个str()方法, 返回一个被初始化成缓冲区内容的成员. 