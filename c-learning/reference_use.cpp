#include<iostream>
using namespace std;

// 相当于给实参a，b开辟了别名，此时形参 'a','b'也指向 实参所在的内存，所以相互干扰
// 相当于 参数传递时执行了，int& 'a' = a; int& 'b' = b; 'a'表示形参
void swap(int& a, int& b) {
	int temp_num = b;
	b = a;
	a = temp_num;
}


// 引用作为函数返回值
int& test() {
	int a = 10;
	return a;	// 定义函数时指定返回值类型为引用后，直接返回变量，就自动是返回变量的引用了，但是接收时需要用 引用数据类型 接收
}


// 函数的调用可以作为左值
int& test2() {
	static int b = 10;	// 指定为静态变量，存放在全局区，只有程序退出时，该变量才会释放内存
	return b;	// 定义函数时指定返回值类型为引用后，直接返回变量，就自动是返回变量的引用了，但是接收时需要用 引用数据类型 接收
}


void printValue(const int& b) {
	cout << b << endl;
	// 因为形参引用被const修饰，所以他不能被作为左值修改，所以b就脱离了和实参的联系，安全
	// b = 10;
}


int main19() {
	// 引用实际上就是给 内存中的变量起一个别名，两个名称都指向同一块内存，互相干扰
	int a = 10;
	cout << a << endl;
	// 使用 数据类型+取地址符 别名 = 原始名;可以将别名和原始名指向同一块内存空间
	// 注意 1、引用必须初始化 int& b;不合法 2、引用指定后不可以重新指定新的引用 3、引用指定后的 别名 = xxx;都只是赋值操作了
	int& b = a;
	cout << b << endl;

	b = 20;
	cout << a << endl;
	cout << b << endl;


	// 引用一个很重要的用途就是 作为函数的参数传递，值传递不能修改实参的值，指针传递晦涩，引用传递简单好用
	// 使用之前做过的swap案例讲解
	int c = 30;
	swap(a, c);
	cout << a << "\t" << c << endl;


	// 引用做函数的返回值
	// 注意 1.不要返回局部变量的引用  
	int& num = test();	// 定义一个引用格式类型 接收函数返回的引用
	// 此时 num指向 test 函数中的局部变量 a 的内存，但是test函数已经结束了，
	// 因此a的内存只会被保留一次，这时候我们输出的第一次 num 值和a是一样的，但是再用一次就会乱码,类似局部变量的地址指针作为返回值
	cout << num << endl;
	cout << num << endl;

	// 注意 2.函数的调用可以作为左值
	// 实际上引用作为函数返回值的时候，是返回了一个变量 b，变量b自然可以作为左值，重新赋值了,相当于直接给静态变量 赋值 1000
	// b = 1000;
	test2() = 1000;
	cout << test2() << endl;


	// 引用的本质实际上是一个 指针常量， int* const ref = &a;	因此引用的指向不能被修改，但是值可以改。
	// 此时的ref是一个指针，但是当我们赋值的时候 ref = 20;  解释器发现ref是一个引用，所以自动解引用为 *ref = 20; 实现了引用的修改
	

	// 引用还有一个问题是，引用和原名相互干扰，为了防止某些函数误操作，传入引用作为参数时，可以加入const修饰 引用参数为 不可修改
	printValue(a);

	return 0;
}