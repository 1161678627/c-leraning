#include<iostream>
#include<string>
using namespace std;

int main() {

	// 注意当前方法一个程序仅能读取一行输入！

	//  从键盘读取输入，并复制给某个变量
	// 整型读入并赋值
	//int a;
	//cout << "请输入一个整型数字：" << ends;
	//// 如果输入的类型和a的类型不一致不错报错，但是a的值会有问题
	//cin >> a;
	//cout << "刚才输入的变量是：" << a << endl;

	//字符串类型的读入
	string str1;
	cout << "请输入一个字符串：" << ends;
	// cin 从键盘读取输入，直到摁下回车结束，并将读取到的输入赋值给str1
	cin >> str1;
	cout << "刚才输入的字符串是：" << str1 << endl;
	return 0;
}