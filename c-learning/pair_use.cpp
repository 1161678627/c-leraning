#include<iostream>
#include<string>
using namespace std;

// 33
int main33() {
	// 对组是成对出现的数据，返回两个值的时候就可以用对组了

	// 构造
	pair<string, int> p("tom", 20);
	// 取值的时候就用 first取第一个，second取第二个就好了
	cout << "name: " << p.first << " age: " << p.second << endl;

	// 还可以这样构造
	pair<string, int> p2 = make_pair("jack", 30);
	cout << "name: " << p2.first << " age: " << p2.second << endl;

	return 0;
}