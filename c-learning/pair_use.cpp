#include<iostream>
#include<string>
using namespace std;

// 33
int main33() {
	// �����ǳɶԳ��ֵ����ݣ���������ֵ��ʱ��Ϳ����ö�����

	// ����
	pair<string, int> p("tom", 20);
	// ȡֵ��ʱ����� firstȡ��һ����secondȡ�ڶ����ͺ���
	cout << "name: " << p.first << " age: " << p.second << endl;

	// ��������������
	pair<string, int> p2 = make_pair("jack", 30);
	cout << "name: " << p2.first << " age: " << p2.second << endl;

	return 0;
}