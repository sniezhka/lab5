#pragma once
#include "Admin.h"
#include "Book.h"
#include "Reader.h"
#include "Header.h"
#include"Seller.h"

using namespace std;
class Bookstore{
	string name;
	string address;
	int department_number;
	int numbers_of_workers;//кількість роботодавців
	int numbers_of_clients;//кількість клієнтів
	int level;//рівень
	int years_of_works;// рік роботи
	Admin* admins;
	Reader* reader;
	Book book;
	Seller* seller;
public:
	Bookstore(Admin* admins, Reader* reader, Seller*seller, Book book, string name, string address, int department_number, int numbers_of_workers, int numbers_of_clients, int level, int years_of_works){
		this->admins = admins;
		this->reader = reader;
		this->seller = seller;
		this->book = book;
		this->name = name;
		this->address = address;
		this->department_number = department_number;
		this->numbers_of_workers = numbers_of_workers;
		this->numbers_of_clients = numbers_of_clients;
		this->level = level;
		this->years_of_works = years_of_works;
	};
	~Bookstore(){
		cout << "Object Bookstore was destructed" << endl;
	};
	Bookstore Bookstore:: operator++(){// 1 перевантаження ++
		years_of_works++;
		level++;
		return *this;
	}
	Bookstore Bookstore:: operator--(){// 1 перевантаження --
		numbers_of_workers--;
		numbers_of_clients--;
		return *this;
	}
	int Bookstore::operator+(Bookstore op){// 2 перевантаження +
		int temp = op.numbers_of_workers + numbers_of_workers;
		return temp;
	}
	int operator-(Bookstore op){// 2 перевантаження -

		int temp = numbers_of_workers - op.numbers_of_workers;
		return temp;
	}
	Bookstore operator*(Bookstore op){// 3 перевантаження *
		Bookstore temp;
		temp.level = op.level*level;
		return temp;
	}
	Bookstore operator=(Bookstore op){// 3 перевантаження =
		name = op.name;
		return *this;
	}
	Bookstore operator+=(Bookstore op){// 3 перевантаження +=
		numbers_of_workers += op.numbers_of_workers;
		return *this;
	}
	Bookstore operator-=(Bookstore op){// 3 перевантаження -=
		numbers_of_workers -= op.numbers_of_workers;
		return *this;
	}
	Bookstore operator*=(Bookstore op){// 3 перевантаження *=
		level *= op.level;
		return *this;
	}
	void operator[](int i){// 3 перевантаження []
		if (numbers_of_clients > i) {
			level++;
		}
	}
	explicit Bookstore(){};
	int getDepartment_number(){
		return department_number;
	}
	string getName(){
		return name;
	}
	string getAddress(){
		return address;
	}
	template<class T>// 4 шаблон для макс значення
	const T& Max(const T& a, const T& b){
		return a > b ? a : b;
	}
	int getLevel(){
		return level;
	}


};