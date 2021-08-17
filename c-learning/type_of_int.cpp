#include<iostream>
using namespace std;

int main1() {

	// 整形
	// 1 short   取值范围 -32768,+32768-1， -2^15,+2^15-1 ,越界后 从最小的开始给上走
	short num1 = 10;
	// 2 int	取值范围 -2^31
	int num2 = 10;
	// 3 long	取值范围 -2^31
	long num3 = 10;
	// long num3 = 100;	一个变量仅能初始化一次
	// 4 long long	取值范围 -2^63
	long long num4 = 10;
}