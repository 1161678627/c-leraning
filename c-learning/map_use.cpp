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


// map�Ĺ���͸�ֵ
void test_map1()
{
	// ����map����
	map<int, int> m1;
	// ����ʹ��insert����ֵ��ֻ����Ҫ����pair��ֵ�ԣ����key��ͬ����������key�岻��ȥ�����Ǹ���
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	myPrint(m1);

	// ��������
	map<int, int> m2(m1);
	myPrint(m2);

	// ��ֵ
	map<int, int> m3 = m2;
	myPrint(m3);
}


// map�����Ĵ�С�ͽ���
void test_map2()
{
	map<int, int> m1;
	cout << "m1" << (m1.empty() ? "Ϊ��" : "��Ϊ��") << endl;
	// ����ʹ��insert����ֵ��ֻ����Ҫ����pair��ֵ��
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));
	cout << "m1�Ĵ�СΪ��" << m1.size() << endl;

	// ����
	map<int, int> m2;
	m2.insert(pair<int, int>(5, 50));
	m2.insert(pair<int, int>(6, 60));
	m2.insert(pair<int, int>(7, 70));
	m2.insert(pair<int, int>(8, 80));
	m2.swap(m1);
	myPrint(m2);
}


// map�Ĳ����ɾ��
void test_map3()
{
	map<int, int> m1;
	// ����1.
	m1.insert(pair<int, int>(1, 10));
	// 2.����ָ�����ͣ�ֱ��д������---�Ƽ�ʹ��
	m1.insert(make_pair(2, 20));
	// 3.value_type
	
	// 4.������ʹ�����ַ�ʽ���룬���ǿ���ʹ�����ַ�ʽ����ȷ�����ڵ�key��value
	m1[3] = 30;	// ����py�е�dict��ֵ
	myPrint(m1);

	// ɾ��
	// 1.���յ�����ɾ��
	m1.erase(m1.begin());
	myPrint(m1);
	// 2.����keyɾ��
	m1.erase(1);	// ɾ��һ�������ڵ�key���ᱨ��
	myPrint(m1);
	// 3.��������ɾ��
	m1.erase(m1.begin(), m1.end());
	// ���
	m1.clear();
	myPrint(m1);
}

// map�Ĳ��Һ�ͳ��---��setһ��
void test_map4()
{
	map<int, int> m1;
	// ����ʹ��insert����ֵ��ֻ����Ҫ����pair��ֵ��
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));

	// ����-����key���ң�����ֵ��һ�����������������а����˼�ֵ�ԣ����û�ҵ����򷵻�end������
	map<int, int>::iterator i = m1.find(3);
	if (i != m1.end())
	{
		cout << "key = " << (*i).first << ", value = " << i->second;
	}
	else
	{
		cout << "δ�ҵ�Ԫ�أ�" << endl;
	}

	// ͳ��---key���ֵĴ���,��map�о��� 0��1   multimap���ܴ���1
	int num = m1.count(3);
	cout << "num = " << num << endl;
}


class MyCompare
{
public:
	bool operator() (int v1, int v2) const
	{
		// ��������
		return v1 > v2;
	}

private:

};



// �������
void test_map5()
{
	map<int, int> m1;
	// �����ʱ��Ĭ�������������
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(make_pair(4, 40));

	// ������޸����������ô��set�����޸��������һ������ʵ����set����ʱ��ָ���º���
	map<int, int, MyCompare> m2;
	// �����ʱ��Ĭ�������������
	m2.insert(pair<int, int>(1, 10));
	m2.insert(pair<int, int>(2, 20));
	m2.insert(pair<int, int>(3, 30));
	m2.insert(make_pair(4, 40));
	for (map<int, int, MyCompare>::iterator i = m2.begin(); i != m2.end(); i++)
	{
		cout << "key = " << (*i).first << ", value = " << i->second << endl;
	}

	// �����Զ����������ͣ���ʵ����mapʱ��ͱ���Ҫָ��һ�� �º�����������ˣ�������set
}


// 34
int main34() {

	// mapʵ���Ͼ���python�е�dict����������pair��pair�еĵ�һ��Ԫ��Ϊ�����ڶ���Ԫ��Ϊֵ������Ԫ�ظ��ݼ��Զ�����
	// ��Ϊ���Զ���������map�ײ�Ҳ�Ƕ�����ʵ�ֵģ�����ʹ��key��������value
	// map�������ظ�Ԫ�أ�multimap�����ظ�Ԫ��
	
	// test_map1();
	// test_map2();
	// test_map3();
	// test_map4();
	test_map5();
	return 0;
}