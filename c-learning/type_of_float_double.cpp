#include<iostream>
using namespace std;
int main3() {
	// Ĭ����������һ��С�������۾��ȣ�������ʾ6λ��Ч����
	// ������ float,һ���ٸ������ȱ�����ֵʱ�����С��������� f����־��С���ǵ����ȣ����������Ĭ�Ͻ�С������Ϊ˫�������ͣ�����ֵ��num1ʱ������ǿ��ת��Ϊ������
	float num1 = 3.14f;
	// ˫���� double
	double num2 = 3.14;
	cout << num1 << endl;
	cout << num2 << endl;

	// ͳ��float �� double ռ�õ��ڴ�ռ�
	cout << "doubleռ�õ��ڴ�ռ�Ϊ��" << sizeof(double) << endl;	// 4�ֽ�
	cout << "floatռ�õ��ڴ�ռ�Ϊ��" << sizeof(float) << endl;		// 8�ֽ�

	// ��ѧ������ 3e2	��ѧ��������ʾ������Ĭ�϶��� double ���͵�С������ֵ��float���Լ���f��׺�������ǿתΪfloat��intҲһ������ǿת
	float num3 = 3e2;
	cout << num3 << endl;
	float num4 = 3e-2;
	cout << num4 << endl;
	int num5 = 3e3;
	cout << num5 << endl;
}