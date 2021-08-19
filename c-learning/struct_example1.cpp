#include<iostream>
#include<string>
using namespace std;

// 定义学生结构体，姓名，分数
struct Student
{
	string name;
	int score;
};

// 定义老师结构体，老师姓名，五个学生
struct Teacher
{
	string name;
	Student stus[5];
};


void make_value(Teacher* p, int length);

int main16() {

	string nameseed = "ABCDE";
	nameseed = nameseed + "ssss";
	cout << nameseed[1] << nameseed.size() << endl;

	// 定义三位老师的结构体数组
	Teacher teas[3];
	int length = sizeof(teas) / sizeof(teas[0]);
	make_value(teas, length);

	return 0;
}

// 传入老师数组的指针进行赋值,这里既可以把形参定义为 指针，也可以把形参定义为 数组，在使用的时候是一样用的
// void make_value(Teacher t_array[], int len)
void make_value(Teacher* p, int length) {
	for (int i = 0; i < length; i++)
	{	
		cout << "请输入第" << i + 1 << "个老师的姓名：";
		cin >> p[i].name;
		for (int j = 0; j < 5; j++)
		{
			cout << "请输入第" << i + 1 << "个老师，第：" << j + 1 << "个学生的姓名：";
			cin >> p[i].stus[j].name;
			cout << "请输入第" << i + 1 << "个老师，第：" << j + 1 << "个学生的成绩：";
			cin >> p[i].stus[j].name;
		}
	}
}