#include<iostream>
#include<string>
using namespace std;

// ����ѧ���ṹ�壬����������
struct Student
{
	string name;
	int score;
};

// ������ʦ�ṹ�壬��ʦ���������ѧ��
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

	// ������λ��ʦ�Ľṹ������
	Teacher teas[3];
	int length = sizeof(teas) / sizeof(teas[0]);
	make_value(teas, length);

	return 0;
}

// ������ʦ�����ָ����и�ֵ,����ȿ��԰��βζ���Ϊ ָ�룬Ҳ���԰��βζ���Ϊ ���飬��ʹ�õ�ʱ����һ���õ�
// void make_value(Teacher t_array[], int len)
void make_value(Teacher* p, int length) {
	for (int i = 0; i < length; i++)
	{	
		cout << "�������" << i + 1 << "����ʦ��������";
		cin >> p[i].name;
		for (int j = 0; j < 5; j++)
		{
			cout << "�������" << i + 1 << "����ʦ���ڣ�" << j + 1 << "��ѧ����������";
			cin >> p[i].stus[j].name;
			cout << "�������" << i + 1 << "����ʦ���ڣ�" << j + 1 << "��ѧ���ĳɼ���";
			cin >> p[i].stus[j].name;
		}
	}
}