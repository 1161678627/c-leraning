#include "circle.h"

// void setCr(int r);
void Circle::setCr(int r) {
	c_r = r;
	cout << "�ɹ���Բ�İ뾶����Ϊ��" << r << endl;
}

// int getCr();
int Circle::getCr() {
	return c_r;
}

//void setCenter(Point c_c);
void Circle::setCenter(Point c_c) {
	c_center = c_c;
}

// Point getCenter();
Point Circle::getCenter() {
	return c_center;
}