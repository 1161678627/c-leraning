#include<iostream>
#include<string>
using namespace std;

int main4() {
	// �ַ��ͱ����Ĵ�����ʽ,�ַ���Ҫ�õ����ű�ʾ���ҵ������ڽ�����һ���ַ�
	char ch1 = 'a';
	cout << ch1 << endl;
	// �ַ��ͱ�����ռ�ڴ��С	1���ֽ�
	cout << sizeof(char) << endl;
	// �鿴�ַ������ݶ�Ӧ�� ascii �룬�ַ����������ڴ�������ascii����ʽ�洢��---������ a=97��A=65
	cout << "a��Ӧ��asciiֵΪ:" << int(ch1) << endl;
	cout << "A��Ӧ��asciiֵΪ:" << int('A') << endl;


	// ת���ַ�	\t ˮƽ�Ʊ�����Ʊ��+�Ʊ��ǰ���ַ�����ռ8���ո����ڶ������
	cout << "��������һ��֮���еĵ�һ�ַ���\tendl" << endl;
	cout << "��������һ��֮���еĵڶ��ַ���\t\\n \n";


	// �ַ�������,C++�������ַ����ַ����������ַ���������˫����
	// 1 c���Է����ַ���,��������ʽ����
	char str1[] = "c���Է����ַ���";
	// 2 c++�����ַ�������string���Ͷ���
	// ������Ҫ���� #include<string> ͷ�ļ�,���ǲ�����Ҳ���ԣ���Ϊ#include<iostream>����ʽ������#include<string>�ˣ����ǻ��ǽ�����ʽ����һ�£�����Ī�������
	string str2 = "C++�����ַ���";

	cout << str1 << endl;
	cout << str2 << endl;
	return 0;
}