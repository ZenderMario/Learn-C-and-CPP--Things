# **Functor 函数符**

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [**Functor 函数符**](#functor-函数符)
  - [**预定义的函数符**](#预定义的函数符)
    - [**自适应函数符**](#自适应函数符)
  - [**算法的通用特征**](#算法的通用特征)

<!-- /code_chunk_output -->

&emsp;&emsp;函数符是可以将名称与()结合的对象( 函数和类对象).
&emsp;&emsp;前面有介绍函数中预算符重载, 而()的重载使对象可以被像函数般使用. 即可以应用于 STL 算法的实现.

```C++
    //可以这样定义一个类

    template< typename T>
    class Plus
    {
        public:

        T operator()( T a, T b) { return a + b;}

    };


    //则可以这样使用

    Plus<int> a;

    cout << a( 10, 20);
    //结果为30

```

从上可看出, 函数对象使用起来和真正函数差不多, 而且也支持泛型, STL 算法也更加通用.
&emsp;&emsp;对于一些算法, 如 for_each(), 最后一个参数可以是函数指针, 也可以是函数对象, 即定义时通过泛型定义参数, 最后在函数内就能像函数一样使用 a().下面展示了 STL 定义的函数符的概念.

- 生成器( generator) 不用参数可以调用的函数符
- 一元函数( unary function) 一个参数可以调用
- 二元函数( binary funciton) 两个参数

所以提供给 for_each()应该是医院, 每次只用一个元素.

这些概念也有些改进:

- 返回 bool 的一元函数是谓词( predicate)
- 返回 bool 的二元函数是二元谓词( binary predicate)

比如 sort()算法就需要二元谓词( 比较大小).

&emsp;&emsp;list 模板有一个将谓词作为参数的 remove_if 成员, 将其应用在每个元素, 如果谓词返回 true, 则删除.

```C++
    bool isbig( int n)
    {
        return n > 100 ? true : false;
    }

    int a[10] = { 200, 10, 200, 20 , 10, 30};

    list<int> l( a, a + 10);


```

## **预定义的函数符**

&emsp;&emsp;STL 定义了多个函数符, 用于支持 STL 函数.

```C++

    //transform() 函数接收四个参数, 前三个是源区间和目标位置(输出)迭代器, 第五个则是函数符, 用于应用于源的每个元素生成于目标容器.

    const int M = 5;
    int arr1[M] = { 37, 39, 52, 45, 48};
    vector<int> gr( arr1, arr1+5);
    ostream_iterator<int, char> oi( cout, " ");

    transform( vector.begin(), vector.end(), oi, sqrt);
    //有问题
    //多个重载的版本但无法选择那个实例?
    //不明


```

&emsp;&emsp;更好的办法是定义一个模板, 而不是临时定义一个函数或类. 头文件&lt;functional>定义了一些函数对象.
比如用 plus&lt;>模板做加法运算.

| 运算符 |    函数符     |
| :----: | :-----------: |
|   +    |     plus      |
|   -    |     minus     |
|   \*   |  multiplies   |
|   /    |    divides    |
|   %    |    modulus    |
|   -    |    negate     |
|   ==   |   equal_to    |
|   !=   | not_equal_to  |
|   >    |    greater    |
|   <    |     less      |
|   >=   | greater_equal |
|  <=>   |  less_equal   |
|   &&   |  logical_and  |
|  \|\|  |  logical_or   |
|   !    |  logical_not  |

<br/>

### **自适应函数符**

&emsp;&emsp;上表提到的函数符都是自适应的. 因其携带了相关标识参数类型和返回类型的 typedef 成员. 可以简化函数符使用, 使其更通用.

```C++

    transform( gr.begin(), gr.end(), oi, ? )
    //假设要将每个元素*2.5, 该怎么办?
    //要定义新的二元函数比较麻烦
    //可以运用自适应性

    //c++提供了binder1st类和其函数(简化类运用).

    bind1st( multiplies<double>(), 2.5) mul;

    //所以可以
    transform( gr.begin(), gr.end(), oi, mul);
    //即将二元函数改成一元函数

    //binder1st将特定值赋给函数符第一个参数
    //binder2nd将特定值赋给函数符第一个参数

```

<br/>

## **算法的通用特征**

由前所学知, STL 算法使用迭代器确定区间. STL 使用模板参数名称表示参数模型的概念( 多种迭代器类型). 如 copy 函数原型:
&emsp;&emsp;template < calss InputIterator, class OutputIterator>
&emsp;&emsp;OutputIterator copy( InputIterator first, InputIterator last, OutputIterator result);
即相关使用迭代器必须是同级或更高类型的迭代器.


