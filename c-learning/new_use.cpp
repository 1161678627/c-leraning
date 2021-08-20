#include<iostream>
using namespace std;

// 栈区返回值保留测试
int* test1() {
	int num1 = 5;
	return &num1;
}

// 堆区返回值保留测试
int* test2() {
	// 利用new 关键字可以将数据开辟到堆区
	// 这里返回的p指针也是局部变量，但是指针存放的地址，是开辟在堆上的数据，new int 这样定义的数据，返回值是该数据存放在堆区的地址
	int* p = new int(10);
	return p;
}

// 堆区开辟和释放数组
int* test3() {
	int* arr = new int[10];	// 好像不支持直接给堆区数组赋值,如果是 数值就可以用 new int(10) 直接赋值10
	for (int i = 0; i < 10; i++)
	{
		arr[i] = 100 + i;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	return arr;
}


int main18() {

	// 函数内定义的局部变量存放在  栈区，函数执行完毕后这个变量就会在内存中销毁掉，因此不能返回局部变量的地址
	// 如果返回的是 数值，则需要在外部用一个新变量接收
	int* num1 = test1();
	cout << *num1 << endl;	// 系统会保留一次这个栈区地址的数据，下次在访问这个地址就是乱码了
	cout << *num1 << endl;

	int* num2 = test1();
	int num3 = *num2;	// 如果在系统保留的那次，把这个数据放到一个新开辟的内存里，就可以长久保留了
	cout << num3 << endl;
	cout << num3 << endl;

	// 如果想在函数结束后返回一个局部变量的地址，则需要将该 局部变量开辟到 堆区 中，堆区的特点是1、程序结束后才会释放；2、可以人工手动释放
	int* p = test2();
	// 此时返回的这个 p 指向堆区
	cout << *p << endl;
	cout << *p << endl;

	// 如果想释放堆区的数据，利用关键字 delete 返回的地址即可
	delete p;
	// 堆区地址释放后，再次访问就是非法报错，会报权限错误
	// cout << *p << endl;


	// 堆区开辟数组
	int* arr = test3();
	// 如果要释放堆区数组，则需要标明 数组
	delete[] arr;	// 只写arr则只会释放数组第一个元素
	return 0;
}