#include<iostream>
using namespace std;

int main() {

	// ����
	// 1 short 2���ֽ�  ȡֵ��Χ -32768,+32768-1�� -2^15,+2^15-1 ,Խ��� ����С�Ŀ�ʼ������
	short num1 = 10;
	// 2 int 4���ֽ�	ȡֵ��Χ -2^31
	int num2 = 10;
	// 3 long 4���ֽ�	ȡֵ��Χ -2^31
	long num3 = 10;
	// long num3 = 100;	һ���������ܳ�ʼ��һ��
	// 4 long long 8���ֽ�	ȡֵ��Χ -2^63
	long long num4 = 10;

	// ����ʹ�� sizeof �����������ռ�õ��ڴ��С,����ֱ�Ӵ��������ͣ�Ҳ���Դ�ʵ��������
	// ����ֵΪ �ֽ��� 2 4 6 8
	cout << "short ռ�õ��ڴ�ռ��СΪ��" << sizeof(short) << endl;
	cout << "short ռ�õ��ڴ�ռ��СΪ��" << sizeof(num1) << endl;
	
	return 0;
}