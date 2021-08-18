#include<iostream>
using namespace std;

// https://www.runoob.com/cplusplus/cpp-switch.html switch 使用规则见该网页
// 一般switch的每个case分支语句中都会带个break，如果不带，则当进入一个case分支后，先执行完该case中的语句，然后不再判断其余的case，直接挨个执行他们case中的语句，直到遇到break
// 当某两个 分支的执行语句一致，可以把他们写为连续分支 10，9分时，然后第一个分支可以不写执行语句。
// default 分支当前面所有case都不满足时才执行(当然前面如果不写break也会执行到default)
int main10() {
	int score;
	cout << "请输入您对当前电影的评分：";
	cin >> score;
	cout << "您给该电影打了" << score << "分" << endl;
	switch (score)
	{
	case 10:
	case 9:
		cout << "您认为当前电影评分很高" << endl;
		break;
	case 8:
	case 7:
		cout << "您认为当前电影评分一般" << endl;
		break;
	default:
		cout << "您认为当前电影不行" << endl;
		break;
	}

	return 0;
}