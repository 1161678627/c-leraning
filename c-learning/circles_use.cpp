#include<iostream>
#include<ctime>		// ��Ϊ����������time����������timeͷ�ļ�
using namespace std;


// ����һ������������ĺ���
int get_random_number(int max) {
	int random_num;
	srand((unsigned int)time(NULL)); //time()��ϵͳʱ���ʼ���֡�Ϊrand()���ɲ�ͬ��������ӡ�
	random_num = rand() % max + 1;
	return random_num;
}

int main11 () {
	// do while ѭ��---����ִ��һ��
	int num = 1;
	do
	{
		cout << "��ǰ����������ǣ�" << num << endl;
		num++;
	} while (num <= 10);


	// ˮ�ɻ�����ʹ�� do while
	for (int i = 100; i <= 999; i++)
	{
		int one, ten, hundred;
		one = i % 10;
		ten = (i % 100 - one) / 10;
		hundred = i / 100;
		int final_num = one * one * one + ten * ten * ten + hundred * hundred * hundred;
		if (final_num == i)
		{
			cout << "�ҵ�ˮ�ɻ�����" << i << endl;
		}
	}


	// while ѭ��
	int random_num = get_random_number(100);
	bool flag = 1;
	while (flag)
	{	
		int temp_num;
		cout << "��������µ����֣�" << ends;
		cin >> temp_num;
		if (temp_num > random_num) {
			cout << "�Բ������µĹ���" << endl;
		}
		else if (temp_num < random_num)
		{
			cout << "�Բ������µĹ�С��" << endl;
		}
		else
		{
			cout << "��ϲ�����¶��ˣ�" << endl;
			flag = 0;
		}
	}

	return 0;
}