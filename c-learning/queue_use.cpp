#include<iostream>
#include<queue>
using namespace std;

int main30() {

	// ����queue��һ���Ƚ��ȳ��Ľṹ��һͷֻ�ܽ���push��һͷֻ�ܳ�ȥpop����ͷ�������ȳ���
	// ���в������������Ϊֻ�ж�ͷ�Ͷ�β��Ԫ�ؿ��Թ������ʣ���������һֱpop

	// ��ʼ�������
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	// ֻҪ���в�Ϊ�գ��鿴��ͷ�Ͷ�β
	while (!q.empty())
	{
		cout << "��ͷԪ��Ϊ��" << q.front() << endl;
		cout << "��βԪ��Ϊ��" << q.back() << endl;
		q.pop();
	}
	cout << "���еĴ�СΪ��" << q.size() << endl;

	return 0;
}