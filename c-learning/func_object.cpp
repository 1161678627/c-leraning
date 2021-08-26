#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;


class MyAdd
{
public:
	int operator() (int v1, int v2) const
	{
		return v1 + v2;
	}

private:

};


class MyPrint
{
public:
	int count;
	MyPrint() {
		count = 0;	// 可以使用一个成员记录自己的状态
	}
	void operator() (string s)
	{
		cout << s << endl;
		this->count++;
	}
private:

};


void do_print(MyPrint& mp, string s)
{
	mp(s);
}


class GreatFive
{
public:
	// 因为返回值为bool，且只有一个参数，所以是一元谓词
	bool operator() (int num)
	{
		return num > 5;
	}

private:

};


// 一元谓词
void test_pred1() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// 前两个参数是迭代器区间，第三个参数是 一个谓词函数
	// GreatFive() 匿名的函数对象，约等于  GreatFive gf; gf();
	// 如果找到了，满足仿函数条件了(只要满足一次就返回，因此返回的位置只有一个)，就返回一个迭代器位置，没找到就返回end迭代器
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreatFive());
	if (it != v1.end())
	{
		cout << "找到了大于5的数字" << *it << endl;
	}
	else
	{
		cout << "没有找到大于5的数字" << endl;
	}
}

class MyCompare
{
public:
	bool operator() (int v1, int v2)
	{
		return v1 > v2;
	}
private:

};


// 二元谓词
void test_pred2()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// sort默认是升序排序
	sort(v1.begin(), v1.end());
	// 如果我们想要降序排序，则要使用仿函数，sort的重载版本
	sort(v1.begin(), v1.end(), MyCompare());
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}


// 算数仿函数
void test_functional()
{
	// 取反仿函数negate-50取反是-50
	negate<int> n;
	cout << n(50) << endl;

	// 加法 plus，实例化时，只用写一个int就行了，因为默认只允许同类型数据进行相加
	plus<int> p;
	cout << p(10, 10) << endl;

	// 其他的算数运算符
	//* `template<class T > T plus<T>`                //加法仿函数
	//* `template<class T > T minus<T>`              //减法仿函数
	//* `template<class T > T multiplies<T>`    //乘法仿函数
	//* `template<class T > T divides<T>`         //除法仿函数
	//* `template<class T > T modulus<T>`         //取模仿函数
	//* `template<class T > T negate<T>`           //取反仿函数
}


// 关系仿函数，大于小于之类的
void test_functional2()
{
	//*`template<class T > bool equal_to<T>`                    //等于
	//* `template<class T > bool not_equal_to<T>`            //不等于
	//* `template<class T > bool greater<T>`                      //大于
	//* `template<class T > bool greater_equal<T>`          //大于等于
	//* `template<class T > bool less<T>`                           //小于
	//* `template<class T > bool less_equal<T>`               //小于等于
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	
	// 降序排列---sort默认是升序操作，但是我们需要降序，所以要写一个仿函数，传入第三个参数
	// 我们可以自己写一个类，定义函数 bool operator() (int v1, int v2)这样写一个自己的仿函数
	// 但是c++也给我们做好了一个关系仿函数，就是greater<int>()，实际上sort底层降序排列，用的就是 less<int>()小于
	sort(v.begin(), v.end(), greater<int>());
}


// 逻辑仿函数
void test_functional3()
{
	//*`template<class T > bool logical_and<T>`              //逻辑与
	//* `template<class T > bool logical_or<T>`                //逻辑或
	//* `template<class T > bool logical_not<T>`              //逻辑非

	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	// 将v中的数据搬运到v2中，并且取反
	vector<bool> v2;
	v2.resize(v.size());	// 这个必须要有，否则会报错，因为v2没有开辟空间，没法给里面塞数据
	// 搬用对象使用transform,参数依次为：原始对象的起始迭代器，终止迭代器，搬运后对象的起始迭代器，仿函数（可选）
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
}

int main36() {
	// 函数对象(仿函数)是一个** 类** ，不是一个函数
	// 函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**

	// 1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	MyAdd myadd;
	cout << myadd(10, 20) << endl;

	// 2.函数对象超出普通函数的概念，函数对象可以有自己的状态
	MyPrint myprint;
	myprint("hello world");
	cout << "myprint调用的次数是：" << myprint.count << endl;

	// 3.函数对象可以作为参数传递---淡然普通函数也可以
	do_print(myprint, "xixixixi");


	// 谓词：返回bool类型的仿函数，如果重载的时候，参数一个就叫一元谓词，参数是两个就是二元谓词
	test_pred1();
	test_pred2();


	// 内建函数对象（对内置数据类型常用的操作，c++都预定义好了，拿来就能用）---使用前需要包含一个头文件 functional
	// 算术仿函数
	// negate 取反仿函数，一元的
	test_functional();

	// 关系仿函数
	test_functional2();

	// 逻辑仿函数
	test_functional3();

	return 0;
}