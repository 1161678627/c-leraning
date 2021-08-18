#include<iostream>
using namespace std;

int main7() {
	// 加减乘除运算
	// 加减乘不说了没啥
	// 除法说一下，首先避免除0错误，
	// 两整数相除，只会整除，结果为整数
	int a = 10;
	int b = 3;
	cout << a / b << endl;
	// 两小数相除，结果依旧为小数，保持原来的定义类型double，整除也不会变整数类型的
	double c = 0.5;
	double d = 0.25;
	cout << c / d << "\t除完的类型是" << typeid(c/d).name() << endl;
	// 不同类型的两小数相除，会自动转为精度较高的类型，即c的double类型
	float e = 0.25f;
	cout << c / e << "\t除完的类型是" << typeid(c/e).name() << endl;

	// 整数和小数相除，会强转整数为小数去除，结果是一个小数
	cout << a / d << "\t除完的类型是" << typeid(a/d).name() << endl;
	float f = 4.5f;
	cout << a / f << "\t除完的类型是" << typeid(a/f).name() << endl;

	//取余/取模，取余操作也不能避免和0操作，小数无法完成取余操作
	cout << a % b << "\t除完的类型是" << typeid(a%b).name() << endl;


	// 前置递增、递减，后置递增、递减，递增递减都只有 1 
	// 实际上前置和后置的区别就是，先进行 递增/递减操作 还是先进行 (表达式运算)赋值操作；++/--在前面就是前置，就先递增/递减操作，再赋值，反之一样
	// 不论前置后置反正执行完之后 a1 肯定是+1了，区别只是b1能否享受到 a1 的变化
	int a1 = 10;
	int b1 = ++a1;
	cout << b1 << endl;

	// 逻辑运算符，c++除了数字0都为真
	// !a 取反
	// a&&b 同真为真，否则为假
	// a||b 有真则真

	return 0;
}