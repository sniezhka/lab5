#pragma once
#include "Header.h"
class Human{//абстрактний клас
protected:
	string surname;
	void SetSurname(string);
	string GetSurname();

public:
	virtual void who_is_this_man() = 0;//чиста віртуальна функція
	virtual void funcs(){
		cout << "Human func" << endl;
	}
	string name;
	void SetName(string);
	string GetName();
	Human(string, string, int);
	Human(string);
	Human(){};
	virtual ~Human(){//3 destructed(virtual)
		cout << "Object Human was destructed(virtual)" << endl;
	}

private:
	int age;
	void SetAge(int);
	int GetAge();
};