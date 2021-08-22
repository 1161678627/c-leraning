#include<iostream>
using namespace std;

class Animal
{
public:
	Animal();
	~Animal();
	// 加一个 virtual 关键字，用于晚点指定函数绑定的地址，当需要执行这个speak的方法时候，它会根据传进来的对象，去执行这个对象相应的方法
	virtual void speak() {
		cout << "动物在说话" << endl;
	}


private:

};

Animal::Animal()
{
}

Animal::~Animal()
{
}


class Cat : public Animal
{
public:
	// 动态多态必须要有继承关系--且父类声明了虚函数
	// 子类要重写父类的虚函数，否则编译器无法从父类中指向子类对应的方法（重写和重载不同，重写是子类的函数和父类的函数，声明，参数列表，返回值等都要一样）
	// 当子类传入父类的调用参数（引用、指针）时，就会将这个函数中父类指向的虚函数，全部指向子类去调用
	void speak() {
		cout << "小猫在说话" << endl;
	}

private:

};

// speak函数接收父类 animal的引用，因为父类的speak是虚函数，所以当父类对象（实际上传入的是子类的实例化对象）的虚函数被调用时，该虚函数实际调用的是子类的这个speak方法
void doSpeak(Animal& animal) {
	animal.speak();
}

void test() {
	Cat cat;
	// 此时运行打印的是动物在说话，因为地址早绑定了
	// 1. 这是父类的引用实现多态，doSpeak函数的参数是 父类的引用，但实际上传的子类的实例进去
	doSpeak(cat);	// C++中允许子类和父类之间强转类型

	// 2. 父类的指针指向子类对象,好像必须用堆区开辟内存的方式实例化右值子类才可以
	Animal* cat2 = new Cat;
	// 因为cat2是一个指针，因此需要用 ->访问cat2实例化对象的属性
	cat2->speak();
	// 注意释放堆区内存
	delete cat2;
}

int main22() {

	test();
	return 0;
}