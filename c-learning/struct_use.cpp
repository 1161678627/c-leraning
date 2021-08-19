#include<iostream>
#include<string>
using namespace std;

// �ṹ��Ľ̳� https://www.runoob.com/cplusplus/cpp-data-structures.html
// �ṹ��ʵ���Ͼ����Զ����һ���������ͣ����͵ļ���
// �ṹ���������ʽ����
struct Student
{
	// Ȼ�������ṹ�������
	string name;
	bool sex;	// 0Ϊ�У�1ΪŮ
	int age;
	int score;
};

// ��������
void printStu1(Student stu);
void printStu2(Student* p);
void printStu3(const Student* p);

int main15() {
	// �����ṹ��ķ�ʽ, struct Student tom;	���� struct �ؼ�����ʵ�����ṹ��ʱ����ʡ�ԣ����������ṹ��ʱ����ʡ�ԣ�
	// 1. ʵ�����ṹ���������Ը�ֵ�ֿ�
	Student tom;
	tom.name = "tom";
	tom.age = 22;
	tom.sex = 0;
	tom.score = 100;
	cout << "tom������������£�" << tom.name << "    " << tom.sex << "    " << tom.age << "    " << tom.score << endl;

	// 2. ʵ�����ṹ���������Ը�ֵһ��ע�⸳ֵ˳���ԭʼ����˳�򱣳�һ��
	Student jack = { "jack", 0, 23, 98 };
	cout << "tom������������£�" << jack.name << "    " << jack.sex << "    " << jack.age << "    " << jack.score << endl;


	// �ṹ��������������������������һ�£������ڳ�ʼ�����ʱ��͸�ֵ��Ҳ�����ں���Լ���ֵ
	// Student stuArry1[2] = { {"jack", 22, 1, 1}, {"tom", 11, 1, 2} };
	Student stuArry[3];
	for (int i = 0; i < 3; i++)
	{
		stuArry[i].name = "jack";
		stuArry[i].age = 22;
		stuArry[i].sex = 1;
		stuArry[i].score = 100;
	}


	// �ṹ��ָ��,���ṹ�����͵�ָ�룬ר��ָ��ṹ��
	// �ṹ��ʵ������ı����� jack --- �������;��ǽṹ�����ͣ����Ե���int����
	// cout << typeid(jack).name() << endl;

	// ����һ�� Student���ͽṹ���ָ�룬ָ�� jack ����ĵ�ַ
	Student* p = &jack;
	// ͨ��  ָ��->����  ���ſ��Է�����ָ��Ľṹ���е����ԣ������޸Ļ��ߴ�ӡ
	p->age = 55;
	cout << "�ṹ��" << p->name << "��������" << p->age << endl;


	// �ṹ�� Ƕ�׽ṹ�壬ע�� 1.�ڲ��ṹ��Ķ���Ӧ�����ⲿ�ṹ��֮ǰ��������Ҳ�������		2.�����ڲ��ṹ������Գ�Ա ��ֵ��������ʱ��ʹ�� �ⲿ�ṹ��.�ڲ��ṹ��.���� = xxx;
	// ����Ƕ�׽ṹ��
	struct Teacher
	{
		string name;
		int age;
		Student student;
	};
	// ʵ����Ƕ�׽ṹ�岢��ֵ
	Teacher zk;
	zk.name = "zhaokun";
	zk.age = 23;
	// ��������ֱ�Ӹ� Ƕ�׽ṹ�帳ֵһ�����еĽṹ�壬Ҳ����  zk.student.name = "xxx" ����������ֵ
	// ���ִ����� deepcopy ���ݣ�jack��Ա�ĸı䣬����Ӱ��zk�е�student����
	zk.student = jack;
	cout << "����ʦ��ѧ��������" << zk.student.name << endl;
	jack.name = "xxxxx";	// �����޸���jack.name��zk.student.name����
	cout << jack.name << endl;
	cout << "����ʦ��ѧ��������" << zk.student.name << endl;


	// �ṹ������������---ֵ���ݡ�ָ�봫��
	// ֵ���ݾ��ǰ� jack ���ʵ��������ֱ�Ӵ���������������ȥ��deepcopy���ã������ڲ��βκ�ʵ���޸Ĳ������������Ĳ��������� Student xxx;
	// ָ�봫�ݾ��� ��ʵ����һ�� Student ���͵�ָ�룬ָ�� jack ����Ȼ������ָ����Ϊ������������ȥ�������Ĳ���������	Student* xxx;
	printStu1(jack);
	cout << "ֵ���ݺ������޸ĺ��������" << jack.name << endl;
	printStu2(&jack);
	cout << "ָ�봫�ݺ������޸ĺ��������" << jack.name << endl;


	// �ṹ��ָ�봫����Ϊ��������ʱ���п��ܻᱻ�����ڲ��Ĳ����޸��������ԣ�������ܲ���������Ҫ�ģ�
	// Ϊ�˱����󴥣������ں����������ʱ ����const Student* xxx ---��������������ڣ��ô���ṹ��ֻ�ܱ���ȡ�������޸�
	// ��ָ�벻��ֵ��ԭ���ǣ�ָ�����һ����ַ��4���ֽڣ�����ֵҪcopyһ��һģһ���������ݣ�������ʱ�����˷��ڴ�
	printStu3(&jack);


	return 0;
}

// ֵ����---����ȥ֮�󣬾������������ˣ��໥������
void printStu1(Student stu) {
	stu.name = "wogaile";
	cout << "ֵ���ݺ������޸ĺ�������ǣ�" << stu.name << endl;
}

// ָ�봫��
void printStu2(Student* p) {
	p->name = "wogaile";
	cout << "ָ�봫�ݺ������޸ĺ�������ǣ�" << p->name << endl;
}

// ָ�봫�ݣ����const
void printStu3(const Student* p) {
	// p->name = "wogaile";		ֻ�ܷ��ʣ��޷���Ϊ��ֵ�޸�
	cout << "ָ�봫�ݺ������޸ĺ�������ǣ�" << p->name << endl;
}