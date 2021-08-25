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
		string name = "ѡ��";
		v.push_back(Personp0(name + name_seed[i], 0));
	}
}

void myPrint(vector<Personp0>& v)
{
	for (int i = 0; i < 5; i++)
	{
		cout << "���������" << v[i].m_name << "\t����" << v[i].m_score << endl;
	}
}

void setScore(vector<Personp0>& v)
{
	for (int i = 0; i < 5; i++)
	{
		deque<int> scores;
		for (int j = 0; j < 10; j++)
		{
			int score = rand() % 41 + 60;	// 60-100,�������������ʱ��ÿ������Ľ����һ��
			scores.push_back(score);
		}
		sort(scores.begin(), scores.end());
		scores.pop_back();
		scores.pop_front();	// ȥ����߷֣���ͷ�
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
	// ������������ӣ���֤randÿ�ν����ͬ
	srand((unsigned int)time(NULL));

	// ��������ѡ��
	vector<Personp0> v;
	createPerson(v);

	// ������ѡ�ִ��
	setScore(v);

	myPrint(v);
	return 0;
}