#include<iostream>
#include<string>
using namespace std;

// 结构体的教程 https://www.runoob.com/cplusplus/cpp-data-structures.html
// 结构体实际上就是自定义的一种数据类型，类型的集合
// 结构体的声明方式如下
struct Student
{
	// 然后声明结构体的属性
	string name;
	bool sex;	// 0为男，1为女
	int age;
	int score;
};

// 函数声明
void printStu1(Student stu);
void printStu2(Student* p);
void printStu3(const Student* p);

int main15() {
	// 创建结构体的方式, struct Student tom;	其中 struct 关键字在实例化结构体时可以省略，但在声明结构体时不能省略！
	// 1. 实例化结构体对象和属性赋值分开
	Student tom;
	tom.name = "tom";
	tom.age = 22;
	tom.sex = 0;
	tom.score = 100;
	cout << "tom对象的属性如下：" << tom.name << "    " << tom.sex << "    " << tom.age << "    " << tom.score << endl;

	// 2. 实例化结构体对象和属性赋值一起，注意赋值顺序和原始定义顺序保持一致
	Student jack = { "jack", 0, 23, 98 };
	cout << "tom对象的属性如下：" << jack.name << "    " << jack.sex << "    " << jack.age << "    " << jack.score << endl;


	// 结构体数组声明，和数组声明基本一致，可以在初始定义的时候就赋值，也可以在后边自己赋值
	// Student stuArry1[2] = { {"jack", 22, 1, 1}, {"tom", 11, 1, 2} };
	Student stuArry[3];
	for (int i = 0; i < 3; i++)
	{
		stuArry[i].name = "jack";
		stuArry[i].age = 22;
		stuArry[i].sex = 1;
		stuArry[i].score = 100;
	}


	// 结构体指针,即结构体类型的指针，专门指向结构体
	// 结构体实例化后的变量名 jack --- 它的类型就是结构体类型，可以当作int看待
	// cout << typeid(jack).name() << endl;

	// 定义一个 Student类型结构体的指针，指向 jack 对象的地址
	Student* p = &jack;
	// 通过  指针->属性  符号可以访问其指向的结构体中的属性，可以修改或者打印
	p->age = 55;
	cout << "结构体" << p->name << "的年龄是" << p->age << endl;


	// 结构体 嵌套结构体，注意 1.内部结构体的定义应该在外部结构体之前，否则会找不到对象		2.访问内部结构体的属性成员 赋值或者引用时，使用 外部结构体.内部结构体.属性 = xxx;
	// 定义嵌套结构体
	struct Teacher
	{
		string name;
		int age;
		Student student;
	};
	// 实例化嵌套结构体并赋值
	Teacher zk;
	zk.name = "zhaokun";
	zk.age = 23;
	// 可以这样直接给 嵌套结构体赋值一个现有的结构体，也可以  zk.student.name = "xxx" 这样慢慢赋值
	// 这种传递是 deepcopy 传递，jack成员的改变，不会影响zk中的student属性
	zk.student = jack;
	cout << "赵老师的学生名字是" << zk.student.name << endl;
	jack.name = "xxxxx";	// 这里修改了jack.name，zk.student.name不变
	cout << jack.name << endl;
	cout << "赵老师的学生名字是" << zk.student.name << endl;


	// 结构体做函数参数---值传递、指针传递
	// 值传递就是把 jack 这个实例化对象直接传到函数参数里面去，deepcopy引用，函数内部形参和实参修改不关联，函数的参数类型是 Student xxx;
	// 指针传递就是 先实例化一个 Student 类型的指针，指向 jack 对象，然后把这个指针作为函数参数传进去，函数的参数类型是	Student* xxx;
	printStu1(jack);
	cout << "值传递函数外修改后的姓名是" << jack.name << endl;
	printStu2(&jack);
	cout << "指针传递函数外修改后的姓名是" << jack.name << endl;


	// 结构体指针传递作为函数参数时，有可能会被函数内部的操作修改他的属性，但这可能不是我们想要的，
	// 为了避免误触，可以在函数定义参数时 加上const Student* xxx ---这样在这个函数内，该传入结构体只能被读取，不能修改
	// 传指针不传值的原因是，指针就是一个地址，4个字节，而传值要copy一份一模一样的新数据，参数大时，很浪费内存
	printStu3(&jack);


	return 0;
}

// 值传递---传进去之后，就是两份数据了，相互不干扰
void printStu1(Student stu) {
	stu.name = "wogaile";
	cout << "值传递函数内修改后的姓名是：" << stu.name << endl;
}

// 指针传递
void printStu2(Student* p) {
	p->name = "wogaile";
	cout << "指针传递函数内修改后的姓名是：" << p->name << endl;
}

// 指针传递，配合const
void printStu3(const Student* p) {
	// p->name = "wogaile";		只能访问，无法作为左值修改
	cout << "指针传递函数内修改后的姓名是：" << p->name << endl;
}