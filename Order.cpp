#include "Header.h"
#include "Reader.h"
#include "Book.h"
#include "Order.h"
#include "Admin.h"
using namespace std;
Order::Order(Book book, Reader &reader, Admin &admin, string date){
	this->book = &book;
	this->reader = reader;
	this->admin = admin;
	this->date = date;
}
void Order::setBook(Book book){
	this->book = &book;
}
void Order::setReader(Reader reader){
	this->reader = reader;
}
void Order::setDate(string date){
	this->date = date;
}
void Order::MakeOrder(Admin admin){
	ofstream file("Orders.data", ios::app);
	file.write((char *)&(*this), sizeof(*this));
	file.close();
	cout << "Order was made!\n" << endl;

	char yes_or_no;
	int how_many_times = 0;
	cout << "Do you want pay order? y/n\n";
tryagain:
	cin >> yes_or_no;
	if (yes_or_no == 'y'){
		this->PayOrder(admin.cardnumber, book->GetPrice(), reader.money, admin);
	}
	else if (yes_or_no == 'n'){
		cout << "Your order wasn`t pay\n";
		admin.AddToBlackList(*book);
	}
	else{
		cout << "Try again pls";
		if (how_many_times<3){
			goto tryagain;
		}
		else{
			admin.AddToBlackList(*book);
		}
	}
}
void Order::PayOrder(int cardnumber, int price, int money, Admin admin){
	if (cardnumber == admin.cardnumber){
		money -= price;
		admin.SetWallet(price);
		cout << "Your order was succesfully payed\n";
	}
}