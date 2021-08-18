#include<iostream>
using namespace std;
int main5() {
	// 非0即真，可以赋值任何非0的数	eg.2 "xxx"
	bool flag = true;
	// 在打印的时候真就输出为1，假输出为0
	cout << flag << endl;
	flag = false;
	cout << flag << endl;
	// bool 类型占用一个字节
	cout << "bool 类型所占的内存空间：" << sizeof(flag) << "字节" << endl;
	return 0;
}