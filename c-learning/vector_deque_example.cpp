#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

class Personp0
{
public:
	Personp0(string name, int score);
	string m_name;
	int m_score;
private:

};

Personp0::Personp0(string name, int score)
{
	this->m_name = name;
	this->m_score = score;
}

void createPerson(vector<Personp0>& v)
{
	string name_seed = "abcde";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		v.push_back(Personp0(name + name_seed[i], 0));
	}
}

void myPrint(vector<Personp0>& v)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "玩家姓名：" << v[i].m_name << "\t分数" << v[i].m_score << endl;
	}
}

void setScore(vector<Personp0>& v)
{
	for (int i = 0; i < 5; i++)
	{
		deque<int> scores;
		for (int j = 0; j < 10; j++)
		{
			int score = rand() % 41 + 60;	// 60-100,不加随机数种子时，每次随机的结果都一样
			scores.push_back(score);
		}
		sort(scores.begin(), scores.end());
		scores.pop_back();
		scores.pop_front();	// 去除最高分，最低分
		int sum = 0;
		for (deque<int>::iterator i = scores.begin(); i != scores.end(); i++)
		{
			sum += *i;
		}
		v[i].m_score = sum / 8;
	}
}

// 28
int main28()
{
	// 增加随机数种子，保证rand每次结果不同
	srand((unsigned int)time(NULL));

	// 创建五名选手
	vector<Personp0> v;
	createPerson(v);

	// 给五名选手打分
	setScore(v);

	myPrint(v);
	return 0;
}