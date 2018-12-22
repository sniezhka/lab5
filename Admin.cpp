#pragma once
#include "Header.h"
#include "Admin.h"
#include"Book.h"
#include "Reader.h"

Admin::Admin(string name, string surname, string work, int cardnumber, int salary, int age, int premium) :Human(name, surname, age){//конструктор
	this->work = work;
	this->cardnumber = cardnumber;
	this->salary = salary;
	this->premium = premium;
	this->SetWallet(0);
}
Admin::Admin(string name) :Human(name){//конструктор
}
void Admin::AddToBlackList(Book book){// додати невиплачене замовлення до чорного списку
	cout << "Замовлення додано в чорний список" << endl;
}
void Admin::SetName(){
	this->name = "Anonym";
}
void Admin::AddBook(string author, string name, int year, int number_of_pages, int price, int code){//додати нової книги
	Book book(author, name, year, number_of_pages, price, code); //item 3 //item 6
	ofstream file("Books.data", ios::app);//item 5

	file.write((char *)&book, sizeof(Book));
	file.close();
}
void Admin::ClassName(){// item 4 //повернення classname
	cout << typeid(*this).name();
}
string Admin::GetName(){
	return name;
}
void Admin::SetName(string name){
	this->name = name;
}
void Admin::PayForBook(int cardnumber, int price, int money){ //отримання грошей за замовлення
	if (cardnumber == this->cardnumber){
		if (money >= price){
			money -= price;
			this->wallet += price;
			cout << "Ваше замовлення сплачено\n";
		}
		else{
			cout << "Ви не маєте достатньо грошей\n";
		}
	}
	else{
		cout << "Номер картки не правильний\n";
	}
}
void ChangeWork(Admin &ob){//10 дружня ф-ія
	ob.work = "Senioradmin";
}
void Admin::ReadToFile(Book*book, int n){
	try{
		ifstream file("Books.data");
		file.exceptions(ifstream::badbit | ifstream::failbit);

		for (int i = 0; i < n; i++){
			file.read((char *)&book[i], sizeof(book));
		}
		file.close();
	}
	catch (const std::exception &ex){
		cout << "Error" << endl;
	}


}
