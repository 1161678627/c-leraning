#include<iostream>
using namespace std;

// 常量的定义 #define,在文件头部声明
#define Day 7
// 使用const 标记变量为 常量，const定义一般写在函数内
const int month = 24;
// month = 10;	修改常量会提示报错

int main1() {

	cout << "一周一共有：" << Day << "天" << endl;
	// 变量的定义及赋值
	int a;
	a = 10;
	int b = 10;
	float sum = a + b;
	cout << "a + b = " << sum << endl;
	// cout << "hello world" << endl;
	system("pause");
	return 0;
}