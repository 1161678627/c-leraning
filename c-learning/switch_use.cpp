#include<iostream>
using namespace std;

// https://www.runoob.com/cplusplus/cpp-switch.html switch ʹ�ù��������ҳ
// һ��switch��ÿ��case��֧����ж������break������������򵱽���һ��case��֧����ִ�����case�е���䣬Ȼ�����ж������case��ֱ�Ӱ���ִ������case�е���䣬ֱ������break
// ��ĳ���� ��֧��ִ�����һ�£����԰�����дΪ������֧ 10��9��ʱ��Ȼ���һ����֧���Բ�дִ����䡣
// default ��֧��ǰ������case��������ʱ��ִ��(��Ȼǰ�������дbreakҲ��ִ�е�default)
int main10() {
	int score;
	cout << "���������Ե�ǰ��Ӱ�����֣�";
	cin >> score;
	cout << "�����õ�Ӱ����" << score << "��" << endl;
	switch (score)
	{
	case 10:
	case 9:
		cout << "����Ϊ��ǰ��Ӱ���ֺܸ�" << endl;
		break;
	case 8:
	case 7:
		cout << "����Ϊ��ǰ��Ӱ����һ��" << endl;
		break;
	default:
		cout << "����Ϊ��ǰ��Ӱ����" << endl;
		break;
	}

	return 0;
}