#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main29(){

	// ջ���Ƚ�������������б����������뿴ֵ�ͱ���pop�����ǿ��Բ鿴�Ƿ�Ϊ�գ��Լ�size
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	// ֻҪջ��Ϊ�վͲ鿴ջ�������ҳ�ջ
	while (!s.empty())
	{
		cout << "ջ��Ԫ��Ϊ��" << s.top() << endl;
		// ��ջ
		s.pop();	// ע��popû�з���ֵ��ʹ��top��ȡջ��Ԫ��
	}
	cout << "ջ��sizeΪ��" << s.size() << endl;

	return 0;
}