// �ȵ�������ͷ�ļ�������ȷ����ʲô������Ҫ����
#include "point.h"

void Point::set_X(int x) {
	p_x = x;
	cout << "�ɹ������x��������Ϊ��" << x << endl;
}

int Point::get_X() {
	return p_x;
}


void Point::set_Y(int y) {
	p_y = y;
	cout << "�ɹ������x��������Ϊ��" << y << endl;
}

int Point::get_Y() {
	return p_y;
}