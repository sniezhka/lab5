#pragma once
#include "Header.h"
#include "Admin.h"
#include "Human.h"

class Seller : private Admin, virtual public Human{//item 9, 10
public:
	using Admin::cardnumber;//12
	int money = 0;
	void funcs(){
		cout << "Seller func" << endl;
	}
	 void who_is_this_man() { cout << "Продавець" << endl; };//реалізація 2
	Seller(string, string, int, int);
	Seller(){};
	Seller(const Seller &obj)//4
	{
	}
	~Seller(){
		cout << "Object Seller was destructed\n";
	}
	//virtual double GetCardnumber() { return cardnumber; }//4

};