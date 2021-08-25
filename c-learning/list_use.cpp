#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

// 打印
void myPrint(const list<int>& l)
{
	for (list<int>::const_iterator i = l.begin(); i != l.end(); i++)	// 只读形式时，应该用const_iterator这个迭代器
	{
		cout << *i << ' ';
	}
	cout << endl;
}



// list的构造函数
void test_list1()
{
	// 默认构造
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	myPrint(l1);

	// 区间构造
	list<int> l2(l1.begin(), l1.end());
	myPrint(l2);

	// 拷贝构造
	list<int> l3(l2);
	myPrint(l3);

	// n个element
	list<int> l4(10, 1000);
	myPrint(l4);
}

// list 的赋值和交换
void test_list2()
{
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	list<int> l2;
	// 使用等号赋值
	l2 = l1;
	myPrint(l2);
	// 使用assign赋值，和其他的都差不多，assign和list构造中的方法也一致
	list<int> l3;
	l3.assign(l2.begin(), l2.end());
	myPrint(l3);
	list<int> l4;
	l4.assign(10, 100);
	myPrint(l4);
	
	// 交换---直接交换，不需要指定返回值
	l3.swap(l4);
	myPrint(l3);
	myPrint(l4);
}

// list容器中的size和resize操作
void test_list3()
{
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	cout << "l1的size为：" << l1.size() << endl;
	cout << "l1是否为空：" << l1.empty() << endl;
	// resize和其他容器都一样，给长了resize 补0，或者自己指定补什么
	// 短了，就截断
	l1.resize(10, 100);
	myPrint(l1);
	l1.resize(2);
	myPrint(l1);
}

// list的插入和删除操作---两端插入、删除和中间插入和删除
void test_list4()
{
	//* 尾插-- - push_back
	//* 尾删-- - pop_back
	//* 头插-- - push_front
	//* 头删-- - pop_front
	//* 插入-- - insert
	//* 删除-- - erase
	//* 移除-- - remove
	//* 清空-- - clear

	list<int> l1;
	// 头插尾插
	l1.push_back(10);
	l1.push_back(20);
	l1.push_front(30);
	l1.push_front(40);
	myPrint(l1);
	// 头删、尾删
	l1.pop_back();
	l1.pop_front();
	myPrint(l1);

	// insert插入
	list<int>::iterator it = l1.begin();
	it++;
	l1.insert(it, 1000);	// 在第二个位置插入1000
	myPrint(l1);

	// erase删除
	it = l1.begin();
	l1.erase(++it);
	myPrint(l1);

	// remove---删除所有 传入的参数
	l1.push_back(1000);
	l1.push_back(1000);
	l1.push_back(1000);
	l1.remove(1000);
	myPrint(l1);

	// 清空-clear
	l1.clear();
	myPrint(l1);
}

// list的数据存取，只有front和back，没有下标和at取数据，不支持随机访问，因为list在内存中不是连续的，没法根据下标算出来 下一个元素的位置，必须走指针才行，一个一个走
void test_list5()
{
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	cout << "l1的第一个元素是：" << l1.front() << endl;
	cout << "l1的最后一个元素是：" << l1.back() << endl;

	// 想直接访问第一个元素，只能先 l1.begin() ,然后一直++，加到你要的索引位置，或者l1.end(),然后 -- 也行
}


bool myCompare(int num1, int num2)
{
	return num1 > num2;
}


// list数据反转和排序
void test_list6()
{
	list<int> l1;
	l1.push_back(20);
	l1.push_back(5);
	l1.push_back(4);
	l1.push_back(33);
	l1.push_back(1);
	myPrint(l1);

	// 反转
	l1.reverse();
	myPrint(l1);
	// 排序---所有不支持随机访问的迭代器，不可以用标准算法
	// 但是他的内部会提供一些成员函数完成相应功能
	l1.sort();	// 默认升序
	myPrint(l1);
	l1.sort(myCompare);	// 如果要降序排列，则要指定新增参数-规则
	myPrint(l1);
}


class Personppp
{
public:
	Personppp(string name, int age, int height);
	string m_name;
	int m_age;
	int m_height;

private:

};

Personppp::Personppp(string name, int age, int height)
{
	this->m_name = name;
	this->m_age = age;
	this->m_height = height;
}

void printPerson(Personppp& p)
{
	cout << "姓名：" << p.m_name << "\t年龄：" << p.m_age << "\t身高：" << p.m_height << endl;
}


bool sortPerson(Personppp& p1, Personppp& p2)
{
	// 如果年龄相同则，按照身高排序
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	// 如果年龄不同，则按照年龄排序即可
	else
	{
		return p1.m_age < p2.m_age;
	}
}


// 自定义数据类型的排序
void test_list7()
{
	list<Personppp> l1;
	// 准备数据
	Personppp p1("刘备", 35, 175);
	Personppp p2("曹操", 45, 180);
	Personppp p3("孙权", 40, 170);
	Personppp p4("赵云", 25, 190);
	Personppp p5("张飞", 35, 160);
	Personppp p6("关羽", 35, 200);

	l1.push_back(p1);
	l1.push_back(p2);
	l1.push_back(p3);
	l1.push_back(p4);
	l1.push_back(p5);
	l1.push_back(p6);

	for_each(l1.begin(), l1.end(), printPerson);

	// 排序
	string fgf(50, '-');
	cout << fgf << endl;

	l1.sort(sortPerson);	// 使用自定义的函数，对自定义数据类型进行排序
	for_each(l1.begin(), l1.end(), printPerson);
}


int main31() {

	// list 链表
	// 链表在内存中是离散形式的节点存在的，每一个节点由数据域和指针域构成，数据域维护这个节点存的数据，
	// 指针域维护下一个节点的地址，形成一条长链，虽然内存离散，但是指针域使得可以连续访问
	// 好处是，对于任意位置，可以快速的插入和删除，因为只用修改指针域的指向即可，不用重复开辟空间和复制原有数据
	// 缺点是，遍历的时候可能比较慢，而且占用空间可能大于数组，因为存在指针域
	// STL中提供的链表是一个 双向循环链表，每个节点有一个next指针，还有一个prev指针

	// test_list1();
	// test_list2();
	// test_list3();
	// test_list4();
	// test_list5();
	// test_list6();
	test_list7();
	return 0;
}