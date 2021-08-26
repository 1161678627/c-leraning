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
		count = 0;	// ����ʹ��һ����Ա��¼�Լ���״̬
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
	// ��Ϊ����ֵΪbool����ֻ��һ��������������һԪν��
	bool operator() (int num)
	{
		return num > 5;
	}

private:

};


// һԪν��
void test_pred1() {
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// ǰ���������ǵ��������䣬������������ һ��ν�ʺ���
	// GreatFive() �����ĺ�������Լ����  GreatFive gf; gf();
	// ����ҵ��ˣ�����º���������(ֻҪ����һ�ξͷ��أ���˷��ص�λ��ֻ��һ��)���ͷ���һ��������λ�ã�û�ҵ��ͷ���end������
	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreatFive());
	if (it != v1.end())
	{
		cout << "�ҵ��˴���5������" << *it << endl;
	}
	else
	{
		cout << "û���ҵ�����5������" << endl;
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


// ��Ԫν��
void test_pred2()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	// sortĬ������������
	sort(v1.begin(), v1.end());
	// ���������Ҫ����������Ҫʹ�÷º�����sort�����ذ汾
	sort(v1.begin(), v1.end(), MyCompare());
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}


// �����º���
void test_functional()
{
	// ȡ���º���negate-50ȡ����-50
	negate<int> n;
	cout << n(50) << endl;

	// �ӷ� plus��ʵ����ʱ��ֻ��дһ��int�����ˣ���ΪĬ��ֻ����ͬ�������ݽ������
	plus<int> p;
	cout << p(10, 10) << endl;

	// ���������������
	//* `template<class T > T plus<T>`                //�ӷ��º���
	//* `template<class T > T minus<T>`              //�����º���
	//* `template<class T > T multiplies<T>`    //�˷��º���
	//* `template<class T > T divides<T>`         //�����º���
	//* `template<class T > T modulus<T>`         //ȡģ�º���
	//* `template<class T > T negate<T>`           //ȡ���º���
}


// ��ϵ�º���������С��֮���
void test_functional2()
{
	//*`template<class T > bool equal_to<T>`                    //����
	//* `template<class T > bool not_equal_to<T>`            //������
	//* `template<class T > bool greater<T>`                      //����
	//* `template<class T > bool greater_equal<T>`          //���ڵ���
	//* `template<class T > bool less<T>`                           //С��
	//* `template<class T > bool less_equal<T>`               //С�ڵ���
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	
	// ��������---sortĬ�����������������������Ҫ��������Ҫдһ���º������������������
	// ���ǿ����Լ�дһ���࣬���庯�� bool operator() (int v1, int v2)����дһ���Լ��ķº���
	// ����c++Ҳ������������һ����ϵ�º���������greater<int>()��ʵ����sort�ײ㽵�����У��õľ��� less<int>()С��
	sort(v.begin(), v.end(), greater<int>());
}


// �߼��º���
void test_functional3()
{
	//*`template<class T > bool logical_and<T>`              //�߼���
	//* `template<class T > bool logical_or<T>`                //�߼���
	//* `template<class T > bool logical_not<T>`              //�߼���

	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	// ��v�е����ݰ��˵�v2�У�����ȡ��
	vector<bool> v2;
	v2.resize(v.size());	// �������Ҫ�У�����ᱨ����Ϊv2û�п��ٿռ䣬û��������������
	// ���ö���ʹ��transform,��������Ϊ��ԭʼ�������ʼ����������ֹ�����������˺�������ʼ���������º�������ѡ��
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
}

int main36() {
	// ��������(�º���)��һ��** ��** ������һ������
	// ��������**ʹ�����ص�()ʱ����Ϊ���ƺ������ã�Ҳ��**�º���**

	// 1.����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
	MyAdd myadd;
	cout << myadd(10, 20) << endl;

	// 2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
	MyPrint myprint;
	myprint("hello world");
	cout << "myprint���õĴ����ǣ�" << myprint.count << endl;

	// 3.�������������Ϊ��������---��Ȼ��ͨ����Ҳ����
	do_print(myprint, "xixixixi");


	// ν�ʣ�����bool���͵ķº�����������ص�ʱ�򣬲���һ���ͽ�һԪν�ʣ��������������Ƕ�Ԫν��
	test_pred1();
	test_pred2();


	// �ڽ��������󣨶������������ͳ��õĲ�����c++��Ԥ������ˣ����������ã�---ʹ��ǰ��Ҫ����һ��ͷ�ļ� functional
	// �����º���
	// negate ȡ���º�����һԪ��
	test_functional();

	// ��ϵ�º���
	test_functional2();

	// �߼��º���
	test_functional3();

	return 0;
}