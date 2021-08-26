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
	// ���������
	srand((unsigned int)time(NULL));

	// ����Ա��
	vector<Worker> v1;
	string name_seed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker w;
		// ���д�� += ��ʽ��string����Ƚ϶� w.m_name = "Ա��" + name_seed[i] ���д���;
		w.m_name = "Ա��";
		w.m_name += name_seed[i];
		w.salary = rand() % 10001 + 10000;
		v1.push_back(w);
	}

	for (vector<Worker>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		cout << "������" << i->m_name << "\t���ʣ�" << i->salary << endl;
	}


	// Ա������
	multimap<int, Worker> mWorker;
	for (vector<Worker>::iterator i = v1.begin(); i != v1.end(); i++)
	{
		int deptid;
		deptid = rand() % 3;
		mWorker.insert(make_pair(deptid, *i));
	}

	// ������ʾԱ��
	cout << "�߻����ŵ���Ϣ��" << endl;
	multimap<int, Worker>::iterator it_begin = mWorker.find(0);
	int count = mWorker.count(0);
	for (int i = 0; i < count; i++, it_begin++)
	{
		cout << "������" << it_begin->second.m_name << "\t���ʣ�" << it_begin->second.salary << endl;
	}
	cout << "��Ʋ��ŵ���Ϣ��" << endl;
	it_begin = mWorker.find(1);
	count = mWorker.count(1);
	for (int i = 0; i < count; i++, it_begin++)
	{
		cout << "������" << it_begin->second.m_name << "\t���ʣ�" << it_begin->second.salary << endl;
	}
	cout << "�������ŵ���Ϣ��" << endl;
	it_begin = mWorker.find(1);
	count = mWorker.count(2);
	for (int i = 0; i < count; i++, it_begin++)
	{
		cout << "������" << it_begin->second.m_name << "\t���ʣ�" << it_begin->second.salary << endl;
	}

	return 0;
}