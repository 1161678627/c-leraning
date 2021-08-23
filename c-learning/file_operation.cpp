#include<iostream>
using namespace std;
#include<fstream>	// 用于文件操作的头文件
#include<string>


class Person
{
public:
	char m_Name[64];	// 写入自定义二进制文件时，类的定义最好用c语言中的，字符数组，否则有报错
	int m_Age;
private:

};

// 使用二进制方式写文件
void test1() {
	ofstream ofs;
	ofs.open("person.txt", ios::out | ios::binary);	// 指定mode为二进制 写入
	Person p = {"zhangsan", 15 };
	ofs.write((const char*)&p, sizeof(Person));	// 首先取到实例化对象p的地址，然后 为了满足函数参数需要将 &p 强转为const char*类型， 第二个参数，数据的长度（大小）
	ofs.close();
}

// 使用二进制方式读文件
void test2() {
	ifstream ifs;
	ifs.open("person.txt", ios::in | ios::binary);
	if (!ifs.is_open())
	{
		cout << "二进制文件读取打开失败！" << endl;
		return;
	}
	// 读文件
	Person p;	// 实例化一个写入文件流的对象出来
	ifs.read((char*)&p, sizeof(Person));	// 第一个参数 读取文件类的实例化地址，不过需要强转为char*类型，第二个参数，读取类的大小
	cout << p.m_Name << '\t' << p.m_Age << endl;
	ifs.close();
}


int main24() {
	/*
	文件打开方式：

| 打开方式    | 解释                       |
| ----------- | -------------------------- |
| ios::in     | 为读文件而打开文件         |
| ios::out    | 为写文件而打开文件         |
| ios::ate    | 初始位置：文件尾           |
| ios::app    | 追加方式写文件             |
| ios::trunc  | 如果文件存在先删除，再创建 |
| ios::binary | 二进制方式                 |

**注意：** 文件打开方式可以配合使用，利用|操作符

**例如：**用二进制方式写文件 `ios::binary |  ios:: out`*/
	// 创建流对象---写文件
	ofstream ofs;
	// 指定打开方式
	ofs.open("./test.txt", ios::out);
	// 写内容
	ofs << "姓名：\t张三sssssssssssssssssssssssssssssssssssssssssssss" << endl;
	ofs << "性别：\t男" << endl;
	ofs << "年龄：\t18" << endl;
	// 关闭io流
	ofs.close();


	// 读文件
	ifstream ifs;
	ifs.open("./test.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败了！" << endl;
		return 0;
	}
	// 读数据
	string buf;	// 定义一个字符串变量（指针）用于接收每一行读到的数据
	int index = 1;
	while (getline(ifs, buf))	// getline(ifs, buf) 使用 getline函数从 ifs中按行读取数据到buf中
	{
		cout << "读取第" << index++ << "行的大小是：" << sizeof(buf) << endl;	// 打印 每行读取到的数据
		cout << "读取第" << index++ << "行的内容是：" << buf << endl;	// 打印 每行读取到的数据
	}
	cout << "循环结束后buf中的内容是：" << sizeof(buf) << endl;		// 循环结束后string中的内容就清空了.
	// 注：sizeof返回的是类型的大小，string里面存的是 某种类，这个类里面主要存的是指针，而不存字符数据，因此他的大小永远是28，和你字符串长度没关系


	// 使用二进制方式写入实例化的自定义类到本地
	test1();
	// 使用二进制方式读取写入到本地的实例化的自定义类到内存
	test2();
	return 0;
}