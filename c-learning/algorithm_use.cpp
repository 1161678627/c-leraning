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


// ���õı����㷨
void test_algorithm1()
{
	// 1.for_each����
	
	// 2.transform ��һ�������е����ݰ��˵���һ�������У����˹����п�����һ���º����԰���������һЩ����
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	vector<int> v2;
	v2.resize(v1.size());
	// ���һ�������Ƿº��������������˹����н���ʲô����Ĳ�������ô�º���ֱ��return�Ϳ�����
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

// ���õĲ����㷨
void test_algorithm2()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	// 1.find����û�ҵ�������һ����������û�ҵ�����end
	vector<int>::iterator it = find(v1.begin(), v1.end(), 3);
	if (it != v1.end())
	{
		cout << "�ҵ�Ԫ��" << *it << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
	// ���Զ�����������
	Personp111 p1("aaa", 20);
	Personp111 p2("bbb", 30);
	Personp111 p3("ccc", 40);
	Personp111 p4("ddd", 50);
	vector<Personp111> v2;
	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	// �Զ����������� find ��֪������ô�Աȣ���ô��һ�����ǲ�һ��
	// ������Ҫ��Person�������� == �ŵıȽϷ�ʽ
	vector<Personp111>::iterator it2 = find(v2.begin(), v2.end(), p1);
	if (it2 != v2.end())
	{
		cout << "�ҵ���Ԫ�أ�name=" << it2->m_name << ",age=" << it2->m_age << endl;
	}
	else
	{
		cout << "û���ҵ�Ԫ��" << endl;
	}

	// 2.find_if��ʹ��һ���º���ȥ������������ �����������ǵ�һ������ͻ᷵�أ�ֻ����һ����������û�ҵ��ͷ���end
	it2 = find_if(v2.begin(), v2.end(), GreatFive());
	if (it2 != v2.end())
	{
		cout << "�ҵ�������������Ԫ�أ�name=" << it2->m_name << ",age=" << it2->m_age << endl;
	}
	else
	{
		cout << "û���ҵ�����������Ԫ��" << endl;
	}


	// �������ڣ��ظ���Ԫ��,�ҵ��˵��������ص�һ���ظ�Ԫ�ص�λ�ã�û�ҵ�����end
	v1.push_back(4);
	it = adjacent_find(v1.begin(), v1.end());
	if (it != v1.end())
	{
		cout << "�ҵ��ظ�����Ԫ�أ�" << *it << endl;
	}
	else
	{
		cout << "û���ҵ������ظ�Ԫ��" << endl;
	}


	// ����ָ��Ԫ���Ƿ����,���� bool���ҵ�Ϊ�棬�����,���Ǳ��������򣨲���ʲô���������ݴ������������ľ��У��������в�,�õ��Ƕ��ַ�����
	bool ret = binary_search(v1.begin(), v1.end(), 5);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û�ҵ�" << endl;
	}
	// ������������У����δ֪��������Դ����ַ�ԭ���Լ���һ��


	// ͳ��Ԫ�ظ��� count
	// 1.ͳ��������������
	int num = count(v1.begin(), v1.end(), 4);
	cout << "4һ���У�" << num << endl;
	// 2.ͳ���Զ�����������---��Ҫ���������� -- ��
	num = count(v2.begin(), v2.end(), p4);
	cout << "p4һ���У�" << num << endl;


	// ������ͳ��Ԫ�ظ���
	num = count_if(v1.begin(), v1.end(), GreatThree());
	cout << "v1�д����������ָ����ǣ�" << num << endl;
	// �����Զ�����������Ҳ��һ����ԭ������һ���º�������
}



// ���õ������㷨
void test_algorithm3()
{
	// 1.sort
	// sort(iterator beg, iterator end, _Pred);
	// Ĭ���������Ҫ�Զ���������򣬻��߶��Զ��������򣬴���º������ƾͿ����ˣ�ǰ�永���Ѿ��кܶ���
	// Ҳ���Ժ� functional �е� greater<int>() ��ϣ��޸�Ϊ��������
	

	// 2.random_shuffle-ϴ��   ָ����Χ�ڵ�Ԫ�������������
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

	// 3.merge-����Ԫ�غϲ������洢����һ������, ע��: ��������������**�����**,�Ҷ��������򡢽��򣬺ϲ��������Ҳ������ģ���������ᱨ��
	vector<int> v2;
	for (int i = 0; i < 5; i++)
	{
		v2.push_back(i+1);
	}

	sort(v1.begin(), v1.end());
	// Ŀ������
	vector<int> v3;
	v3.resize(v1.size()+v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	for (int i = 0; i < (v1.size() + v2.size()); i++)
	{
		cout << v3[i] << ' ';
	}


	// 4.reverse-��ת�����е�Ԫ�أ�ԭ�ط�ת
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


// ���õĿ������滻�㷨
void test_algorithm4()
{
	//-`copy`                      // ������ָ����Χ��Ԫ�ؿ�������һ������
	//- `replace`                // ��������ָ����Χ�ľ�Ԫ���޸�Ϊ��Ԫ��
	//- `replace_if `          // ������ָ����Χ����������Ԫ���滻Ϊ��Ԫ��
	//- `swap`                     // ��������������Ԫ��

	// 1.copy---����Ҫ�������������㷨���ܶ�ʱ�� = ��ֵ�����߿������캯�����ܽ����
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}
	// ����ʱ��v2ҲҪ��ǰ�Ŀ��ٿռ�
	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(), v1.end(), v2.begin());


	// 2.replace
	v2.push_back(20);
	v2.push_back(20);
	v2.push_back(20);
	// �Ὣ���е�20���滻Ϊ2000
	replace(v2.begin(), v2.end(), 20, 2000);
	// myPrint���Ҫ����º������� ���� () ����
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;


	// 3.replace_if
	// �����ڵ���1000�Ķ��滻Ϊ30-���÷º���������() ����bool��������һԪν��
	replace_if(v2.begin(), v2.end(), Great30(), 30);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;

	
	// 4.swap  ����������������ͬ���͵ģ����ܿ���������  �����Ƿ�Ҫ��һ�£���Ҫ���������ԺͿ���������
	vector<int> v3;
	swap(v2, v3);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
	for_each(v3.begin(), v3.end(), myPrint);
	cout << endl;
}



// ���������㷨����С���㷨��ʹ��ʱ������ͷ�ļ�Ϊ `#include <numeric>
void test_algorithm5()
{
	vector<int> v1;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
	}

	// ����㷨accumulate�� ���һ������Ϊ����ʼ���ۼ�ֵ
	int total = accumulate(v1.begin(), v1.end(), 0);
	cout << "�ۼӺ�Ľ��Ϊ��" << total << endl;

	vector<int> v2;
	// resizeĬ�����0
	v2.resize(10);
	// fill ����㷨������������䣬����������Ϊ���ֵ
	fill(v2.begin(), v2.end(), 100);
	for_each(v2.begin(), v2.end(), myPrint);
	cout << endl;
}


// ���õļ����㷨
void test_algorithm6()
{
	//- `set_intersection`          // �����������Ľ���
	//- `set_union`                // �����������Ĳ���
	//- `set_difference `          // �����������Ĳ

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

	// ������꽻��������󣬶��Ƿŵ�һ���µ�������ģ������Ҫ�½�һ��Ŀ������
	// Ŀ������Ҫ���ٶ��ռ��أ�---�����������������ȡС��size����˿���ô��

	vector<int> v3;
	v3.resize(v1.size() > v2.size() ? v2.size() : v1.size());	// min(v2.size(),v1.size())����
	// ��ȡ����---����һ��������������v3�в���ĩβ�ķ��صĵ�����
	// ��ȡ�������������ϱ����� ��������
	vector<int>::iterator itend = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
	// ������ʱ�򣬱������صĵ���������
	for_each(v3.begin(), itend, myPrint);
	cout << endl;


	// �󲢼����������������Ҳ�������������в���
	vector<int> v4;
	v4.resize(v1.size() + v2.size());
	itend = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v4.begin());
	for_each(v4.begin(), itend, myPrint);
	cout << endl;


	// ���������ϵĲ---Ҫ����˭��˭�Ĳ����˭Ϊ������
	vector<int> v5;
	v5.resize(v1.size());	// ��˭Ϊ���������Ϳ��ٿռ�Ϊ˭�Ĵ�С����ȻҲ����Ϊ��ʡ�£�ֱ�ӿ�������������sizeΪ���ٿռ䣬max��Ҫ����algorithmͷ�ļ�
	itend = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v5.begin());	// ���������˭Ϊ�����أ������ȴ��룬�����е�������v1
	for_each(v5.begin(), itend, myPrint);
	cout << endl;
}



int main37() {
	
	/*`<algorithm > `������STLͷ�ļ�������һ������Χ�漰���Ƚϡ� ���������ҡ��������������ơ��޸ĵȵ�
	* `<numeric > `�����С��ֻ��������������������м���ѧ�����ģ�庯��
	* `<functional > `������һЩģ����, ����������������*/

	// test_algorithm1();
	// test_algorithm2();
	// test_algorithm3();
	// test_algorithm4();
	// test_algorithm5();
	test_algorithm6();
	return 0;
}