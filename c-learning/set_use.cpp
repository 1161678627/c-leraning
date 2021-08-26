#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


void myPrint(set<int>& s)
{
	for (set<int>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

// set容器的构造和赋值
void test_set1()
{
	// 默认构造
	set<int> s1;

	// set插入数据只有insert这种方式(没有push_back,push_front)---将无序插入自动变为有序
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);	// 插入重复值，不会报错，但结果只有一个，第二次插入不成功
	myPrint(s1);

	// 拷贝构造
	set<int> s2(s1);
	myPrint(s2);

	// 赋值
	set<int> s3 = s2;
	myPrint(s3);
}

// set容器的大小和交换
void test_set2()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	cout << "s1的大小为：" << s1.size() << endl;
	cout << "s1是否为空：" << s1.empty() << endl;

	// set不支持resize方法，因为变长时不知道该给里面补啥

	// 交换
	set<int> s2;
	s2.insert(100);
	s2.insert(400);
	s2.insert(200);
	s2.insert(300);
	s1.swap(s2);
	myPrint(s2);
}

// set容器的插入和删除
void test_set3()
{
	// 插入只有一个 insert
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	// 删除---提供一个迭代器作为参数，begin指向容器中最小的数
	s1.erase(s1.begin());
	myPrint(s1);
	// 删除还有一个重载版本，删除指定的数字
	s1.erase(20);
	myPrint(s1);
	// 删除某个区间
	s1.erase(s1.begin(), s1.end());

	// 清空
	s1.clear();
	myPrint(s1);
}

// set的查找和统计
void test_set4()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	// find 函数返回一个迭代器，如果找到了就是该元素位置的迭代器，如果没找到就是 end位置 的迭代器
	set<int>::iterator it = s1.find(400);
	// 不等于说明找到了
	if (it != s1.end())
	{
		cout << "找到了元素" << *it << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

	// 统计某个数字的个数，对于set 如果有就返回1，么有就返回0---因为某个数字最多只有一个
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

// set和multiset的区别
void test_set5()
{
	set<int> s1;
	// 实际上set在插入的时候会有两个返回值，一个是插入的下标迭代器，另一个是是否插入成功的bool返回值
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	// 使用ret.secend 查看bool返回值
	if (ret.second)
	{
		cout << "插入成功了" << endl;
	}
	else
	{
		cout << "插入失败了" << endl;
	}
	// 第二次插入失败了
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "插入成功了" << endl;
	}
	else
	{
		cout << "插入失败了" << endl;
	}

	// multiset允许插入重复的值，接口和set都是一样的
	multiset<int> ms1;
	// multiset在insert的时候返回值只有一个插入元素下标位置的迭代器，不会有bool判断，因为multiset只要你插入就一定成功，所以没必要有成功判断
	ms1.insert(10);
	ms1.insert(10);
	// 两个10都能打印出来
	for (multiset<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
	{
		cout << *it << " ";
	}
}


// 32
int main32() {
	// 使用set容器的时候所有插入的元素都会被自动排序，底层是二叉树实现的
	// set不允许容器中有重复的元素，mutiset允许有重复元素
	// test_set1();
	// test_set2();
	// test_set3();
	// test_set4();
	test_set5();
}