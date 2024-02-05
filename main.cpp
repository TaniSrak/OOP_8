#include <iostream>

	//������������
class Base
{
public:
	//����������� �� ��������� -
	Base() : Base(0, 0, 0) {}
	// - ���������� ����������� ����������� � �����������
	Base(int a, int b, int c) :a(a), b(b), c(c){} //��� ��������� �� ����� ��������� ������ �� ���� ������

	int a;
	int A() { return a; }
	int B() { return b; }
	int C() { return c; }
protected:

	int b;
private:

	int c;
};

class Derived : public Base //����� ������ �������� �����, �� �� ��� ����� � ����
{
public:
	Derived() = default;
	//����������� � �����������
	Derived(int a, int b, int c, int d):Base(a,b,c),d(d) //�������� ������ � ����������� ��������, � �������� ��������� d(d)
	{

	}
	int M00()
	{
		int res{};
		res = a + b; //�������� ���������� ��������� ���� � ����������
		res /= C(); //��������� ���� �������� ����� ������ ������� ������ ������
		return res;
	}
	int D() { return d; }
private:
	int d;
};
//������ 1
class Animal
{
public:
	int Age() const { return age_; }
	void Age(int newAge) { age_ = newAge; }

	void Name(std::string newName) { name_ = newName; }
	std::string Name()const { return name_; }

	virtual void Say()const //����������� �������� ������� ������� ������ ���������� � ����������� � ������ �� ��������� ��� ����� ��������
	{
		std::cout << "r.\n";
	}
private:
	std::string name_;
	int age_;

};
//���������� ������ � ����������
class Kat :public Animal
{
public:
	void Say()const override // - ��� ��� �������� ������������
	{
		std::cout << "mauw\n";
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	Base obj(1,2,5);
	obj.a;
	// obj.b;
	//obj.c;

	Derived dObj(1,2,4,7);
	dObj.B();

	Animal abs;
	abs.Name("Dog");
	abs.Age(1);
	abs.Say();
	Kat kat;
	kat.Name("Fluffy");
	kat.Age(3);
	kat.Say(); //�� ��������� ������� ���� ����������
	kat.Animal::Say(); //������������� ������� ���������� ��������
	Animal* p = &abs; //������ ������������
	p = &kat;
	p->Say();


	return 0;
};