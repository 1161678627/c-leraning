#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<ctime>
#include<numeric>
using namespace std;


class Transform
{
public:
	int operator() (int val)
	{
		return val+100;
	}
private:

};

class MyPrint
{
public:
	void operator() (int num)
	{
		cout << num << ' ';
	}

private:

};


// 常用的遍历算法
void test_algorithm1()
{
	// 1.for_each遍历
	
	// 2.transform 将一个容器中的数据搬运到另一个容器中，搬运过程中可以用一个仿函数对搬运数据做一些处理
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	v2.resize(v1.size());
	// 最后一个参数是仿函数，如果不想搬运过程中进行什么额外的操作，那么仿函数直接return就可以了
	transform(v1.begin(), v1.end(), v2.begin(), Transform());
	for_each(v2.begin(), v2.end(), MyPrint());
}


class Personp111
{
public:
	Personp111(string name, int age);
	string m_name;
	int m_age;
	bool operator== (const Personp111& p1)
	{
		if (this->m_name == p1.m_name && this->m_age == p1.m_age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:

};
Personp111::Personp111(string name, int age)
{
	this->m_name = name;
	this->m_age = age;
}

class GreatFive
{
public:
	bool operator() (Personp111& p)
	{
		if (p.m_age > 20)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:

};


class GreatThree
{
public:
	bool operator() (int num)
	{
		return num > 3;
	}

private:

};

// 常用的查找算法
void test_algorithm2()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	// 1.find，找没找到都返回一个迭代器，没找到返回end
	vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
	if (it != v1.end())
	{
		cout << "找到元素" << *it << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
	// 找自定义数据类型
	Personp111 p1("aaa", 20);
	Personp111 p2("bbb", 30);
	Personp111 p3("ccc", 40);
	Personp111 p4("ddd", 50);
	vector<Personp111> v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	// 自定义数据类型 find 不知道该怎么对比，怎么算一样还是不一样
	// 所以需要在Person类中重载 == 号的比较方式
	vector<Personp111>::iterator it2 = find(v2.begin(), v2.end(), p1);
	if (it2 != v2.end())
	{
		cout << "找到了元素，name=" << it2->m_name << ",age=" << it2->m_age << endl;
	}
	else
	{
		cout << "没有找到元素" << endl;
	}

	// 2.find_if，使用一个仿函数去找满足条件的 迭代器，但是第一个满足就会返回，只返回一个迭代器，没找到就返回end
	it2 = find_if(v2.begin(), v2.end(), GreatFive());
	if (it2 != v2.end())
	{
		cout << "找到了满足条件的元素，name=" << it2->m_name << ",age=" << it2->m_age << endl;
	}
	else
	{
		cout << "没有找到满足条件的元素" << endl;
	}


	// 查找相邻，重复的元素,找到了迭代器返回第一个重复元素的位置，没找到返回end
	v1.push_back(4);
	it = adjacent_find(v1.begin(), v1.end());
	if (it != v1.end())
	{
		cout << "找到重复相邻元素：" << *it << endl;
	}
	else
	{
		cout << "没有找到相邻重复元素" << endl;
	}


	// 查找指定元素是否存在,返回 bool，找到为真，否则假,但是必须在有序（不管什么容器，数据存放索引是有序的就行）的序列中查,用的是二分法查找
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if (ret)
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没找到" << endl;
	}
	// 如果是无序序列，结果未知，不清楚对错。二分法原理自己推一下


	// 统计元素个数 count
	// 1.统计内置数据类型
	int num = count(v1.begin(), v1.end(), 4);
	cout << "4一共有：" << num << endl;
	// 2.统计自定义数据类型---需要在类中重载 -- 号
	num = count(v2.begin(), v2.end(), p4);
	cout << "p4一共有：" << num << endl;


	// 按条件统计元素个数
	num = count_if(v1.begin(), v1.end(), GreatThree());
	cout << "v1中大于三的数字个数是：" << num << endl;
	// 对于自定义数据类型也是一样的原理，定义一个仿函数即可
}



// 常用的排序算法
void test_algorithm3()
{
	// 1.sort
	// sort(iterator beg, iterator end, _Pred);
	// 默认升序，如果要自定义排序规则，或者对自定义类排序，传入仿函数控制就可以了，前面案例已经有很多了
	// 也可以和 functional 中的 greater<int>() 配合，修改为降序排列
	

	// 2.random_shuffle-洗牌   指定范围内的元素随机调整次序
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	srand((unsigned int)time(NULL));
	random_shuffle(v1.begin(), v1.end());
	for (int i = 0; i < 5; i++)
	{
		cout << v1[i] << ' ';
	}
	cout << endl;

	// 3.merge-容器元素合并，并存储到另一容器中, 注意: 两个容器必须是**有序的**,且都保持升序、降序，合并后的容器也是有序的，不是有序会报错
	vector<int> v2;
	for (int i = 0; i < 5; i++)
	{
		v2.push_back(i+1);
	}

	sort(v1.begin(), v1.end());
	// 目标容器
	vector<int> v3;
	v3.resize(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (int i = 0; i < (v1.size() + v2.size()); i++)
	{
		cout << v3[i] << ' ';
	}


	// 4.reverse-反转容器中的元素，原地反转
	reverse(v1.begin(), v1.end());

}

void myPrint(int& num)
{
	cout << num << " ";
}


class Great30
{
public:
	bool operator() (int num)
	{
		return num > 1000;
	}

private:

};


// 常用的拷贝和替换算法
void test_algorithm4()
{
	//-`copy`                      // 容器内指定范围的元素拷贝到另一容器中
	//- `replace`                // 将容器内指定范围的旧元素修改为新元素
	//- `replace_if `          // 容器内指定范围满足条件的元素替换为新元素
	//- `swap`                     // 互换两个容器的元素

	// 1.copy---不需要过于依赖拷贝算法，很多时候 = 赋值，或者拷贝构造函数就能解决了
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	// 拷贝时候v2也要提前的开辟空间
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());


	// 2.replace
	v2.push_back(20);
	v2.push_back(20);
	v2.push_back(20);
	// 会将所有的20都替换为2000
	replace(v2.begin(), v2.end(), 20, 2000);
	// myPrint如果要传入仿函数，就 重载 () 即可
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;


	// 3.replace_if
	// 将大于等于1000的都替换为30-利用仿函数，重载() 返回bool，所以是一元谓词
	replace_if(v2.begin(), v2.end(), Great30(), 30);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

	
	// 4.swap  这两个容器必须是同类型的，才能拷贝互换。  容量是否要求一致？不要求，甚至可以和空容器交换
	vector<int> v3;
	swap(v2, v3);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
	for_each(v3.begin(), v3.end(), myPrint);
	cout << endl;
}



// 算术生成算法属于小型算法，使用时包含的头文件为 `#include <numeric>
void test_algorithm5()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	// 求和算法accumulate， 最后一个参数为：起始的累加值
	int total = accumulate(v1.begin(), v1.end(), 0);
	cout << "累加后的结果为：" << total << endl;

	vector<int> v2;
	// resize默认填充0
	v2.resize(10);
	// fill 填充算法，可以重新填充，第三个参数为填充值
	fill(v2.begin(), v2.end(), 100);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}


// 常用的集合算法
void test_algorithm6()
{
	//- `set_intersection`          // 求两个容器的交集
	//- `set_union`                // 求两个容器的并集
	//- `set_difference `          // 求两个容器的差集

	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	for (int i = 0; i < 5; i++)
	{
		v2.push_back(i+2);
	}

	// 这个求完交集并集差集后，都是放到一个新的容器里的，因此需要新建一个目标容器
	// 目标容器要开辟多大空间呢？---最大结果是两个容器中取小的size，因此开这么大

	vector<int> v3;
	v3.resize(v1.size() > v2.size() ? v2.size() : v1.size());	// min(v2.size(),v1.size())更简单
	// 获取交集---返回一个迭代器，是在v3中插入末尾的返回的迭代器
	// 获取交集的两个集合必须是 有序序列
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	// 遍历的时候，遍历返回的迭代器即可
	for_each(v3.begin(), itend, myPrint);
	cout << endl;


	// 求并集，参与的两个容器也必须是有序序列才行
	vector<int> v4;
	v4.resize(v1.size() + v2.size());
	itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	for_each(v4.begin(), itend, myPrint);
	cout << endl;


	// 求两个集合的差集---要分求谁和谁的差集，以谁为主体求差集
	vector<int> v5;
	v5.resize(v1.size());	// 以谁为主体求差集，就开辟空间为谁的大小。当然也可以为了省事，直接开辟两个中最大的size为开辟空间，max需要导入algorithm头文件
	itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());	// 如何区分以谁为主体呢？主体先传入，本例中的主体是v1
	for_each(v5.begin(), itend, myPrint);
	cout << endl;
}



int main37() {
	
	/*`<algorithm > `是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
	* `<numeric > `体积很小，只包括几个在序列上面进行简单数学运算的模板函数
	* `<functional > `定义了一些模板类, 用以声明函数对象。*/

	// test_algorithm1();
	// test_algorithm2();
	// test_algorithm3();
	// test_algorithm4();
	// test_algorithm5();
	test_algorithm6();
	return 0;
}