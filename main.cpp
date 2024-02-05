#include <iostream>

	//наследование
class Base
{
public:
	//конструктор по умолчанию -
	Base() : Base(0, 0, 0) {}
	// - делегирует обязанности конструктор с параметрами
	Base(int a, int b, int c) :a(a), b(b), c(c){} //при делегации мы можем указывать только на поля класса

	int a;
	int A() { return a; }
	int B() { return b; }
	int C() { return c; }
protected:

	int b;
private:

	int c;
};

class Derived : public Base //можем менять значение полей, но не сам класс и поля
{
public:
	Derived() = default;
	//конструктор с параметрами
	Derived(int a, int b, int c, int d):Base(a,b,c),d(d) //передали данные в конструктор родителя, и добавили дочернего d(d)
	{

	}
	int M00()
	{
		int res{};
		res = a + b; //свободно используем публичные поля и защищенные
		res /= C(); //приватные поля доступны через методы доступа внутри класса
		return res;
	}
	int D() { return d; }
private:
	int d;
};
//Задача 1
class Animal
{
public:
	int Age() const { return age_; }
	void Age(int newAge) { age_ = newAge; }

	void Name(std::string newName) { name_ = newName; }
	std::string Name()const { return name_; }

	virtual void Say()const //виртуальной опмечают функцию которая должна вызываться у наследников в момент их обработки под видом родителя
	{
		std::cout << "r.\n";
	}
private:
	std::string name_;
	int age_;

};
//перегрузка метода в наследнике
class Kat :public Animal
{
public:
	void Say()const override // - для доп проверки компилятором
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
	kat.Say(); //по умолчанию вызовет свою реализацию
	kat.Animal::Say(); //принудительно вызвали реализацию родителя
	Animal* p = &abs; //начало полиморфизма
	p = &kat;
	p->Say();


	return 0;
};