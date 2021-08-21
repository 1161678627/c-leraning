// 先导入该类的头文件，用于确定有什么方法需要定义
#include "point.h"

void Point::set_X(int x) {
	p_x = x;
	cout << "成功将点的x坐标设置为：" << x << endl;
}

int Point::get_X() {
	return p_x;
}


void Point::set_Y(int y) {
	p_y = y;
	cout << "成功将点的x坐标设置为：" << y << endl;
}

int Point::get_Y() {
	return p_y;
}