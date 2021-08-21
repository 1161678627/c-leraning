#pragma once
#include<iostream>
using namespace std;

// 类的头文件编写和函数的差不多，只写函数的声明即可，但是类的声明不是一行就写完的
// 其他属性的定义就照常写就行
class Point
{
public:
	void set_X(int x);
	int get_X();
	void set_Y(int x);
	int get_Y();

private:
	int p_x;
	int p_y;
};