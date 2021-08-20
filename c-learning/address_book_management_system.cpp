#include<iostream>
#include<string>
using namespace std;

// 最多存放的联系人个数，define后面不需要 分号
#define MAX 100

// 联系人结构体
struct Person
{
	string name;
	int sex;	// 1男 2女
	int age;
	string phone;
	string address;
};

// 通讯录的结构体
struct AddressBooks
{
	Person pers_arr[MAX];
	int size;	// 表示已经存放的联系人数量
};


// 菜单界面函数声明
void showMenu();
void selectFunction(AddressBooks* ab);
void addUser(AddressBooks* ab);
void showUser(AddressBooks* ab);
void delUser(AddressBooks* ab);
void findUser(AddressBooks ab);
void updateUser(AddressBooks* ab);
void clearUser(AddressBooks* ab);

int main17() {
	// 实例化一个通讯录
	AddressBooks address_book;
	// 初始化通讯录中元素的个数--- int 类型不赋值，没办法执行 加法操作
	address_book.size = 0;
	while (true)
	{
		// 展示菜单
		showMenu();
		// 执行选择
		selectFunction(&address_book);
		// 清空屏幕
		system("cls");
	}
	return 0;
}

void showMenu() {
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void selectFunction(AddressBooks* ab) {
	int select;
	cout << "请输入要操作的指令序号：";
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
		cout << "即将退出程序，再见！" << endl;
		system("pause");
		exit(0);
	default:
		break;
	}

}

// 新增输入类型的判断，如果输入类型不对，就重新输入--年龄、性别!
void addUser(AddressBooks* ab) {
	cout << "请输入新建联系人的姓名：";
	string name;
	cin >> name;
	cout << "请输入新建联系人的性别(1-男，2-女)：";
	int sex;
	cin >> sex;
	// 判断性别输入是否为有效值
	while (true)
	{
		if ((sex != 1) && (sex != 2))
		{
			cout << "无效的输入，请重新输入：";
		}
		else
		{
			break;
		}
		cin >> sex;
	}
	cout << "请输入新建联系人的年龄：";
	int age;
	cin >> age;
	// 判断年龄输入是否为有效值
	while (true)
	{
		if ((age <= 0) || (age >= 150))
		{
			cout << "无效的输入，请重新输入：";
		}
		else
		{
			break;
		}
		cin >> age;
	}
	cout << "请输入新建联系人的电话：";
	string phone;
	cin >> phone;
	cout << "请输入新建联系人的地址：";
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
		cout << "抱歉，当前没有有效的联系人信息！" << endl;
		system("pause");
	}
	else
	{
		for (int i = 0; i < user_size; i++)
		{
			cout << "姓名：" << ab->pers_arr[i].name << "\t性别：" << ab->pers_arr[i].sex << "\t手机号：" << ab->pers_arr[i].phone << endl;
		}
		system("pause");
	}
}

void delUser(AddressBooks* ab) {
	int flag = 0;
	cout << "请输入要删除联系人的姓名：";
	string name;
	cin >> name;
	int user_size = ab->size;
	if (user_size == 0)
	{
		cout << "查无此人！";
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
		cout << "查无此人！";
		system("pause");
	}
	else  // 查到人了开始执行删除,其实就是从被删位置右侧，依次前移覆盖前面的数据
	{
		for (int i = flag - 1; i < user_size - 1; i++)
		{
			ab->pers_arr[i] = ab->pers_arr[i + 1];
		}
		ab->size -= 1;
		cout << "成功删除联系人" << name << endl;
		system("pause");
	}
}

// 查找联系人不需要修改结构体，可以值传递
void findUser(AddressBooks ab) {
	int flag = 0;
	cout << "请输入要查找联系人的姓名：";
	string name;
	cin >> name;
	for (int i = 0; i < ab.size; i++)
	{
		if (name == ab.pers_arr[i].name)
		{
			cout << "成功找到联系人：" << name << endl;
			cout << "信息如下：" << "姓名" << ab.pers_arr[i].name << "\t" << "性别：" << ((ab.pers_arr[i].sex == 1) ? "男" : "女") << "\t" << "手机号" << ab.pers_arr[i].phone << endl;
			flag = 1;
			system("pause");
			break;
		}
	}
	if (flag == 0)
	{
		cout << "查无此人！" << endl;
		system("pause");
	}
}

void updateUser(AddressBooks* ab) {
	int flag = 0;
	cout << "请输入要修改的联系人姓名：";
	string name;
	cin >> name;
	for (int i = 0; i < ab->size; i++)
	{
		if (name == ab->pers_arr[i].name)
		{
			cout << "成功找到联系人：" << name << endl;
			cout << "当前信息如下：" << "姓名" << ab->pers_arr[i].name << "\t" << "性别：" << ((ab->pers_arr[i].sex == 1) ? "男" : "女") << "\t" << "手机号" << ab->pers_arr[i].phone << endl;
			flag = 1;
			cout << "请输入新的的姓名：";
			cin >> ab->pers_arr[i].name;
			cout << "请输入新的性别：";
			cin >> ab->pers_arr[i].sex;
			cout << "请输入新的的手机号：";
			cin >> ab->pers_arr[i].phone;
			system("pause");
			break;
		}
	}
	if (flag == 0)
	{
		cout << "查无此人！" << endl;
		system("pause");
	}
}

// 不需要真的清空所有信息，仅仅把维护的size置为0即可，用户就无法访问之前的数据了，并且新的数据会覆盖老数据
void clearUser(AddressBooks* ab) {
	ab->size = 0;
	cout << "所有联系人已成功清空！" << endl;
	system("pause");
}