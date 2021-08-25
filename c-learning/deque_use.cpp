#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//**deque（双端容器）与vector（单端）区别：**
//* vector对于头部的插入删除效率低，数据量越大，效率越低---因为头插时vector需要把头插后的数据都给后移动一次，很麻烦
//* deque相对而言，对头部的插入删除速度回比vector快
//* vector访问元素时的速度会比deque快, 这和两者内部实现有关

void myPrint(deque<int>& d)
{
	for (deque<int>::iterator i = d.begin(); i != d.end(); i++)
	{
		cout << *i << " ";	// i是一个指针，解引用即可拿到其指向的数据
	}
	cout << endl;
}

// deque容器的构造函数，和vector基本保持一致
void test_deque1()
{
	// 默认构造
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myPrint(d1);

	// 区间构造
	deque<int> d2(d1.begin(), d1.end());
	// 赋值n个m
	deque<int> d3(10, 100);
	// 拷贝构造
	deque<int> d4(d3);
	myPrint(d4);
}


// deque容器的赋值操作
void test_deque2()
{
	// 默认构造
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myPrint(d1);

	// 1.等号赋值
	deque<int> d2 = d1;
	// 2.assign赋值
	deque<int> d3;
	d3.assign(d2.begin(), d2.end());
	// 3.赋值n个m，利用assign
	deque<int> d4;
	d4.assign(10, 100);
	myPrint(d4);
}


// deque容器的大小和是否为空，resize等等操作
void test_duque3()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	// 大小size
	cout << "d1的size为：" << d1.size() << endl;
	// deque没有容量这个概念，因为他两端都能插入，用表管理不连续内存片段，因此想插随时都能插，不存在重新开辟更大的内存这回事
	// 是否为空
	cout << "d1是否为空" << d1.empty() << endl;

	// 重新指定大小---比原来长用0填充，或者指定填充数字
	d1.resize(15, 100);
	myPrint(d1);
	// 比原来短就截断
	d1.resize(5);
	myPrint(d1);
}


// deque容器的插入和删除
void test_deque4()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	// 头插
	d1.push_front(100);
	// 尾插
	d1.push_back(99);
	myPrint(d1);
	// 头删
	d1.pop_front();
	// 尾删
	d1.pop_back();
	myPrint(d1);

	// insert插入
	d1.insert(d1.begin(), 100);	// 第一个参数是迭代器
	d1.insert(d1.begin(), 2, 1000);	// 重载版本，插入n个element

	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);

	d1.insert(d1.begin(), d2.begin(), d2.end());	// 迭代器，区间插入
	myPrint(d1);

	// erase单个删除
	deque<int>::iterator i = d1.begin();
	i++;
	d1.erase(i);	// 删除下标为1的元素
	myPrint(d1);
	// erase 区间删除
	d1.erase(d1.begin(), d1.end());	// 相当于清空
	myPrint(d1);
	// 清空
	d1.clear();
}


// deque数据存取，索引 [index]，at
void test_deque5()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	for (int i = 0; i < 4; i++)
	{
		// 利用中括号访问元素
		cout << d1[i] << " ";
	}
	cout << endl;

	cout << d1.at(1) << endl;

	// 头尾元素获取
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}

// deque容器排序
void test_deque6()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	myPrint(d1);
	// 使用sort函数进行排序操作，参数为排序容器的 begin指针和sort指针，原地操作，直接修改传入容器的内容
	sort(d1.begin(), d1.end());
	myPrint(d1);
}


// 27
int main27() {
	// test_deque1();
	// test_deque2();
	// test_duque3();
	// test_deque4();
	// test_deque5();
	test_deque6();
	return 0;
}