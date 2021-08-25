#include<iostream>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

// ��ӡ
void myPrint(const list<int>& l)
{
	for (list<int>::const_iterator i = l.begin(); i != l.end(); i++)	// ֻ����ʽʱ��Ӧ����const_iterator���������
	{
		cout << *i << ' ';
	}
	cout << endl;
}



// list�Ĺ��캯��
void test_list1()
{
	// Ĭ�Ϲ���
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	myPrint(l1);

	// ���乹��
	list<int> l2(l1.begin(), l1.end());
	myPrint(l2);

	// ��������
	list<int> l3(l2);
	myPrint(l3);

	// n��element
	list<int> l4(10, 1000);
	myPrint(l4);
}

// list �ĸ�ֵ�ͽ���
void test_list2()
{
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	list<int> l2;
	// ʹ�õȺŸ�ֵ
	l2 = l1;
	myPrint(l2);
	// ʹ��assign��ֵ���������Ķ���࣬assign��list�����еķ���Ҳһ��
	list<int> l3;
	l3.assign(l2.begin(), l2.end());
	myPrint(l3);
	list<int> l4;
	l4.assign(10, 100);
	myPrint(l4);
	
	// ����---ֱ�ӽ���������Ҫָ������ֵ
	l3.swap(l4);
	myPrint(l3);
	myPrint(l4);
}

// list�����е�size��resize����
void test_list3()
{
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	cout << "l1��sizeΪ��" << l1.size() << endl;
	cout << "l1�Ƿ�Ϊ�գ�" << l1.empty() << endl;
	// resize������������һ����������resize ��0�������Լ�ָ����ʲô
	// ���ˣ��ͽض�
	l1.resize(10, 100);
	myPrint(l1);
	l1.resize(2);
	myPrint(l1);
}

// list�Ĳ����ɾ������---���˲��롢ɾ�����м�����ɾ��
void test_list4()
{
	//* β��-- - push_back
	//* βɾ-- - pop_back
	//* ͷ��-- - push_front
	//* ͷɾ-- - pop_front
	//* ����-- - insert
	//* ɾ��-- - erase
	//* �Ƴ�-- - remove
	//* ���-- - clear

	list<int> l1;
	// ͷ��β��
	l1.push_back(10);
	l1.push_back(20);
	l1.push_front(30);
	l1.push_front(40);
	myPrint(l1);
	// ͷɾ��βɾ
	l1.pop_back();
	l1.pop_front();
	myPrint(l1);

	// insert����
	list<int>::iterator it = l1.begin();
	it++;
	l1.insert(it, 1000);	// �ڵڶ���λ�ò���1000
	myPrint(l1);

	// eraseɾ��
	it = l1.begin();
	l1.erase(++it);
	myPrint(l1);

	// remove---ɾ������ ����Ĳ���
	l1.push_back(1000);
	l1.push_back(1000);
	l1.push_back(1000);
	l1.remove(1000);
	myPrint(l1);

	// ���-clear
	l1.clear();
	myPrint(l1);
}

// list�����ݴ�ȡ��ֻ��front��back��û���±��atȡ���ݣ���֧��������ʣ���Ϊlist���ڴ��в��������ģ�û�������±������ ��һ��Ԫ�ص�λ�ã�������ָ����У�һ��һ����
void test_list5()
{
	list<int> l1;
	for (int i = 0; i < 5; i++)
	{
		l1.push_back(i * 10);
	}
	cout << "l1�ĵ�һ��Ԫ���ǣ�" << l1.front() << endl;
	cout << "l1�����һ��Ԫ���ǣ�" << l1.back() << endl;

	// ��ֱ�ӷ��ʵ�һ��Ԫ�أ�ֻ���� l1.begin() ,Ȼ��һֱ++���ӵ���Ҫ������λ�ã�����l1.end(),Ȼ�� -- Ҳ��
}


bool myCompare(int num1, int num2)
{
	return num1 > num2;
}


// list���ݷ�ת������
void test_list6()
{
	list<int> l1;
	l1.push_back(20);
	l1.push_back(5);
	l1.push_back(4);
	l1.push_back(33);
	l1.push_back(1);
	myPrint(l1);

	// ��ת
	l1.reverse();
	myPrint(l1);
	// ����---���в�֧��������ʵĵ��������������ñ�׼�㷨
	// ���������ڲ����ṩһЩ��Ա���������Ӧ����
	l1.sort();	// Ĭ������
	myPrint(l1);
	l1.sort(myCompare);	// ���Ҫ�������У���Ҫָ����������-����
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
	cout << "������" << p.m_name << "\t���䣺" << p.m_age << "\t��ߣ�" << p.m_height << endl;
}


bool sortPerson(Personppp& p1, Personppp& p2)
{
	// ���������ͬ�򣬰����������
	if (p1.m_age == p2.m_age)
	{
		return p1.m_height > p2.m_height;
	}
	// ������䲻ͬ�������������򼴿�
	else
	{
		return p1.m_age < p2.m_age;
	}
}


// �Զ����������͵�����
void test_list7()
{
	list<Personppp> l1;
	// ׼������
	Personppp p1("����", 35, 175);
	Personppp p2("�ܲ�", 45, 180);
	Personppp p3("��Ȩ", 40, 170);
	Personppp p4("����", 25, 190);
	Personppp p5("�ŷ�", 35, 160);
	Personppp p6("����", 35, 200);

	l1.push_back(p1);
	l1.push_back(p2);
	l1.push_back(p3);
	l1.push_back(p4);
	l1.push_back(p5);
	l1.push_back(p6);

	for_each(l1.begin(), l1.end(), printPerson);

	// ����
	string fgf(50, '-');
	cout << fgf << endl;

	l1.sort(sortPerson);	// ʹ���Զ���ĺ��������Զ����������ͽ�������
	for_each(l1.begin(), l1.end(), printPerson);
}


int main31() {

	// list ����
	// �������ڴ�������ɢ��ʽ�Ľڵ���ڵģ�ÿһ���ڵ����������ָ���򹹳ɣ�������ά������ڵ������ݣ�
	// ָ����ά����һ���ڵ�ĵ�ַ���γ�һ����������Ȼ�ڴ���ɢ������ָ����ʹ�ÿ�����������
	// �ô��ǣ���������λ�ã����Կ��ٵĲ����ɾ������Ϊֻ���޸�ָ�����ָ�򼴿ɣ������ظ����ٿռ�͸���ԭ������
	// ȱ���ǣ�������ʱ����ܱȽ���������ռ�ÿռ���ܴ������飬��Ϊ����ָ����
	// STL���ṩ��������һ�� ˫��ѭ������ÿ���ڵ���һ��nextָ�룬����һ��prevָ��

	// test_list1();
	// test_list2();
	// test_list3();
	// test_list4();
	// test_list5();
	// test_list6();
	test_list7();
	return 0;
}