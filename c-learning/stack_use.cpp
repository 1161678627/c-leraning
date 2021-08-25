#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int main29(){

	// 栈：先进后出，不允许有遍历操作，想看值就必须pop，但是可以查看是否为空，以及size
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);

	// 只要栈不为空就查看栈顶，并且出栈
	while (!s.empty())
	{
		cout << "栈顶元素为：" << s.top() << endl;
		// 出栈
		s.pop();	// 注意pop没有返回值，使用top获取栈顶元素
	}
	cout << "栈的size为：" << s.size() << endl;

	return 0;
}