#include "swap.h"

// 开始写函数定义
void swap(int num1, int num2) {
	cout << "输入的num1 和 num2 的值依次为：" << num1 << "\t" << num2 << endl;
	int temp_num = num2;
	num2 = num1;
	num1 = temp_num;
	cout << "交换后num1的值为：" << num1 << endl;
	cout << "交换后num2的值为：" << num2 << endl;
}