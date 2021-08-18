#include<iostream>
using namespace std;
int main3() {
	// 默认情况下输出一个小数，不论精度，都仅显示6位有效数字
	// 单精度 float,一般再给单精度变量赋值时，会给小数后面加上 f，标志该小数是单精度，否则编译器默认将小数定义为双精度类型，当赋值给num1时，进行强制转换为单精度
	float num1 = 3.14f;
	// 双精度 double
	double num2 = 3.14;
	cout << num1 << endl;
	cout << num2 << endl;

	// 统计float 和 double 占用的内存空间
	cout << "double占用的内存空间为：" << sizeof(double) << endl;	// 4字节
	cout << "float占用的内存空间为：" << sizeof(float) << endl;		// 8字节

	// 科学计数法 3e2	科学计数法表示的数字默认都是 double 类型的小数，赋值给float可以加上f后缀，否则会强转为float，int也一样，会强转
	float num3 = 3e2;
	cout << num3 << endl;
	float num4 = 3e-2;
	cout << num4 << endl;
	int num5 = 3e3;
	cout << num5 << endl;
}