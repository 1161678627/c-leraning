#include<iostream>
#include<ctime>		// 因为后续调用了time，所以引入time头文件
using namespace std;


// 定义一个产生随机数的函数
int get_random_number(int max) {
	int random_num;
	srand((unsigned int)time(NULL)); //time()用系统时间初始化种。为rand()生成不同的随机种子。
	random_num = rand() % max + 1;
	return random_num;
}

int main11 () {
	// do while 循环---至少执行一次
	int num = 1;
	do
	{
		cout << "当前输出的数字是：" << num << endl;
		num++;
	} while (num <= 10);


	// 水仙花数，使用 do while
	for (int i = 100; i <= 999; i++)
	{
		int one, ten, hundred;
		one = i % 10;
		ten = (i % 100 - one) / 10;
		hundred = i / 100;
		int final_num = one * one * one + ten * ten * ten + hundred * hundred * hundred;
		if (final_num == i)
		{
			cout << "找到水仙花数：" << i << endl;
		}
	}


	// while 循环
	int random_num = get_random_number(100);
	bool flag = 1;
	while (flag)
	{	
		int temp_num;
		cout << "请输入你猜得数字：" << ends;
		cin >> temp_num;
		if (temp_num > random_num) {
			cout << "对不起，您猜的过大！" << endl;
		}
		else if (temp_num < random_num)
		{
			cout << "对不起，您猜的过小！" << endl;
		}
		else
		{
			cout << "恭喜您，猜对了！" << endl;
			flag = 0;
		}
	}

	return 0;
}