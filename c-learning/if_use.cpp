#include<iostream>
using namespace std;

int main9() {
	int scores;
	cout << "���������Ŀ��Գɼ���" << ends;
	cin >> scores;
	cout << "������ĳɼ��ǣ�" << scores << endl;

	// ��c���ԵĻ���һ�£�����ע��if �� ����() ֮���пո�,ִ����� {} ����д��()��{}����û�� ;
	if (scores > 600) 
	{
		cout << "��ϲ����������һ��" << endl;
	}
	else if (scores > 500)
	{
		cout << "��ϲ�������˶���" << endl;
	}
	else if (scores > 450)
	{
		cout << "��ϲ������������" << endl;
	}
	else
	{
		cout << "�Բ���������ˣ�" << endl;
	}

	return 0;
}