#include<iostream>
using namespace std;
#include<vector>	// 使用vector容器前要导入相应的头文件，其他容器也是一样的
#include<algorithm>

void myPrint(int p)
{
	cout << p << endl;
}

// 使用vector容器，存放c++自带的数据类型（一个容器只能同时存一种数据类型）
void test_vector()
{
	// 使用vector容器，存放c++自带的数据类型（一个容器只能同时存一种数据类型）
	vector<int> v;	// 声明一个存放int类型的容器 v
	// 向容器中存放数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// 当我们想要取出容器中的元素的时候就可以使用迭代器来做了
	// 每一个容器都有自己的迭代器，迭代器用于遍历容器中的所有元素
	vector<int>::iterator pBegin = v.begin();	// vector<int>::iterator 使用这种方式声明 vector<int> 类型的迭代器，实际上迭代器是一个指针，v.begin()指向v中第一个元素
	vector<int>::iterator pEnd = v.end();	// v.end() 指向迭代器中最后一个元素的下一个元素

	// 然后就可以开始遍历 容器v中的内容了
	while (pBegin != pEnd)	// 当起始迭代器++到最后一个元素的下一个元素，说明迭代完了，该退出了
	{
		cout << *pBegin << endl;
		pBegin++;	// pBegin可以看成一个指针索引，使用++递增
	}

	// 还可以使用for循环迭代
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << endl;
	}

	// 当然c++ stl还提供了一种标准的遍历算法，不过需要导入 algorithm 头文件
	// 提供容器的 begin 和 end索引，以及需要对容器中元素进行的操作函数即可，该函数参数是单一的容器元素（参数类型就是定义容器时的参数类型）
	for_each(v.begin(), v.end(), myPrint);
}


class Personxxx
{
public:
	Personxxx(string name, int age);
	string m_name;
	int m_age;
private:

};

Personxxx::Personxxx(string name, int age)
{
	this->m_age = age;
	this->m_name = name;
}

void myPrint1(Personxxx& p)
{
	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age << endl;
}

// 使用vector容器存放自定义的数据类型--person类
void test_vector2()
{
	// 使用vector容器存放自定义的数据类型--person类
	Personxxx p1("zhangsan", 18);
	Personxxx p2("lisi", 19);
	Personxxx p3("wangwu", 20);
	Personxxx p4("zhaoliu", 21);

	vector<Personxxx> v;	// 声明Person类型的容器
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// 遍历容器中的数据
	for_each(v.begin(), v.end(), myPrint1);
}


void myPrint2(Personxxx* p)
{
	// 访问指针数据
	cout << "姓名：" << p->m_name << " 年龄：" << (*p).m_age << endl;
}
// 使用vector容器存放自定义的数据类型--person类的指针
void test_vector3()
{
	// 使用vector容器存放自定义的数据类型--person类的指针
	Personxxx p1("zhangsan", 18);
	Personxxx p2("lisi", 19);
	Personxxx p3("wangwu", 20);
	Personxxx p4("zhaoliu", 21);

	vector<Personxxx*> v;	// 声明Person类型指针的容器
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	// 遍历容器中的数据
	for_each(v.begin(), v.end(), myPrint2);
}

// 使用循环给嵌套容器中放入值，注意这里要传入引用才可以，否则值传递的话，是给拷贝对象放入值了，实际上v并没放入值
// 执行修改的时候最好传引用，执行打印可以值传递
void mySetValue(vector<int>& v)
{
	for (int i = 0; i < 4; i++)
	{
		cout << "放入值了" << i << endl;
		v.push_back(i);
	}
}

void myPrint4(vector<int> v)
{
	for_each(v.begin(), v.end(), myPrint);
}


// 容器中嵌套容器
void test_vector4()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<vector<int>> v4;		// 建立嵌套容器，他存放的类型是 容器 类型
	v4.push_back(v1);
	v4.push_back(v2);
	v4.push_back(v3);
	for_each(v4.begin(), v4.end(), mySetValue);
	for_each(v4.begin(), v4.end(), myPrint4);
}


// vector容器的构造函数，即创建一个vector的几种方式
void test_vector5()
{
	// 1.默认构造，无参构造
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrint4(v1);
	// 2.通过区间的方式构造，实际上就是传入两个迭代器，构造这两个迭代器之间的数据
	vector<int> v2(v1.begin(), v1.end());
	myPrint4(v2);
	// 3.n个element的方式构造，实际上就是初始化n个相同的元素
	vector<int> v3(10, 100);	// 个数，element
	myPrint4(v3);
	// 4.拷贝构造，直接拷贝一个传入的vector，拷贝一份新的出来
	vector<int> v4(v3);
	myPrint4(v4);
}

// vector的赋值
void test_vector6()
{
	vector<int>v1;
	// 除了一个一个push_back之外，还可以批量赋值
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// 直接等号赋值
	vector<int> v2 = v1;
	// assign赋值,assign提供两个迭代器参数，然后前闭后开的赋值其中的内容---因为v1.end指向最后一个元素+1的空内容，因此后开刚好能取完，没问题
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	myPrint4(v3);
	// assign赋值，赋值n个element
	v3.assign(3, 100);		// 赋值，不是新增，是直接覆盖其上的原有数据
	myPrint4(v3);
}

// vector的容量和大小
void test_vector7()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// 1.查看容器是否为空,如果为空返回真，否则假
	if (v1.empty())
	{
		cout << "v1为空vector" << endl;
	}
	else
	{
		// 不为空打印 容量，容量是大于当前存的size的
		cout << "v1的容量为：" << v1.capacity() << endl;
		cout << "v1的大小size为：" << v1.size() << endl;
	}
	// 重新指定size大小
	v1.resize(15, 0);	// 如果重新指定的size比原来的更长，就会把剩余的位置用第二个参数补齐，不指定第二个参数，默认用0补齐
	myPrint4(v1);
	v1.resize(3);	// 如果resize比原来的短，就截断后面的不要了
	myPrint4(v1);
}

// 插入和删除
void test_vector8()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// push_back，向尾部插入数据
	}
	// 尾删，一次只删除一个尾部数据
	v1.pop_back();
	myPrint4(v1);
	// 插入数据
	v1.insert(v1.begin(), 1000);	// 插入要传的是迭代器
	myPrint4(v1);
	// 还可以一次插多个相同的element
	v1.insert(v1.begin(), 3, 500);	// 插入3个500
	myPrint4(v1);

	// 擦除
	v1.erase(v1.begin());	// 擦除迭代器位置的元素，只删除一个元素
	v1.erase(v1.begin(), v1.end());		// erase提供 区间移除的方式，如果提供begin 和 end，那么就清空了vector了，同clear

	// 清空
	v1.clear();
	myPrint4(v1);
}

// 数据存取，类似于string容器一样
void test_vector9()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// push_back，向尾部插入数据
	}
	// 下标获取元素
	cout << "第2个元素是：" << v1[1] << endl;
	// at获取元素
	cout << "第3个元素是：" << v1.at(2) << endl;
	// 获取第一个元素
	cout << "第一个元素是：" << v1.front() << endl;
	// 获取最后一个元素
	cout << "第一个元素是：" << v1.back() << endl;
}


// vector容器的互换
void test_vector10()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// push_back，向尾部插入数据
	}
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(10 - i);
	}
	// 互换
	// 现在v1是0-9.v2是10-1
	v1.swap(v2);
	myPrint4(v1);	// 换完v1是 10-1
	myPrint4(v2);

	// 互换的实际用途是：可以收缩内存空间，因为一开始如果一个vector里面存放了很多数据，size很大，当我们把他resize小以后，
	// 虽然数据会截断，size会变小，但是容量会不变小，还是之前那么大，这就会浪费内存了
	// 比如要缩小 v1的容量为v1的size，执行下面的语句即可
	vector<int>(v1).swap(v1);
}


// vector预留空间
void test_vector11()
{
	// vector 是 变长的，一开始分配长度可能不够，再使用的过程中，他会动态增加长度的，重新找内存开辟
	vector<int> v1;
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);	// push_back，向尾部插入数据
		if (p != &v1[0])	// 一开始指向v1的首元素地址，当v1拓展内存时，肯定会重新找一个地方开辟一个新的大的vector，然后把原来的数据都copy进去，释放原来的vector
		{					// 所以新vector的首地址就会改变，我们每当改变一次，就记录一次++，就可以记录拓展内存的次数了
			num++;
			p = &v1[0];
		}
	}
	cout << "v1一共拓展了" << num << "次内存" << endl;


	// 所以这样在大批数据操作存入时，由于不断地开辟新的空间，可能会效率低，因此当我们知道数据量很大的时候，可以直接指定一块很大的空间，免去动态开辟
	vector<int> v2;
	// 注意：reserve预留的空间，没放数据之前也是不能访问的，只有放了数据才能访问，只是一次性开辟很大的空间预留着，能访问不访问是看你存没存到位数据
	v2.reserve(100000);
	int num2 = 0;
	int* p2 = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v2.push_back(i);	// push_back，向尾部插入数据
		if (p2 != &v1[0])	// 一开始指向v1的首元素地址，当v1拓展内存时，肯定会重新找一个地方开辟一个新的大的vector，然后把原来的数据都copy进去，释放原来的vector
		{					// 所以新vector的首地址就会改变，我们每当改变一次，就记录一次++，就可以记录拓展内存的次数了
			num2++;
			p2 = &v1[0];
		}
	}
	cout << "v2一共拓展了" << num2 << "次内存" << endl;	// 只拓展一次，很省事

}



// 25
int main25() {
	
	//test_vector();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	//test_vector7();
	//test_vector8();
	//test_vector9();
	//test_vector10();
	test_vector11();
	return 0;
}