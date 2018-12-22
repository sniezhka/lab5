#pragma once
#include "Header.h"
#include"Admin.h"
#include"Reader.h"
#include"Order.h"
#include"Book.h"

Reader::Reader(string name, string surname, int cardnumber, int money, int id, int age) :Human(name, surname, age){
	this->cardnumber = cardnumber;
	this->money = money;
	this->id = id;
}

void Reader::MakeOrder(Book book, Admin admin){
	Order order(book, *this, admin, "11.11");
	order.MakeOrder(admin);
}
void Reader::FindBook(Book *mass, Admin admin, int count, string title){
	ifstream file("Books.data");//item 5
	bool is_exist = 0;
	char yes_or_no;
	for (int i = 0; i < count; i++){
		file.read((char *)&mass[i], sizeof(Book));
		if (mass[i].GetTitle() == title){
			cout << "Ви хочете зробити замовлення? y/n\n";
			cin >> yes_or_no;
			if (yes_or_no == 'y'){
				MakeOrder(mass[i], admin);
				is_exist = 1;
				break;
			}
			else break;
		}
	}
	file.close();
	if (is_exist != 1){
		cout << "На жаль, ми не маємо цієї книги";
	}
}
Book Reader::FindBook(Admin admin, int count, string title){//15
	Book *mass = new Book[count];
	ifstream file("Books.data");//item 5
	bool is_exist = 0;
	for (int i = 0; i < count; i++){
		file.read((char *)&mass[i], sizeof(Book));
		if (mass[i].GetTitle() == title){
			return mass[i];
			is_exist = 1;
		}
	}
	file.close();
	if (is_exist){
		cout << "We are sorry, but we haven`t this book";
	}
}
void Reader::FindBook(Book *mass, Admin admin, int count){
	ifstream file("Books.data");//item 5
	for (int i = 0; i < count; i++){
		file.read((char *)&mass[i], sizeof(Book));
	}
	file.close();
}
string Reader::GetName(){
	return name;
}
void Reader::SetName(string name){
	this->name = name;
}
int Reader::getСardnumber(){
	return cardnumber;
}