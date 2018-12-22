#pragma once
#include "Header.h"
#include"Human.h"
#include "Book.h"
#include"Admin.h"

class Reader : public Human{//item 2
	int cardnumber;
	int id;
public:
	class reader_creating{};
	class reader_deleting{};
	int money;
	Reader(string, string, int, int, int, int);//конструктор
	Reader(){};
	Reader(const Reader &obj)//4
	{
	}
	~Reader(){
		cout << "Object Reader was destructed" << endl;
	}
	void funcs(){
		cout << "Reader func" << endl;
	}
	string GetName();
	void SetName(string);
	void SetName();
	int Money_(){ return money - 1; }
	virtual void Money(){//4
		cout << Reader::Money_();
	}
	Book FindBook(Admin, int, string);
	 void who_is_this_man() { cout << "Читач" << endl; };//реалізація 2
	void FindBook(Book *, Admin, int, string);//метод шукає книги за назвою
	void FindBook(Book *, Admin, int);//метод для виведення всіх книг
	void MakeOrder(Book, Admin);//метод для замовлення вибраної книги
	int getСardnumber();
	friend class ReaderStatus;//11 дружній клас
};
class ReaderStatus{//11
	string status;
public:
	ReaderStatus();
	void setStatus(Reader &ob){
		if (ob.getСardnumber() % 2 == 0){
			status = "twin";
		}
		else{
			status = "not twin";
		}
	}

};