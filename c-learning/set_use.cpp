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

// set�����Ĺ���͸�ֵ
void test_set1()
{
	// Ĭ�Ϲ���
	set<int> s1;

	// set��������ֻ��insert���ַ�ʽ(û��push_back,push_front)---����������Զ���Ϊ����
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);	// �����ظ�ֵ�����ᱨ�������ֻ��һ�����ڶ��β��벻�ɹ�
	myPrint(s1);

	// ��������
	set<int> s2(s1);
	myPrint(s2);

	// ��ֵ
	set<int> s3 = s2;
	myPrint(s3);
}

// set�����Ĵ�С�ͽ���
void test_set2()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	cout << "s1�Ĵ�СΪ��" << s1.size() << endl;
	cout << "s1�Ƿ�Ϊ�գ�" << s1.empty() << endl;

	// set��֧��resize��������Ϊ�䳤ʱ��֪���ø����油ɶ

	// ����
	set<int> s2;
	s2.insert(100);
	s2.insert(400);
	s2.insert(200);
	s2.insert(300);
	s1.swap(s2);
	myPrint(s2);
}

// set�����Ĳ����ɾ��
void test_set3()
{
	// ����ֻ��һ�� insert
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	// ɾ��---�ṩһ����������Ϊ������beginָ����������С����
	s1.erase(s1.begin());
	myPrint(s1);
	// ɾ������һ�����ذ汾��ɾ��ָ��������
	s1.erase(20);
	myPrint(s1);
	// ɾ��ĳ������
	s1.erase(s1.begin(), s1.end());

	// ���
	s1.clear();
	myPrint(s1);
}

// set�Ĳ��Һ�ͳ��
void test_set4()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);

	// find ��������һ��������������ҵ��˾��Ǹ�Ԫ��λ�õĵ����������û�ҵ����� endλ�� �ĵ�����
	set<int>::iterator it = s1.find(400);
	// ������˵���ҵ���
	if (it != s1.end())
	{
		cout << "�ҵ���Ԫ��" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	// ͳ��ĳ�����ֵĸ���������set ����оͷ���1��ô�оͷ���0---��Ϊĳ���������ֻ��һ��
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

// set��multiset������
void test_set5()
{
	set<int> s1;
	// ʵ����set�ڲ����ʱ�������������ֵ��һ���ǲ�����±����������һ�����Ƿ����ɹ���bool����ֵ
	pair<set<int>::iterator, bool> ret = s1.insert(10);
	// ʹ��ret.secend �鿴bool����ֵ
	if (ret.second)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ����" << endl;
	}
	// �ڶ��β���ʧ����
	ret = s1.insert(10);
	if (ret.second)
	{
		cout << "����ɹ���" << endl;
	}
	else
	{
		cout << "����ʧ����" << endl;
	}

	// multiset��������ظ���ֵ���ӿں�set����һ����
	multiset<int> ms1;
	// multiset��insert��ʱ�򷵻�ֵֻ��һ������Ԫ���±�λ�õĵ�������������bool�жϣ���ΪmultisetֻҪ������һ���ɹ�������û��Ҫ�гɹ��ж�
	ms1.insert(10);
	ms1.insert(10);
	// ����10���ܴ�ӡ����
	for (multiset<int>::iterator it = ms1.begin(); it != ms1.end(); it++)
	{
		cout << *it << " ";
	}
}

// �º�����
class MyCompare
{
public:
	// ����С����,�ǵú���Ҫ��const
	bool operator() (int v1, int v2)const
	{
		// ���õ�һ�������ڵڶ�����
		return v1 > v2;
	}

private:

};



// set������������޸�---������������
void test_set6()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	myPrint(s1);	// ��ӡʱ���Ѿ�Ĭ�������ĺ�xu��

	// �޸��������Ϊ����
	// ��Ϊset�ǲ����ʱ�򹹽�����������ģ������Ҫ����ָ��set��������򣬾ͱ����ڴ�����������û�в�������ǰ��ָ����
	// ����setʱ�򣬿���ָ���ڶ�������Ϊһ���º���
	set<int, MyCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	// ��������ҲҪ����
	for (set<int, MyCompare>::iterator i = s2.begin(); i != s2.end(); i++)
	{
		cout << *i << ' ';
	}

}

class MyPerson
{
public:
	MyPerson(string name, int age)
	{
		this->m_name = name;
		this->age = age;
	}
	string m_name;
	int age;

private:

};

class MyPersonCompare
{
public:
	bool operator() (const MyPerson p1, const MyPerson p2)const
	{
		// �������併��
		return p1.age > p2.age;
	}

private:

};


// set������������޸�---�Զ�����������
void test_set7()
{
	MyPerson p1("����", 23);
	MyPerson p2("����", 27);
	MyPerson p3("�ŷ�", 25);
	MyPerson p4("����", 21);

	// �Զ����������������ָ��������򣬷������ͻᱨ����Ϊ����ʱ��֪����ô����
	// �����ڴ��� set�Զ����������� ʱ��Ӧ��ָ�� �º����������
	set<MyPerson, MyPersonCompare> s1;
	
	s1.insert(p1);
	s1.insert(p2);
	s1.insert(p3);
	s1.insert(p4);

	// ��ӡ
	for (set<MyPerson, MyPersonCompare>::iterator i = s1.begin(); i != s1.end(); i++)
	{
		cout << "������" << i->m_name << " ���䣺" << i->age << endl;
	}
}


// 32
int main32() {
	// ʹ��set������ʱ�����в����Ԫ�ض��ᱻ�Զ����򣬵ײ��Ƕ�����ʵ�ֵ�
	// set���������������ظ���Ԫ�أ�mutiset�������ظ�Ԫ��
	// test_set1();
	// test_set2();
	// test_set3();
	// test_set4();
	// test_set5();
	// test_set6();
	test_set7();
	return 0;
}