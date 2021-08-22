#include<iostream>
using namespace std;

// 定义一个抽象父类，用纯虚函数描述制作饮品公用的四个阶段（方法）
class Beverage
{
public:
	// 煮水
	virtual void Boil() = 0;
	// 冲泡
	virtual void Brew() = 0;
	// 倒入杯中
	virtual void PourCup() = 0;
	// 加入辅料
	virtual void PutSomething() = 0;

	// 整合这四步为一个函数，这个函数被完整的继承到子类中即可，其中调用的纯虚函数也会被子类的重写函数替代的
	void makeDrink() {
		Boil();
		Brew();
		PourCup();
		PutSomething();
	}

private:

};

// 开始定义 不用纯虚函数实现的子类
// coffee
class Coffee : public Beverage
{
public:
	// 开始具体的实现抽象类中的虚函数
	virtual void Boil() {
		cout << "煮农夫山泉" << endl;
	}

	virtual void Brew() {
		cout << "冲泡coffee" << endl;
	}
	virtual void PourCup() {
		cout << "倒入星巴克杯子" << endl;
	}
	virtual void PutSomething() {
		cout << "加入奶泡" << endl;
	}

private:

};

// tea
class Tea : public Beverage
{
public:
	// 开始具体的实现抽象类中的虚函数
	virtual void Boil() {
		cout << "煮华山论剑水" << endl;
	}

	virtual void Brew() {
		cout << "冲泡龙井茶" << endl;
	}
	virtual void PourCup() {
		cout << "倒入磨砂杯" << endl;
	}
	virtual void PutSomething() {
		cout << "加入一点茶花" << endl;
	}

private:

};

// 定义一个调用实例化对象制作饮品的函数---这里可以选择 父类的引用传入，也可以选择指针传入，我们当前选择父类指针传入
void doWork(Beverage* beverage) {
	beverage->makeDrink();
	// 当堆区数据用完后，手动释放下---注意这只是释放了堆区指针指向地方的内存，但这个指针变量还有效
	delete beverage;
}


int main23() {

	doWork(new Coffee);	// 在堆区开辟一个 coffee 对象传进去，new 类，返回的是一个指针
	// doWork(new Tea);
	cout << "-------------------------------" << endl;
	// 堆区开辟实例化子类对象和传入分开
	Tea* tea = new Tea;
	// Beverage* tea = new Tea;	这样写也可以，将指针类型提前就声明Beverage，直接就强转了，不用等到在doWork函数传入的时候再强转
	doWork(tea);
	return 0;
}