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


int main25() {
	
	//test_vector();
	//test_vector2();
	//test_vector3();
	test_vector4();
	return 0;
}