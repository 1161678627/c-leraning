#include<iostream>
using namespace std;
// 使用自定义头文件函数
#include "swap.h"


// 函数声明，由于c程序是从第一行开始从上给下执行的，因此当我们 被调用函数写在 main 函数上方时，就可以不做特殊声明
// 但是当  被调用函数写在 main 函数下方时，程序在main里面调用它的时候，并不知道它是谁就会报错，因此需要 前置声明下
// 函数的声明可以有多次---因为声明是告诉编译器有这么一个东西，告诉多次无所谓，但是函数的定义只能有一次

// 声明可以不写出形参，只写出返回值类型，传入参数类型即可
int sum(int, int);
// int sum(int num1, int num2);
// int sum(int, int);

int main13() {
	int a = 10;
	int b = 20;
	int c = sum(a, b);
	cout << "相加后的值为：" << c << endl;

	swap(a, b);
	return 0;
}

int sum(int num1, int num2) {
	return num1 + num2;
}


/*
补充函数的分文件编写，实际上函数的分文件编写就是类似于自己写一个 头文件这样的东西，用于导入。
主要用途是使主程序代码结构更加清晰，封装一个函数 一般有2个步骤：
1. 在解决方案资源管理器 中的 头文件文件夹中  创建后缀名为 .h的头文件，并在其中写函数的声明，样本如下
	#include<iostream>
	using namespace std;
	// 写函数声明
	int sum(int, int);

2. 在解决方案资源管理器 中的 源文件文件夹中  创建后缀名为 .cpp的源文件，并在其中写函数的定义，样本如下
	#include "sum.h"	// 该行代码用于关联头文件和对应源文件，不需要再引入其他头文件了，要引入就在 .h文件中引入就行了
	// 开始函数的定义
	int sum(int num1, int num2) {
		return num1 + num2;
	}
这样就可以了，在其他cpp文件中调用该函数时，需要用	#include "xxx.h" 的形式引入，双引号表示该头文件是我们自己编写的
*/