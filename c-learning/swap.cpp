#include "swap.h"

// ��ʼд��������
void swap(int num1, int num2) {
	cout << "�����num1 �� num2 ��ֵ����Ϊ��" << num1 << "\t" << num2 << endl;
	int temp_num = num2;
	num2 = num1;
	num1 = temp_num;
	cout << "������num1��ֵΪ��" << num1 << endl;
	cout << "������num2��ֵΪ��" << num2 << endl;
}