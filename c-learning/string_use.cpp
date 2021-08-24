#include<iostream>
using namespace std;
#include<string>

// stringʵ����Ҳ��һ���࣬�������ڲ���װ�˺ܶ෽����Ҳ�����˺ܶ๹�캯��


/**
`string();`          				//����һ���յ��ַ��� ����: string str;
`string(const char* s);`	        //ʹ���ַ���s��ʼ��
`string(const string& str);`    //ʹ��һ��string�����ʼ����һ��string����
`string(int n, char c);`           //ʹ��n���ַ�c��ʼ�� */
// string�Ĺ��캯��
void test_string1()
{
	string s1;	// Ĭ�Ϲ���
	const char* str = "hello world";	// ����c���Է����ַ���
	string s2(str);	// ʹ���ַ���s��ʼ��
	cout << "s2:" << s2 << endl;
	string s3(s2);	// ��������
	cout << "s3:" << s3 << endl;
	string s4(10, 'a');		// ��ʼ��n���ַ�
	cout << "s4:" << s4 << endl;
}


// string�ĸ�ֵ����
//*`string& operator=(const char* s); `             //char*�����ַ��� ��ֵ����ǰ���ַ���
//* `string& operator=(const string& s); `         //���ַ���s������ǰ���ַ���
//* `string& operator=(char c); `                          //�ַ���ֵ����ǰ���ַ���
//* `string& assign(const char* s); `                  //���ַ���s������ǰ���ַ���
//* `string& assign(const char* s, int n); `     //���ַ���s��ǰn���ַ�������ǰ���ַ���
//* `string& assign(const string& s); `              //���ַ���s������ǰ�ַ���
//* `string& assign(int n, char c); `                  //��n���ַ�c������ǰ�ַ���
// һ��=�͹����ˣ���һ���ǵ���assign
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
	s5.assign("hello c++", 5);	// ��һ���������԰��ַ�����ǰ������ֵ��һ���µ��ַ���
	cout << "s5:" << s5 << endl;

	string s6;
	s6.assign(s5);
	cout << "s6:" << s6 << endl;

	string s7;
	s7.assign(10, 'c');
	cout << "s7:" << s7 << endl;
}


// string���ַ���ƴ��
void test_string3()
{
	string s1 = "wo";
	s1 += "������Ϸ";
	cout << "s1:" << s1 << endl;

	string s2 = ":lol";
	s1 += s2;
	cout << "s1:" << s1 << endl;

	// string�ĳ�Ա ���� append Ҳ��������������
	string s3 = "i ";
	s3.append("love");
	string s4 = "lol";
	s3.append(s4);
	s3.append(" xxxxx", 3);	// ֻ׷��ǰ�����ַ���
	s3.append("wodewode", 2, 4);	// ֻ׷׷���ַ����еĲ����ַ���--- �����ǣ����ĸ�λ�ÿ�ʼ��ȡ����ȡ����
	cout << "s3:" << s3 << endl;
}


// string�Ĳ��Һ��滻����
//*`int find(const string& str, int pos = 0) const; `              //����str��һ�γ���λ��,��pos��ʼ����
//* `int find(const char* s, int pos = 0) const; `                     //����s��һ�γ���λ��,��pos��ʼ����
//* `int find(const char* s, int pos, int n) const; `               //��posλ�ò���s��ǰn���ַ���һ��λ��
//* `int find(const char c, int pos = 0) const; `                       //�����ַ�c��һ�γ���λ��
//* `int rfind(const string& str, int pos = npos) const; `      //����str���һ��λ��,��pos��ʼ����
//* `int rfind(const char* s, int pos = npos) const; `              //����s���һ�γ���λ��,��pos��ʼ����
//* `int rfind(const char* s, int pos, int n) const; `              //��pos����s��ǰn���ַ����һ��λ��
//* `int rfind(const char c, int pos = 0) const;  `                      //�����ַ�c���һ�γ���λ��
//* `string& replace(int pos, int n, const string& str); `       //�滻��pos��ʼn���ַ�Ϊ�ַ���str
//* `string& replace(int pos, int n, const char* s); `                 //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
void test_string4()
{
	// ����
	string s1 = "abcdefgde";
	int pos = s1.find("de", 0);	// ���� de ��һ�γ��ֵ��±꣬�ڶ���������ָ�� �ڼ����ַ�λ�ÿ�ʼ���ң�Ĭ���Ǵ�ͷ���ң����Բ���
	cout << "de�������ҵ�һ�γ����±��ǣ�" << pos << endl;
	pos = s1.find("ad");	// ���û���ҵ����� -1
	if (pos == -1)
	{
		cout << "û���ҵ�ad" << endl;
	}

	// rfind �� find ������---rfind�Ǵ�������飬find�Ǵ������Ҳ飬��ֻ���ص�һ�γ��ֵ��±�
	pos = s1.rfind("de");
	cout << "de���������һ�γ����±��ǣ�" << pos << endl;


	// �滻
	s1.replace(1, 3, "1111");	// ��һ�������� ��ʼλ�ã��ڶ��������Ǹ����滻�����ַ���������ʼλ�ã��������������� �滻����ַ������滻ǰ���ַ�����Ŀ��Ҫ����ȣ�
	cout << "�滻����ַ����ǣ�" << s1 << endl;
}


// string�ıȽϣ���Ҫ�����ǲ�����ȣ��Ƚϴ�Сû��̫������
void test_string5()
{
	string str1 = "aello";
	string str2 = "hello";
	if (str1.compare(str2) == 0)	// �����ַ����Ƚϣ���λ����ascii��Ƚϣ���ȷ���0
	{
		cout << "���" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1��" << endl;	// ��һ������ͬ��λ�ã���˭��ascii�� �󣬷��ض�Ӧ���
	}
	else
	{
		cout << "str2��" << endl;
	}
}


// string���ַ��桢ȡ����
void test_string6()
{
	string s1 = "hello";
	// stringʵ���Ͼ��Ǹ��ַ����飬�ײ���д��[]����˿���ʹ��[]ȡ�����ַ�
	for (int i = 0; i < s1.size(); i++)	// string.size() �����ַ�������
	{
		cout << s1[i] << ' ';
	}

	// ������ͨ�� at ���� �����ַ�
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << ' ';
	}

	s1[1] = 'b';	// Ҳ��������ȥ�޸�
	cout << s1 << endl;
}


// string�Ĳ����ɾ��
void test_string7()
{
	string s1 = "hello";
	// ����
	s1.insert(1, "111");	// ���� 1 �±�λ�ã����� 111�����±�֮ǰ��
	cout << s1 << endl;
	// ɾ��
	s1.erase(1, 3);		// ���Ǹ�λ���𣬸���ɾ�������ַ�����������ʼλ��Ҳɾ��
	cout << s1 << endl;
}


// string��ȡ�Ӵ�
void test_string8()
{
	string s1 = "abcdefg";
	string s2 = s1.substr(1, 3);	// ���ĸ�λ�ýأ��ؼ�����������ʼλ�ã�
	cout << s2 << endl;

	// �������ڽ�ȡ ������׼�����еĲ��ֱ�־��Ϣ���������û�����ȡ
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