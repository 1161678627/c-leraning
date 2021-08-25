#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//**deque��˫����������vector�����ˣ�����**
//* vector����ͷ���Ĳ���ɾ��Ч�ʵͣ�������Խ��Ч��Խ��---��Ϊͷ��ʱvector��Ҫ��ͷ�������ݶ������ƶ�һ�Σ����鷳
//* deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻر�vector��
//* vector����Ԫ��ʱ���ٶȻ��deque��, ��������ڲ�ʵ���й�

void myPrint(deque<int>& d)
{
	for (deque<int>::iterator i = d.begin(); i != d.end(); i++)
	{
		cout << *i << " ";	// i��һ��ָ�룬�����ü����õ���ָ�������
	}
	cout << endl;
}

// deque�����Ĺ��캯������vector��������һ��
void test_deque1()
{
	// Ĭ�Ϲ���
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myPrint(d1);

	// ���乹��
	deque<int> d2(d1.begin(), d1.end());
	// ��ֵn��m
	deque<int> d3(10, 100);
	// ��������
	deque<int> d4(d3);
	myPrint(d4);
}


// deque�����ĸ�ֵ����
void test_deque2()
{
	// Ĭ�Ϲ���
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	myPrint(d1);

	// 1.�ȺŸ�ֵ
	deque<int> d2 = d1;
	// 2.assign��ֵ
	deque<int> d3;
	d3.assign(d2.begin(), d2.end());
	// 3.��ֵn��m������assign
	deque<int> d4;
	d4.assign(10, 100);
	myPrint(d4);
}


// deque�����Ĵ�С���Ƿ�Ϊ�գ�resize�ȵȲ���
void test_duque3()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	// ��Сsize
	cout << "d1��sizeΪ��" << d1.size() << endl;
	// dequeû��������������Ϊ�����˶��ܲ��룬�ñ���������ڴ�Ƭ�Σ���������ʱ���ܲ壬���������¿��ٸ�����ڴ������
	// �Ƿ�Ϊ��
	cout << "d1�Ƿ�Ϊ��" << d1.empty() << endl;

	// ����ָ����С---��ԭ������0��䣬����ָ���������
	d1.resize(15, 100);
	myPrint(d1);
	// ��ԭ���̾ͽض�
	d1.resize(5);
	myPrint(d1);
}


// deque�����Ĳ����ɾ��
void test_deque4()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	// ͷ��
	d1.push_front(100);
	// β��
	d1.push_back(99);
	myPrint(d1);
	// ͷɾ
	d1.pop_front();
	// βɾ
	d1.pop_back();
	myPrint(d1);

	// insert����
	d1.insert(d1.begin(), 100);	// ��һ�������ǵ�����
	d1.insert(d1.begin(), 2, 1000);	// ���ذ汾������n��element

	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);

	d1.insert(d1.begin(), d2.begin(), d2.end());	// ���������������
	myPrint(d1);

	// erase����ɾ��
	deque<int>::iterator i = d1.begin();
	i++;
	d1.erase(i);	// ɾ���±�Ϊ1��Ԫ��
	myPrint(d1);
	// erase ����ɾ��
	d1.erase(d1.begin(), d1.end());	// �൱�����
	myPrint(d1);
	// ���
	d1.clear();
}


// deque���ݴ�ȡ������ [index]��at
void test_deque5()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	for (int i = 0; i < 4; i++)
	{
		// ���������ŷ���Ԫ��
		cout << d1[i] << " ";
	}
	cout << endl;

	cout << d1.at(1) << endl;

	// ͷβԪ�ػ�ȡ
	cout << d1.front() << endl;
	cout << d1.back() << endl;
}

// deque��������
void test_deque6()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	myPrint(d1);
	// ʹ��sort���������������������Ϊ���������� beginָ���sortָ�룬ԭ�ز�����ֱ���޸Ĵ�������������
	sort(d1.begin(), d1.end());
	myPrint(d1);
}


// 27
int main27() {
	// test_deque1();
	// test_deque2();
	// test_duque3();
	// test_deque4();
	// test_deque5();
	test_deque6();
	return 0;
}