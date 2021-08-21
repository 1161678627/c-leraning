#pragma once
#include<iostream>
using namespace std;
#include "point.h"

class Circle
{
public:
	void setCr(int r);
	int getCr();
	void setCenter(Point c_c);
	Point getCenter();

private:
	int c_r;
	Point c_center;
};