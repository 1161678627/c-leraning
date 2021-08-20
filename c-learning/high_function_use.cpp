#include<iostream>
using namespace std;

// 函数的声明 和 实现只能有一个带默认参数，因为如果两个都带默认参数的话，编译器不知道该跟随哪个了
// 最好给函数的声明带默认参数，因为函数的实现如果在main函数下面的话，函数的默认参数在main执行的时候编译器还没有见到
// 会不认这个默认参数的，当作没有，函数的实现带默认参数必须把函数 定义在 调用位置之前！ 建议在函数的声明出加默认参数
int add_func(int a, int b = 10);


// 函数的占位参数，就是定义一个参数类型 ，但是不给他形参变量名称，这样这个参数在函数内部就没法使用
// 但是调用这个函数时必须传入这个参数才能调用，符合语法，因此叫做占位参数
int sub_func(int a, int) {
	return a - 10;
}
// 占位参数也可以有默认参数
int sub_func1(int a, int = 10) {
	return a - 10;
}

int div_func(int a, int b) {
	return a / b;
}
// 函数的重载返回值可以不同
double div_func(int a, double b) {
	return a / b;
}


// 函数的引用重载
void func(int& a) {
	cout << "int& a调用" << endl;
}

void func(const int& a) {
	cout << "const int& a调用" << endl;
}


// 函数的默认参数重载
void func2(int& a) {
	cout << "int& a, int b = 10调用" << endl;
}

// 这两个重载就差了个默认参数
void func2(int& a, int b = 10) {
	cout << "int& a, int b = 10调用" << endl;
}


int main20() {
	
	// 函数的高阶特性
	// 1 函数的默认参数
	int res = add_func(10);
	cout << "a+b=" << res << endl;

	// 想调用这个占位参数必须传两个值
	res = sub_func(10, 10);
	// 带默认参数的占位参数，就可以不传第二个参数了，默认的会替补上
	res = sub_func1(10);


	// 函数的重载
	// 条件 1、必须在同一作用域下 2、函数名相同 3、函数的参数-个数不同、类型不同、顺序不同等需要满足一个
	// 注意函数的返回值不同不能作为重载条件---函数的重载返回值可以不同
	cout << div_func(10, 20) << endl;
	cout << div_func(10, 0.5) << endl;

	// 引用作为函数重载的条件---有坑,首先加const和不加const 的引用 可以作为重载的条件
	// 但是因为两者长得一致，当你传变量作为参数的时候，必定走不加const的函数重载
	int aa = 10;
	func(aa);
	// 如果想走 加const 的重载，得传个常数进去
	func(10);
	const int vv = 10;	// 或者传一个const定义的int进去
	func(vv);


	// 函数重载碰到默认参数的坑---如果两个重载刚好差了一个默认参数时，导致两个重载都能调用，编译器就傻了，出现二义性，因此报错
	// 所以函数的重载最好不要加默认参数
	// func2(aa);	// 报错提示，有多个重载与当前调用匹配

	return 0;
}

int add_func(int a, int b) {
	return a + b;
}