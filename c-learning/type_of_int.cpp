#include<iostream>
using namespace std;

int main() {

	// 整形
	// 1 short 2个字节  取值范围 -32768,+32768-1， -2^15,+2^15-1 ,越界后 从最小的开始给上走
	short num1 = 10;
	// 2 int 4个字节	取值范围 -2^31
	int num2 = 10;
	// 3 long 4个字节	取值范围 -2^31
	long num3 = 10;
	// long num3 = 100;	一个变量仅能初始化一次
	// 4 long long 8个字节	取值范围 -2^63
	long long num4 = 10;

	// 可以使用 sizeof 求出数据类型占用的内存大小,可以直接传数据类型，也可以传实例化变量
	// 返回值为 字节数 2 4 6 8
	cout << "short 占用的内存空间大小为：" << sizeof(short) << endl;
	cout << "short 占用的内存空间大小为：" << sizeof(num1) << endl;
	
	return 0;
}