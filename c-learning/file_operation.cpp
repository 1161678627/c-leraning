#include<iostream>
using namespace std;
#include<fstream>	// �����ļ�������ͷ�ļ�
#include<string>


class Person
{
public:
	char m_Name[64];	// д���Զ���������ļ�ʱ����Ķ��������c�����еģ��ַ����飬�����б���
	int m_Age;
private:

};

// ʹ�ö����Ʒ�ʽд�ļ�
void test1() {
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);	// ָ��modeΪ������ д��
	Person p = {"zhangsan", 15 };
	ofs.write((const char*)&p, sizeof(Person));	// ����ȡ��ʵ��������p�ĵ�ַ��Ȼ�� Ϊ�����㺯��������Ҫ�� &p ǿתΪconst char*���ͣ� �ڶ������������ݵĳ��ȣ���С��
	ofs.close();
}

// ʹ�ö����Ʒ�ʽ���ļ�
void test2() {
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "�������ļ���ȡ��ʧ�ܣ�" << endl;
		return;
	}
	// ���ļ�
	Person p;	// ʵ����һ��д���ļ����Ķ������
	ifs.read((char*)&p, sizeof(Person));	// ��һ������ ��ȡ�ļ����ʵ������ַ��������ҪǿתΪchar*���ͣ��ڶ�����������ȡ��Ĵ�С
	cout << p.m_Name << '\t' << p.m_Age << endl;
	ifs.close();
}


int main24() {
	/*
	�ļ��򿪷�ʽ��

| �򿪷�ʽ    | ����                       |
| ----------- | -------------------------- |
| ios::in     | Ϊ���ļ������ļ�         |
| ios::out    | Ϊд�ļ������ļ�         |
| ios::ate    | ��ʼλ�ã��ļ�β           |
| ios::app    | ׷�ӷ�ʽд�ļ�             |
| ios::trunc  | ����ļ�������ɾ�����ٴ��� |
| ios::binary | �����Ʒ�ʽ                 |

**ע�⣺** �ļ��򿪷�ʽ�������ʹ�ã�����|������

**���磺**�ö����Ʒ�ʽд�ļ� `ios::binary |  ios:: out`*/
	// ����������---д�ļ�
	ofstream ofs;
	// ָ���򿪷�ʽ
	ofs.open("./test.txt", ios::out);
	// д����
	ofs << "������\t����sssssssssssssssssssssssssssssssssssssssssssss" << endl;
	ofs << "�Ա�\t��" << endl;
	ofs << "���䣺\t18" << endl;
	// �ر�io��
	ofs.close();


	// ���ļ�
	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ���ˣ�" << endl;
		return 0;
	}
	// ������
	string buf;	// ����һ���ַ���������ָ�룩���ڽ���ÿһ�ж���������
	int index = 1;
	while (getline(ifs, buf))	// getline(ifs, buf) ʹ�� getline������ ifs�а��ж�ȡ���ݵ�buf��
	{
		cout << "��ȡ��" << index++ << "�еĴ�С�ǣ�" << sizeof(buf) << endl;	// ��ӡ ÿ�ж�ȡ��������
		cout << "��ȡ��" << index++ << "�е������ǣ�" << buf << endl;	// ��ӡ ÿ�ж�ȡ��������
	}
	cout << "ѭ��������buf�е������ǣ�" << sizeof(buf) << endl;		// ѭ��������string�е����ݾ������.
	// ע��sizeof���ص������͵Ĵ�С��string�������� ĳ���࣬�����������Ҫ�����ָ�룬�������ַ����ݣ�������Ĵ�С��Զ��28�������ַ�������û��ϵ


	// ʹ�ö����Ʒ�ʽд��ʵ�������Զ����ൽ����
	test1();
	// ʹ�ö����Ʒ�ʽ��ȡд�뵽���ص�ʵ�������Զ����ൽ�ڴ�
	test2();
	return 0;
}