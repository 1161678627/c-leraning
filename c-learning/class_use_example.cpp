#include<iostream>
using namespace std;

// ����һ�������࣬�ô��麯������������Ʒ���õ��ĸ��׶Σ�������
class Beverage
{
public:
	// ��ˮ
	virtual void Boil() = 0;
	// ����
	virtual void Brew() = 0;
	// ���뱭��
	virtual void PourCup() = 0;
	// ���븨��
	virtual void PutSomething() = 0;

	// �������Ĳ�Ϊһ����������������������ļ̳е������м��ɣ����е��õĴ��麯��Ҳ�ᱻ�������д���������
	void makeDrink() {
		Boil();
		Brew();
		PourCup();
		PutSomething();
	}

private:

};

// ��ʼ���� ���ô��麯��ʵ�ֵ�����
// coffee
class Coffee : public Beverage
{
public:
	// ��ʼ�����ʵ�ֳ������е��麯��
	virtual void Boil() {
		cout << "��ũ��ɽȪ" << endl;
	}

	virtual void Brew() {
		cout << "����coffee" << endl;
	}
	virtual void PourCup() {
		cout << "�����ǰͿ˱���" << endl;
	}
	virtual void PutSomething() {
		cout << "��������" << endl;
	}

private:

};

// tea
class Tea : public Beverage
{
public:
	// ��ʼ�����ʵ�ֳ������е��麯��
	virtual void Boil() {
		cout << "��ɽ�۽�ˮ" << endl;
	}

	virtual void Brew() {
		cout << "����������" << endl;
	}
	virtual void PourCup() {
		cout << "����ĥɰ��" << endl;
	}
	virtual void PutSomething() {
		cout << "����һ��軨" << endl;
	}

private:

};

// ����һ������ʵ��������������Ʒ�ĺ���---�������ѡ�� ��������ô��룬Ҳ����ѡ��ָ�봫�룬���ǵ�ǰѡ����ָ�봫��
void doWork(Beverage* beverage) {
	beverage->makeDrink();
	// ����������������ֶ��ͷ���---ע����ֻ���ͷ��˶���ָ��ָ��ط����ڴ棬�����ָ���������Ч
	delete beverage;
}


int main23() {

	doWork(new Coffee);	// �ڶ�������һ�� coffee ���󴫽�ȥ��new �࣬���ص���һ��ָ��
	// doWork(new Tea);
	cout << "-------------------------------" << endl;
	// ��������ʵ�����������ʹ���ֿ�
	Tea* tea = new Tea;
	// Beverage* tea = new Tea;	����дҲ���ԣ���ָ��������ǰ������Beverage��ֱ�Ӿ�ǿת�ˣ����õȵ���doWork���������ʱ����ǿת
	doWork(tea);
	return 0;
}