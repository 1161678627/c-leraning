#include<iostream>
#include<queue>
using namespace std;

int main30() {

	// 队列queue是一种先进先出的结构，一头只能进入push，一头只能出去pop，队头的数据先出。
	// 队列不允许遍历，因为只有队头和队尾的元素可以供外界访问，遍历必须一直pop

	// 初始化，入队
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	// 只要队列不为空，查看队头和队尾
	while (!q.empty())
	{
		cout << "队头元素为：" << q.front() << endl;
		cout << "队尾元素为：" << q.back() << endl;
		q.pop();
	}
	cout << "队列的大小为：" << q.size() << endl;

	return 0;
}