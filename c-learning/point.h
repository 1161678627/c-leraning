#pragma once
#include<iostream>
using namespace std;

// ���ͷ�ļ���д�ͺ����Ĳ�ֻ࣬д�������������ɣ����������������һ�о�д���
// �������ԵĶ�����ճ�д����
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