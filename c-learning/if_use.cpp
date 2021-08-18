#include<iostream>
using namespace std;

int main9() {
	int scores;
	cout << "请输入您的考试成绩：" << ends;
	cin >> scores;
	cout << "您输入的成绩是：" << scores << endl;

	// 和c语言的基本一致，但是注意if 和 条件() 之间有空格,执行语句 {} 换行写，()和{}后面没有 ;
	if (scores > 600) 
	{
		cout << "恭喜您，考上了一本" << endl;
	}
	else if (scores > 500)
	{
		cout << "恭喜您考上了二本" << endl;
	}
	else if (scores > 450)
	{
		cout << "恭喜您考上了三本" << endl;
	}
	else
	{
		cout << "对不起，您落榜了！" << endl;
	}

	return 0;
}