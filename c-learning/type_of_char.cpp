#include<iostream>
#include<string>
using namespace std;

int main4() {
	// 字符型变量的创建方式,字符需要用单引号表示，且单引号内仅能有一个字符
	char ch1 = 'a';
	cout << ch1 << endl;
	// 字符型变量所占内存大小	1个字节
	cout << sizeof(char) << endl;
	// 查看字符型数据对应的 ascii 码，字符型数据在内存中是以ascii码形式存储的---整数， a=97，A=65
	cout << "a对应的ascii值为:" << int(ch1) << endl;
	cout << "A对应的ascii值为:" << int('A') << endl;


	// 转义字符	\t 水平制表符让制表符+制表符前的字符串共占8个空格，用于对齐输出
	cout << "如何输出完一行之后换行的第一种方案\tendl" << endl;
	cout << "如何输出完一行之后换行的第二种方案\t\\n \n";


	// 字符串类型,C++中有两种风格的字符串声明，字符串声明用双引号
	// 1 c语言风格的字符串,以数组形式定义
	char str1[] = "c语言风格的字符串";
	// 2 c++风格的字符串，以string类型定义
	// 不过需要引入 #include<string> 头文件,但是不引入也可以，因为#include<iostream>，隐式引入了#include<string>了，但是还是建议显式引入一下，避免莫名其妙报错
	string str2 = "C++风格的字符串";

	cout << str1 << endl;
	cout << str2 << endl;
	return 0;
}