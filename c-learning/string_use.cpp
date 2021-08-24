#include<iostream>
using namespace std;
#include<string>

// string实际上也是一个类，这个类的内部封装了很多方法，也重载了很多构造函数


/**
`string();`          				//创建一个空的字符串 例如: string str;
`string(const char* s);`	        //使用字符串s初始化
`string(const string& str);`    //使用一个string对象初始化另一个string对象
`string(int n, char c);`           //使用n个字符c初始化 */
// string的构造函数
void test_string1()
{
	string s1;	// 默认构造
	const char* str = "hello world";	// 这是c语言风格的字符串
	string s2(str);	// 使用字符串s初始化
	cout << "s2:" << s2 << endl;
	string s3(s2);	// 拷贝构造
	cout << "s3:" << s3 << endl;
	string s4(10, 'a');		// 初始化n个字符
	cout << "s4:" << s4 << endl;
}


// string的赋值操作
//*`string& operator=(const char* s); `             //char*类型字符串 赋值给当前的字符串
//* `string& operator=(const string& s); `         //把字符串s赋给当前的字符串
//* `string& operator=(char c); `                          //字符赋值给当前的字符串
//* `string& assign(const char* s); `                  //把字符串s赋给当前的字符串
//* `string& assign(const char* s, int n); `     //把字符串s的前n个字符赋给当前的字符串
//* `string& assign(const string& s); `              //把字符串s赋给当前字符串
//* `string& assign(int n, char c); `                  //用n个字符c赋给当前字符串
// 一般=就够用了，不一定非得用assign
void test_string2()
{
	string s1;
	s1 = "hello world";
	cout << "s1:" << s1 << endl;

	string s2;
	s2 = s1;
	cout << "s2:" << s2 << endl;

	string s4;
	s4.assign("hello c++");
	cout << "s4:" << s4 << endl;

	string s5;
	s5.assign("hello c++", 5);	// 加一个参数可以把字符串的前几个赋值给一个新的字符串
	cout << "s5:" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6:" << s6 << endl;

	string s7;
	s7.assign(10, 'c');
	cout << "s7:" << s7 << endl;
}


// string的字符串拼接
void test_string3()
{
	string s1 = "wo";
	s1 += "爱玩游戏";
	cout << "s1:" << s1 << endl;

	string s2 = ":lol";
	s1 += s2;
	cout << "s1:" << s1 << endl;

	// string的成员 函数 append 也可以完成这个任务
	string s3 = "i ";
	s3.append("love");
	string s4 = "lol";
	s3.append(s4);
	s3.append(" xxxxx", 3);	// 只追加前几个字符串
	s3.append("wodewode", 2, 4);	// 只追追加字符串中的部分字符串--- 参数是，从哪个位置开始截取，截取几个
	cout << "s3:" << s3 << endl;
}


// string的查找和替换操作
//*`int find(const string& str, int pos = 0) const; `              //查找str第一次出现位置,从pos开始查找
//* `int find(const char* s, int pos = 0) const; `                     //查找s第一次出现位置,从pos开始查找
//* `int find(const char* s, int pos, int n) const; `               //从pos位置查找s的前n个字符第一次位置
//* `int find(const char c, int pos = 0) const; `                       //查找字符c第一次出现位置
//* `int rfind(const string& str, int pos = npos) const; `      //查找str最后一次位置,从pos开始查找
//* `int rfind(const char* s, int pos = npos) const; `              //查找s最后一次出现位置,从pos开始查找
//* `int rfind(const char* s, int pos, int n) const; `              //从pos查找s的前n个字符最后一次位置
//* `int rfind(const char c, int pos = 0) const;  `                      //查找字符c最后一次出现位置
//* `string& replace(int pos, int n, const string& str); `       //替换从pos开始n个字符为字符串str
//* `string& replace(int pos, int n, const char* s); `                 //替换从pos开始的n个字符为字符串s
void test_string4()
{
	// 查找
	string s1 = "abcdefgde";
	int pos = s1.find("de", 0);	// 返回 de 第一次出现的下标，第二个参数是指从 第几个字符位置开始查找，默认是从头查找，可以不传
	cout << "de从左往右第一次出现下标是：" << pos << endl;
	pos = s1.find("ad");	// 如果没查找到返回 -1
	if (pos == -1)
	{
		cout << "没查找到ad" << endl;
	}

	// rfind 和 find 的区别---rfind是从右往左查，find是从左往右查，都只返回第一次出现的下标
	pos = s1.rfind("de");
	cout << "de从右往左第一次出现下标是：" << pos << endl;


	// 替换
	s1.replace(1, 3, "1111");	// 第一个参数是 起始位置，第二个参数是给后替换几个字符（包含起始位置），第三个参数是 替换后的字符串（替换前后字符串数目不要求相等）
	cout << "替换后的字符串是：" << s1 << endl;
}


// string的比较，主要用来是不是相等，比较大小没有太大意义
void test_string5()
{
	string str1 = "aello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)	// 两个字符串比较，按位进行ascii码比较，相等返回0
	{
		cout << "相等" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1大" << endl;	// 第一个不相同的位置，看谁的ascii码 大，返回对应结果
	}
	else
	{
		cout << "str2大" << endl;
	}
}


// string的字符存、取操作
void test_string6()
{
	string s1 = "hello";
	// string实际上就是个字符数组，底层重写了[]，因此可以使用[]取单个字符
	for (int i = 0; i < s1.size(); i++)	// string.size() 返回字符串长度
	{
		cout << s1[i] << ' ';
	}

	// 还可以通过 at 访问 单个字符
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << ' ';
	}

	s1[1] = 'b';	// 也可以这样去修改
	cout << s1 << endl;
}


// string的插入和删除
void test_string7()
{
	string s1 = "hello";
	// 插入
	s1.insert(1, "111");	// 给第 1 下标位置，插入 111，给下标之前插
	cout << s1 << endl;
	// 删除
	s1.erase(1, 3);		// 从那个位置起，给后删除几个字符，（包含起始位置也删）
	cout << s1 << endl;
}


// string截取子串
void test_string8()
{
	string s1 = "abcdefg";
	string s2 = s1.substr(1, 3);	// 从哪个位置截，截几个（包含起始位置）
	cout << s2 << endl;

	// 可以用于截取 批量标准数据中的部分标志信息，如邮箱用户名获取
	string s3 = "1161678627@qq.com";
	int index = s3.find('@');
	cout << s3.substr(0, index) << endl;;
}

// 26
int main26() {

	// test_string1();
	// test_string2();
	// test_string3();
	// test_string4();
	// test_string5();
	// test_string6();
	// test_string7();
	test_string8();
	return 0;
}