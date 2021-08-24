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


// vector�����Ĺ��캯����������һ��vector�ļ��ַ�ʽ
void test_vector5()
{
	// 1.Ĭ�Ϲ��죬�޲ι���
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	myPrint4(v1);
	// 2.ͨ������ķ�ʽ���죬ʵ���Ͼ��Ǵ�������������������������������֮�������
	vector<int> v2(v1.begin(), v1.end());
	myPrint4(v2);
	// 3.n��element�ķ�ʽ���죬ʵ���Ͼ��ǳ�ʼ��n����ͬ��Ԫ��
	vector<int> v3(10, 100);	// ������element
	myPrint4(v3);
	// 4.�������죬ֱ�ӿ���һ�������vector������һ���µĳ���
	vector<int> v4(v3);
	myPrint4(v4);
}

// vector�ĸ�ֵ
void test_vector6()
{
	vector<int>v1;
	// ����һ��һ��push_back֮�⣬������������ֵ
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// ֱ�ӵȺŸ�ֵ
	vector<int> v2 = v1;
	// assign��ֵ,assign�ṩ����������������Ȼ��ǰ�պ󿪵ĸ�ֵ���е�����---��Ϊv1.endָ�����һ��Ԫ��+1�Ŀ����ݣ���˺󿪸պ���ȡ�꣬û����
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	myPrint4(v3);
	// assign��ֵ����ֵn��element
	v3.assign(3, 100);		// ��ֵ��������������ֱ�Ӹ������ϵ�ԭ������
	myPrint4(v3);
}

// vector�������ʹ�С
void test_vector7()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// 1.�鿴�����Ƿ�Ϊ��,���Ϊ�շ����棬�����
	if (v1.empty())
	{
		cout << "v1Ϊ��vector" << endl;
	}
	else
	{
		// ��Ϊ�մ�ӡ �����������Ǵ��ڵ�ǰ���size��
		cout << "v1������Ϊ��" << v1.capacity() << endl;
		cout << "v1�Ĵ�СsizeΪ��" << v1.size() << endl;
	}
	// ����ָ��size��С
	v1.resize(15, 0);	// �������ָ����size��ԭ���ĸ������ͻ��ʣ���λ���õڶ����������룬��ָ���ڶ���������Ĭ����0����
	myPrint4(v1);
	v1.resize(3);	// ���resize��ԭ���Ķ̣��ͽضϺ���Ĳ�Ҫ��
	myPrint4(v1);
}

// �����ɾ��
void test_vector8()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// push_back����β����������
	}
	// βɾ��һ��ֻɾ��һ��β������
	v1.pop_back();
	myPrint4(v1);
	// ��������
	v1.insert(v1.begin(), 1000);	// ����Ҫ�����ǵ�����
	myPrint4(v1);
	// ������һ�β�����ͬ��element
	v1.insert(v1.begin(), 3, 500);	// ����3��500
	myPrint4(v1);

	// ����
	v1.erase(v1.begin());	// ����������λ�õ�Ԫ�أ�ֻɾ��һ��Ԫ��
	v1.erase(v1.begin(), v1.end());		// erase�ṩ �����Ƴ��ķ�ʽ������ṩbegin �� end����ô�������vector�ˣ�ͬclear

	// ���
	v1.clear();
	myPrint4(v1);
}

// ���ݴ�ȡ��������string����һ��
void test_vector9()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// push_back����β����������
	}
	// �±��ȡԪ��
	cout << "��2��Ԫ���ǣ�" << v1[1] << endl;
	// at��ȡԪ��
	cout << "��3��Ԫ���ǣ�" << v1.at(2) << endl;
	// ��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ���ǣ�" << v1.front() << endl;
	// ��ȡ���һ��Ԫ��
	cout << "��һ��Ԫ���ǣ�" << v1.back() << endl;
}


// vector�����Ļ���
void test_vector10()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// push_back����β����������
	}
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(10 - i);
	}
	// ����
	// ����v1��0-9.v2��10-1
	v1.swap(v2);
	myPrint4(v1);	// ����v1�� 10-1
	myPrint4(v2);

	// ������ʵ����;�ǣ����������ڴ�ռ䣬��Ϊһ��ʼ���һ��vector�������˺ܶ����ݣ�size�ܴ󣬵����ǰ���resizeС�Ժ�
	// ��Ȼ���ݻ�ضϣ�size���С�����������᲻��С������֮ǰ��ô����ͻ��˷��ڴ���
	// ����Ҫ��С v1������Ϊv1��size��ִ���������伴��
	vector<int>(v1).swap(v1);
}


// vectorԤ���ռ�
void test_vector11()
{
	// vector �� �䳤�ģ�һ��ʼ���䳤�ȿ��ܲ�������ʹ�õĹ����У����ᶯ̬���ӳ��ȵģ��������ڴ濪��
	vector<int> v1;
	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v1.push_back(i);	// push_back����β����������
		if (p != &v1[0])	// һ��ʼָ��v1����Ԫ�ص�ַ����v1��չ�ڴ�ʱ���϶���������һ���ط�����һ���µĴ��vector��Ȼ���ԭ�������ݶ�copy��ȥ���ͷ�ԭ����vector
		{					// ������vector���׵�ַ�ͻ�ı䣬����ÿ���ı�һ�Σ��ͼ�¼һ��++���Ϳ��Լ�¼��չ�ڴ�Ĵ�����
			num++;
			p = &v1[0];
		}
	}
	cout << "v1һ����չ��" << num << "���ڴ�" << endl;


	// ���������ڴ������ݲ�������ʱ�����ڲ��ϵؿ����µĿռ䣬���ܻ�Ч�ʵͣ���˵�����֪���������ܴ��ʱ�򣬿���ֱ��ָ��һ��ܴ�Ŀռ䣬��ȥ��̬����
	vector<int> v2;
	// ע�⣺reserveԤ���Ŀռ䣬û������֮ǰҲ�ǲ��ܷ��ʵģ�ֻ�з������ݲ��ܷ��ʣ�ֻ��һ���Կ��ٺܴ�Ŀռ�Ԥ���ţ��ܷ��ʲ������ǿ����û�浽λ����
	v2.reserve(100000);
	int num2 = 0;
	int* p2 = NULL;
	for (int i = 0; i < 100000; i++)
	{
		v2.push_back(i);	// push_back����β����������
		if (p2 != &v1[0])	// һ��ʼָ��v1����Ԫ�ص�ַ����v1��չ�ڴ�ʱ���϶���������һ���ط�����һ���µĴ��vector��Ȼ���ԭ�������ݶ�copy��ȥ���ͷ�ԭ����vector
		{					// ������vector���׵�ַ�ͻ�ı䣬����ÿ���ı�һ�Σ��ͼ�¼һ��++���Ϳ��Լ�¼��չ�ڴ�Ĵ�����
			num2++;
			p2 = &v1[0];
		}
	}
	cout << "v2һ����չ��" << num2 << "���ڴ�" << endl;	// ֻ��չһ�Σ���ʡ��

}



// 25
int main25() {
	
	//test_vector();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	//test_vector7();
	//test_vector8();
	//test_vector9();
	//test_vector10();
	test_vector11();
	return 0;
}