#include<iostream>
#include<string>
using namespace std;

// ����ŵ���ϵ�˸�����define���治��Ҫ �ֺ�
#define MAX 100

// ��ϵ�˽ṹ��
struct Person
{
	string name;
	int sex;	// 1�� 2Ů
	int age;
	string phone;
	string address;
};

// ͨѶ¼�Ľṹ��
struct AddressBooks
{
	Person pers_arr[MAX];
	int size;	// ��ʾ�Ѿ���ŵ���ϵ������
};


// �˵����溯������
void showMenu();
void selectFunction(AddressBooks* ab);
void addUser(AddressBooks* ab);
void showUser(AddressBooks* ab);
void delUser(AddressBooks* ab);
void findUser(AddressBooks ab);
void updateUser(AddressBooks* ab);
void clearUser(AddressBooks* ab);

int main17() {
	// ʵ����һ��ͨѶ¼
	AddressBooks address_book;
	// ��ʼ��ͨѶ¼��Ԫ�صĸ���--- int ���Ͳ���ֵ��û�취ִ�� �ӷ�����
	address_book.size = 0;
	while (true)
	{
		// չʾ�˵�
		showMenu();
		// ִ��ѡ��
		selectFunction(&address_book);
		// �����Ļ
		system("cls");
	}
	return 0;
}

void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

void selectFunction(AddressBooks* ab) {
	int select;
	cout << "������Ҫ������ָ����ţ�";
	cin >> select;
	switch (select)
	{
	case 1:
		addUser(ab);
		break;
	case 2:
		showUser(ab);
		break;
	case 3:
		delUser(ab);
		break;
	case 4:
		findUser(*ab);
		break;
	case 5:
		updateUser(ab);
		break;
	case 6:
		clearUser(ab);
		break;
	case 0:
		cout << "�����˳������ټ���" << endl;
		system("pause");
		exit(0);
	default:
		break;
	}

}

// �����������͵��жϣ�����������Ͳ��ԣ�����������--���䡢�Ա�!
void addUser(AddressBooks* ab) {
	cout << "�������½���ϵ�˵�������";
	string name;
	cin >> name;
	cout << "�������½���ϵ�˵��Ա�(1-�У�2-Ů)��";
	int sex;
	cin >> sex;
	// �ж��Ա������Ƿ�Ϊ��Чֵ
	while (true)
	{
		if ((sex != 1) && (sex != 2))
		{
			cout << "��Ч�����룬���������룺";
		}
		else
		{
			break;
		}
		cin >> sex;
	}
	cout << "�������½���ϵ�˵����䣺";
	int age;
	cin >> age;
	// �ж����������Ƿ�Ϊ��Чֵ
	while (true)
	{
		if ((age <= 0) || (age >= 150))
		{
			cout << "��Ч�����룬���������룺";
		}
		else
		{
			break;
		}
		cin >> age;
	}
	cout << "�������½���ϵ�˵ĵ绰��";
	string phone;
	cin >> phone;
	cout << "�������½���ϵ�˵ĵ�ַ��";
	string address;
	cin >> address;
	int size = ab->size;
	ab->pers_arr[size].name = name;
	ab->pers_arr[size].sex = sex;
	ab->pers_arr[size].age = age;
	ab->pers_arr[size].phone = phone;
	ab->pers_arr[size].address = address;
	ab->size = size + 1;
	system("pause");
}

void showUser(AddressBooks* ab) {
	int user_size = ab->size;
	if (!user_size)
	{
		cout << "��Ǹ����ǰû����Ч����ϵ����Ϣ��" << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; i < user_size; i++)
		{
			cout << "������" << ab->pers_arr[i].name << "\t�Ա�" << ab->pers_arr[i].sex << "\t�ֻ��ţ�" << ab->pers_arr[i].phone << endl;
		}
		system("pause");
	}
}

void delUser(AddressBooks* ab) {
	int flag = 0;
	cout << "������Ҫɾ����ϵ�˵�������";
	string name;
	cin >> name;
	int user_size = ab->size;
	if (user_size == 0)
	{
		cout << "���޴��ˣ�";
		system("pause");
	}
	else
	{
		for (int i = 0; i < user_size; i++)
		{
			if (name == ab->pers_arr[i].name)
			{
				flag = i + 1;
			}
		}
	}
	if (!flag)
	{
		cout << "���޴��ˣ�";
		system("pause");
	}
	else  // �鵽���˿�ʼִ��ɾ��,��ʵ���Ǵӱ�ɾλ���Ҳ࣬����ǰ�Ƹ���ǰ�������
	{
		for (int i = flag - 1; i < user_size - 1; i++)
		{
			ab->pers_arr[i] = ab->pers_arr[i + 1];
		}
		ab->size -= 1;
		cout << "�ɹ�ɾ����ϵ��" << name << endl;
		system("pause");
	}
}

// ������ϵ�˲���Ҫ�޸Ľṹ�壬����ֵ����
void findUser(AddressBooks ab) {
	int flag = 0;
	cout << "������Ҫ������ϵ�˵�������";
	string name;
	cin >> name;
	for (int i = 0; i < ab.size; i++)
	{
		if (name == ab.pers_arr[i].name)
		{
			cout << "�ɹ��ҵ���ϵ�ˣ�" << name << endl;
			cout << "��Ϣ���£�" << "����" << ab.pers_arr[i].name << "\t" << "�Ա�" << ((ab.pers_arr[i].sex == 1) ? "��" : "Ů") << "\t" << "�ֻ���" << ab.pers_arr[i].phone << endl;
			flag = 1;
			system("pause");
			break;
		}
	}
	if (flag == 0)
	{
		cout << "���޴��ˣ�" << endl;
		system("pause");
	}
}

void updateUser(AddressBooks* ab) {
	int flag = 0;
	cout << "������Ҫ�޸ĵ���ϵ��������";
	string name;
	cin >> name;
	for (int i = 0; i < ab->size; i++)
	{
		if (name == ab->pers_arr[i].name)
		{
			cout << "�ɹ��ҵ���ϵ�ˣ�" << name << endl;
			cout << "��ǰ��Ϣ���£�" << "����" << ab->pers_arr[i].name << "\t" << "�Ա�" << ((ab->pers_arr[i].sex == 1) ? "��" : "Ů") << "\t" << "�ֻ���" << ab->pers_arr[i].phone << endl;
			flag = 1;
			cout << "�������µĵ�������";
			cin >> ab->pers_arr[i].name;
			cout << "�������µ��Ա�";
			cin >> ab->pers_arr[i].sex;
			cout << "�������µĵ��ֻ��ţ�";
			cin >> ab->pers_arr[i].phone;
			system("pause");
			break;
		}
	}
	if (flag == 0)
	{
		cout << "���޴��ˣ�" << endl;
		system("pause");
	}
}

// ����Ҫ������������Ϣ��������ά����size��Ϊ0���ɣ��û����޷�����֮ǰ�������ˣ������µ����ݻḲ��������
void clearUser(AddressBooks* ab) {
	ab->size = 0;
	cout << "������ϵ���ѳɹ���գ�" << endl;
	system("pause");
}