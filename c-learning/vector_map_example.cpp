#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<ctime>
using namespace std;

class Worker
{
public:
	string m_name;
	int salary;

private:

};


int main35() {
	// 随机数种子
	srand((unsigned int)time(NULL));

	// 创建员工
	vector<Worker> v1;
	string name_seed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker w;
		// 最好写成 += 形式，string问题比较多 w.m_name = "员工" + name_seed[i] 会有错误;
		w.m_name = "员工";
		w.m_name += name_seed[i];
		w.salary = rand() % 10001 + 10000;
		v1.push_back(w);
	}

	for (vector<Worker>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		cout << "姓名：" << i->m_name << "\t工资：" << i->salary << endl;
	}


	// 员工分组
	multimap<int, Worker> mWorker;
	for (vector<Worker>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		int deptid;
		deptid = rand() % 3;
		mWorker.insert(make_pair(deptid, *i));
	}

	// 分组显示员工
	cout << "策划部门的信息：" << endl;
	multimap<int, Worker>::iterator it_begin = mWorker.find(0);
	int count = mWorker.count(0);
	for (int i = 0; i < count; i++, it_begin++)
	{
		cout << "姓名：" << it_begin->second.m_name << "\t工资：" << it_begin->second.salary << endl;
	}
	cout << "设计部门的信息：" << endl;
	it_begin = mWorker.find(1);
	count = mWorker.count(1);
	for (int i = 0; i < count; i++, it_begin++)
	{
		cout << "姓名：" << it_begin->second.m_name << "\t工资：" << it_begin->second.salary << endl;
	}
	cout << "技术部门的信息：" << endl;
	it_begin = mWorker.find(1);
	count = mWorker.count(2);
	for (int i = 0; i < count; i++, it_begin++)
	{
		cout << "姓名：" << it_begin->second.m_name << "\t工资：" << it_begin->second.salary << endl;
	}

	return 0;
}