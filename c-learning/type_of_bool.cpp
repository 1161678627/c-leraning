#include<iostream>
using namespace std;
int main5() {
	// ��0���棬���Ը�ֵ�κη�0����	eg.2 "xxx"
	bool flag = true;
	// �ڴ�ӡ��ʱ��������Ϊ1�������Ϊ0
	cout << flag << endl;
	flag = false;
	cout << flag << endl;
	// bool ����ռ��һ���ֽ�
	cout << "bool ������ռ���ڴ�ռ䣺" << sizeof(flag) << "�ֽ�" << endl;
	return 0;
}