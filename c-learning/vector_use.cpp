#include<iostream>
using namespace std;
#include<vector>	// ʹ��vector����ǰҪ������Ӧ��ͷ�ļ�����������Ҳ��һ����
#include<algorithm>

void myPrint(int p)
{
	cout << p << endl;
}

// ʹ��vector���������c++�Դ����������ͣ�һ������ֻ��ͬʱ��һ���������ͣ�
void test_vector()
{
	// ʹ��vector���������c++�Դ����������ͣ�һ������ֻ��ͬʱ��һ���������ͣ�
	vector<int> v;	// ����һ�����int���͵����� v
	// �������д������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	// ��������Ҫȡ�������е�Ԫ�ص�ʱ��Ϳ���ʹ�õ�����������
	// ÿһ�����������Լ��ĵ����������������ڱ��������е�����Ԫ��
	vector<int>::iterator pBegin = v.begin();	// vector<int>::iterator ʹ�����ַ�ʽ���� vector<int> ���͵ĵ�������ʵ���ϵ�������һ��ָ�룬v.begin()ָ��v�е�һ��Ԫ��
	vector<int>::iterator pEnd = v.end();	// v.end() ָ������������һ��Ԫ�ص���һ��Ԫ��

	// Ȼ��Ϳ��Կ�ʼ���� ����v�е�������
	while (pBegin != pEnd)	// ����ʼ������++�����һ��Ԫ�ص���һ��Ԫ�أ�˵���������ˣ����˳���
	{
		cout << *pBegin << endl;
		pBegin++;	// pBegin���Կ���һ��ָ��������ʹ��++����
	}

	// ������ʹ��forѭ������
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
	{
		cout << *i << endl;
	}

	// ��Ȼc++ stl���ṩ��һ�ֱ�׼�ı����㷨��������Ҫ���� algorithm ͷ�ļ�
	// �ṩ������ begin �� end�������Լ���Ҫ��������Ԫ�ؽ��еĲ����������ɣ��ú��������ǵ�һ������Ԫ�أ��������;��Ƕ�������ʱ�Ĳ������ͣ�
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
	cout << "������" << p.m_name << " ���䣺" << p.m_age << endl;
}

// ʹ��vector��������Զ������������--person��
void test_vector2()
{
	// ʹ��vector��������Զ������������--person��
	Personxxx p1("zhangsan", 18);
	Personxxx p2("lisi", 19);
	Personxxx p3("wangwu", 20);
	Personxxx p4("zhaoliu", 21);

	vector<Personxxx> v;	// ����Person���͵�����
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	// ���������е�����
	for_each(v.begin(), v.end(), myPrint1);
}


void myPrint2(Personxxx* p)
{
	// ����ָ������
	cout << "������" << p->m_name << " ���䣺" << (*p).m_age << endl;
}
// ʹ��vector��������Զ������������--person���ָ��
void test_vector3()
{
	// ʹ��vector��������Զ������������--person���ָ��
	Personxxx p1("zhangsan", 18);
	Personxxx p2("lisi", 19);
	Personxxx p3("wangwu", 20);
	Personxxx p4("zhaoliu", 21);

	vector<Personxxx*> v;	// ����Person����ָ�������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	// ���������е�����
	for_each(v.begin(), v.end(), myPrint2);
}

// ʹ��ѭ����Ƕ�������з���ֵ��ע������Ҫ�������òſ��ԣ�����ֵ���ݵĻ����Ǹ������������ֵ�ˣ�ʵ����v��û����ֵ
// ִ���޸ĵ�ʱ����ô����ã�ִ�д�ӡ����ֵ����
void mySetValue(vector<int>& v)
{
	for (int i = 0; i < 4; i++)
	{
		cout << "����ֵ��" << i << endl;
		v.push_back(i);
	}
}

void myPrint4(vector<int> v)
{
	for_each(v.begin(), v.end(), myPrint);
}


// ������Ƕ������
void test_vector4()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<vector<int>> v4;		// ����Ƕ������������ŵ������� ���� ����
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