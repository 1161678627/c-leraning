#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

void myPrint(map<int, int>& m)
{
	for (map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	{
		cout << "key = " << i->first << ", value = " << i->second << endl;
	}
}


// map的构造和赋值
void test_map1()
{
	// 创建map容器
	map<int, int> m1;
	// 可以使用insert插入值，只不过要插入pair键值对，如果key相同，后面插入的key插不进去，不是覆盖
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	myPrint(m1);

	// 拷贝构造
	map<int, int> m2(m1);
	myPrint(m2);

	// 赋值
	map<int, int> m3 = m2;
	myPrint(m3);
}


// map容器的大小和交换
void test_map2()
{
	map<int, int> m1;
	cout << "m1" << (m1.empty() ? "为空" : "不为空") << endl;
	// 可以使用insert插入值，只不过要插入pair键值对
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	cout << "m1的大小为：" << m1.size() << endl;

	// 交换
	map<int, int> m2;
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	m2.insert(pair<int, int>(8, 80));
	m2.swap(m1);
	myPrint(m2);
}


// map的插入和删除
void test_map3()
{
	map<int, int> m1;
	// 插入1.
	m1.insert(pair<int, int>(1, 10));
	// 2.不用指定类型，直接写就行了---推荐使用
	m1.insert(make_pair(2, 20));
	// 3.value_type
	
	// 4.不建议使用这种方式插入，但是可以使用这种方式访问确定存在的key的value
	m1[3] = 30;	// 类似py中的dict赋值
	myPrint(m1);

	// 删除
	// 1.按照迭代器删除
	m1.erase(m1.begin());
	myPrint(m1);
	// 2.按照key删除
	m1.erase(1);	// 删除一个不存在的key不会报错
	myPrint(m1);
	// 3.按照区间删除
	m1.erase(m1.begin(), m1.end());
	// 清空
	m1.clear();
	myPrint(m1);
}

// map的查找和统计---和set一致
void test_map4()
{
	map<int, int> m1;
	// 可以使用insert插入值，只不过要插入pair键值对
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));

	// 查找-按照key查找，返回值是一个迭代器，迭代器中包含了键值对，如果没找到，则返回end迭代器
	map<int, int>::iterator i = m1.find(3);
	if (i != m1.end())
	{
		cout << "key = " << (*i).first << ", value = " << i->second;
	}
	else
	{
		cout << "未找到元素！" << endl;
	}

	// 统计---key出现的次数,在map中就是 0，1   multimap可能大于1
	int num = m1.count(3);
	cout << "num = " << num << endl;
}


class MyCompare
{
public:
	bool operator() (int v1, int v2) const
	{
		// 降序排列
		return v1 > v2;
	}

private:

};



// 排序操作
void test_map5()
{
	map<int, int> m1;
	// 插入的时候默认升序排序好了
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(make_pair(4, 40));

	// 如果想修改排序规则，那么和set容器修改排序规则一样，在实例化set容器时，指定仿函数
	map<int, int, MyCompare> m2;
	// 插入的时候默认升序排序好了
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(make_pair(4, 40));
	for (map<int, int, MyCompare>::iterator i = m2.begin(); i != m2.end(); i++)
	{
		cout << "key = " << (*i).first << ", value = " << i->second << endl;
	}

	// 对于自定义数据类型，在实例化map时候就必须要指定一个 仿函数排序规则了，类似于set
}


// 34
int main34() {

	// map实际上就是python中的dict，里面存的是pair，pair中的第一个元素为键，第二个元素为值，所有元素根据键自动排序
	// 因为会自动排序，所以map底层也是二叉树实现的，可以使用key快速索引value
	// map不允许重复元素，multimap允许重复元素
	
	// test_map1();
	// test_map2();
	// test_map3();
	// test_map4();
	test_map5();
	return 0;
}