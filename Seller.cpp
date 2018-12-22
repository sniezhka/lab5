#include "Header.h"
#include "Human.h"
#include "Seller.h"

Seller::Seller(string name, string surname, int age, int cardnumber) : Human(name, surname, age){//11
	this->cardnumber = cardnumber;
}