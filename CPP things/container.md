# **Container**

&emsp;&emsp;容器是存放数据的类对象, STL 设计了类方法以用来动态存放数据.



<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [**Container**](#container)
  - [**1 容器概念**](#1-容器概念)
  - [**2 序列容器**](#2-序列容器)
    - [**2.1 vector**](#21-vector)
    - [**2.2 deque 双端队列**](#22-deque-双端队列)
    - [**2.3 list 双向链表**](#23-list-双向链表)
    - [**2.4 forward_list**](#24-forward_list)
    - [**2.5 queue队列 FIFO**](#25-queue队列-fifo)
    - [**2.6 priority_list**](#26-priority_list)
    - [**2.7 stack 栈 LIFO**](#27-stack-栈-lifo)
    - [**2.8 array**](#28-array)
  - [**3 关联容器**](#3-关联容器)
    - [**3.1 set 集合**](#31-set-集合)
    - [**3.2 multimap**](#32-multimap)
    - [**3.3 无序容器**](#33-无序容器)

<!-- /code_chunk_output -->



## **1 容器概念**

&emsp;&emsp;容器操作所占时间

- **编译时间** 编译时执行
- **固定时间** 运行时执行, 但固定操作, 和容器大小无关
- **线性时间** 运行时执行, 但和容器大小线性相关

&emsp;&emsp;基本特征:

1. 容器用于存储一系列同类型的值
2. 容器存储数据必须是可复制构造和可赋值的. 如果类有复制构造函数, 赋值运算符则也满足容器模板存储类型要求
3. 如果容器内元素为指针,则可能指向堆内存不会释放 (智能指针)

| 表达式              |                               说明                               |
| :------------------ | :--------------------------------------------------------------: |
| X::iterator         |                       指向 X 的正向迭代器                        |
| X::reverse_iterator |                       指向 X 的反向迭代器                        |
| X()                 |                             构造函数                             |
| X::value_type       |                     容器元素的类型(typedef)                      |
| X::swap()           |                         交换两个容器内容                         |
| x::~x()             |                             析构函数                             |
| a == b              | 将 a 中所有元素和 b 中所有对应元素比较是否相等(大小不同直接不等) |

<br/>

&emsp;&emsp;C++11 新要求

| 表达式         |          说明          |
| :------------- | :--------------------: |
| X::(rv)        | 移动构造函数(右值引用) |
| 移动赋值运算符 |                        |
| const 迭代器   | X::cbegin() X::cend()  |

## **2 序列容器**

&emsp;&emsp;C++ STL 共有七种类型序列: deque, forward_list, list, queue,priority_queue, stack, vector.
&emsp;&emsp;序列改进了基本的容器概念, 基本有以下特征:

- 迭代器至少是正向迭代器的要求, 所以元素按顺序排列, 不会在两次迭代间发生变化
- 有严格线性顺序, (第一个元素, 最后一个元素, 其它都有前后元素), 即树之类结构不是
- 具有确定顺序, 因此可以进行插入, 删除等操作

| 表达式              | 返回类型 |                   说明                    |
| :------------------ | :------: | :---------------------------------------: |
| X a( n, t)          |          | 构造函数, 由 n 个 t 构成(可以有匿名对象)  |
| X a(i1, i2)         |          | a(i1, i2)初始化为区间[i1, i2)值(匿名对象) |
| a.insert(p,t)       |  迭代器  |            将 t 插入到 p 前面             |
| a.insert(p, n, t)   |   void   |                                           |
| a.insert(p, i1, i2) |   void   |                 区间插入                  |
| a.erase(p)          |  迭代器  |             消除 p 指向的数据             |
| a.erase(i1, i2)     |  迭代器  |                                           |
| a.clear()           |   void   |                   清空                    |

<br/>

&emsp;&emsp;除此之外deque, list, queue, priority_queue, stack, vector还有一些其它操作, 允许情况下时间复杂度都是固定时间

| 表达式          | 返回类型 |       容器        |
| :-------------- | :------: | :---------------: |
| a.front()       |    T&    | vector list deque |
| a.back()        |   同上   |                   |
| a.push_front(t) |   void   |    list deque     |
| a.push_back(t)  |   void   |    vector 同上    |
| a.pop_front(t)  |   同上   |                   |
| a.pop_back(t)   |          |                   |
| a\[n]            |    T&    |   vector deque    |
| a.at(n)         |   同上   |       同上        |

&emsp;&emsp;**上述成员函数规定了能对容器进行的操作. 从上表知没有为vector定义push_front(), 因为如果制定, 需要将前面元素整体后移, 即线性时间, 而list和deque仅需新建结点即固定时间.**

### **2.1 vector**

<br/>

&emsp;&emsp;vector可以动态改变长度, 删除和新增. 此外还提供了随机访问, 因此可以像数组一样访问vector. 而且在尾部添加和删除元素的时间是固定的, 但在头部或其他地方为线性时间. 
&emsp;&emsp;同时, vector还是反转容器模型, 即反向迭代器rbegin()和rend() --> reverse_iterator

<br/>

### **2.2 deque 双端队列**

<br/>

&emsp;&emsp;实现类似vector, 但支持固定时间插入开始位置(或删除), 所以多数操作发生在起始和结尾考虑deque, 而vector操作更快

### **2.3 list 双向链表**

<br/>

&emsp;&emsp;顾名思义,即可以双向遍历链表. 和vector不同, list插入和删除时间都是固定的, 而且不允许随即访问和下标表示. 同时, list插入后原有迭代器仍指向原元素, 而vector则是指向新元素. 因为list仅用指针跟踪节点, 而vector需要整体移动.
&emsp;&emsp;同时list有实现sort()成员函数, 因为快速插入就不能实现随机访问, STL通用sort()便不能使用.
&emsp;&emsp;sort(), merge(), unique()还拥有重载版本, 接受一个谓词函数用来判断参数.

| list成员函数                                  |                                   说明                                   |
| :-------------------------------------------- | :----------------------------------------------------------------------: |
| void merge( list< T, Alloc> &)                | 将x与调用链表合并(必须已经排序), 合并后放在调用链表中, x为空, 线性复杂度 |
| void remove( const T & val)                   |                       删除val所用实例, 线性复杂度                        |
| void sort()                                   |                       <预算符排序, N$\log$N 复杂度                       |
| void splice( iterator pos, list< T, Alloc> x) |               将x链表插入到pos标记位置, x将为空, 固定时间                |
| void unique()                                 |                  连续相同元素压缩为单个元素, 线性复杂度                  |

<br/>

### **2.4 forward_list**

&emsp;&emsp;相当于只能单向遍历的链表, 代码更快, 但功能更少

<br/>

### **2.5 queue队列 FIFO**

&emsp;&emsp;queue是一个适配器类(相当于ostream_iterator, 能让输出流使用迭代器接口), 可以让deque展示队列接口.
&emsp;&emsp;queue限制比deque多, 不允许遍历队列. 只保留基本操作, 如添加, 删除队首, 查看队首和队尾, 查看是否为空. 所以使用元素时应该先用front()查看, 后用pop()弹出. 

&emsp;&emsp;支持以下方法

| 方法                  |   说明   |
| :-------------------- | :------: |
| bool empty() const    |          |
| size_t size() const   |          |
| T& front()            |          |
| T& back()             |          |
| void push(const T& x) | 队尾插入 |
| void pop()            | 删除队首 |

<br/>

### **2.6 priority_list**

<br/>

&emsp;&emsp;类似于list, 但最大的元素将被移至队首. ~~生活总是不公平的, 编程也是~~内部区别是默认底层为vector, 但可以用构造函数指定 priority_list&lt;int> a( greater&lt;int>) greater<> 是个函数对象, 后见谓词.

<br/>

### **2.7 stack 栈 LIFO**

<br/>

&emsp;&emsp;同样不允许随机访问和遍历, 也限制了一些基本操作, 

| 方法                  |     说明     |
| :-------------------- | :----------: |
| bool empty() const    |              |
| size_t size() const   |              |
| T& top()              |   栈顶元素   |
| void push(const T& x) | 栈顶插入插入 |
| void pop()            |   删除栈尾   |

<br/>

### **2.8 array**

<br/>

&emsp;&emsp;STL将array划入序列范围内, 但不支持动态内存, 因此push()和pop()无效. 但基本操作仍具备如[]随机访问, 因此可以应用sort()等算法.

## **3 关联容器**

<br/>

&emsp;&emsp;关联容器应用另一种概念--将值和对应的键关联起来(类似于映射), 并使用键来查找值(不一定一种类型). X::value_type和X::key_type指出了值和键的类型.
&emsp;&emsp;关联容器一个优点是可以快速访问元素(有特定算法查找信息), 插入新元素, 所以不能指定插入值的位置. 
&emsp;&emsp;关联容器通常是某种树来实现, 因此可以快速查找, 但添加速度稍有减少.
&emsp;&emsp;STL提供了4种关联容器: set, multsit, map, multimap. 前两种在&lt;set>头文件, 后两种在&lt;map>头文件

<br/>

### **3.1 set 集合**

set和数学上集合性质类似, 互异性, 但有序,

&emsp;&emsp;也是用类型指定储存类型, 同priority_list, 也可以指定一个谓词函数, 但在模板参数位置, 默认使用less&lt; T>;

```C++

    string st[6] = { "hello", "world", "I am", "big" };

	set<string> sa( st, st + 6);

	for (auto x : sa)
		cout << x << ' ';

```
结果自动排序.
&emsp;&emsp;此外STL还有一些通用函数用于set( set自动排序, 因此满足条件). set_union()函数接收5个参数, 前两个知名第一个集合, 中间两个第二个集合, 最后一个是输出迭代器.如果想要保存并集,需要用到insert_iterator.
&emsp;&emsp;set_intersection和set_difference分别用于交集和差, 参数和set_union()同.
&emsp;&emsp;lower_bound()和upper_bound(). 前者将键作为一个参数, 返回容器中第一个第一个小于键参数的成员, 同理upper_bound()也返回一个迭代器. 

```C++
  string str[6] = { "hello", "world", "I am", "Welcom", "neo", "alien"};

  set<string> sa( str, str + 3);
  set<string> sb( str + 2, str + 6);

  sa.insert("forget");
  //因为set容器有序, 故不需要指明插入位置

  set_union( sa.begin(), sa.end(), sb.begin(), sb.end(), ostream_iterator< string, char>( cout, " "));


```

<br/>

### **3.2 multimap**

<br/>

&emsp;&emsp;与set类似, 也是可反转的, 排序容器, 但键和值的类型不同, 且一个键可以对应多个值

```CPP

  //multimap声明

  multimap< int, string> codes;

```
其中键类型为int, 值类型为string.
&emsp;&emsp;为将键和值固定在一起, C++使用模板类pair&lt;const keytype, datatype>存储到一个对象当中. 

```CPP
  //假设要插入一条键-值
  //第一种方法
  pair< int, string> item( 123, "Los");

  codes.insert( item);

  //第二种
  codes.insert( pair< int, string> ( 123, "Los"));

  //则对于pair对象, 可以通过.first 和 .second成员访问

  cout << item.first << ' ' << item.second ;

  //关于获取multimap对象信息

  //成员函数count()返回键参数对应值的数目
  codes.count( 123);

  //也具有lower_bound()和upper_bound()成员函数. 

  //而成员函数equal_range()则返回键参数对应的区间(已经排序), 含有两个迭代器, 即通过pair模板实现.

  pair < multimap< int, string>::iterator, multimap<int, string>::iterator > it = codes.equal_range( 123);
  //返回容器中123对应键-值区间


```

当然也可以用auto, typedef, using来简化代码

<br/>

### **3.3 无序容器**

<br/>

&emsp;&emsp;由于multimap和set均是对容器元素进行排序, 所以势必降低运行速度. 无序关联容器则和有序一样均将值和键对应, 但底层结构由树转为哈希表, 则提高元素添加和删除速度.
&emsp;&emsp;共有四种无序容器--unordered_set, unordered_multiset, unordered_map和unordered_multimap



