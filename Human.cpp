#include "Header.h"
#include "Human.h"

Human::Human(string name, string surname, int age){
	this->name = name;
	this->surname = surname;
	this->age = age;
}
Human::Human(string name){
	this->name = name;
}
void Human::SetName(string name){
	this->name = name;
}
void Human::SetSurname(string surname){
	this->surname = surname;
}
void Human::SetAge(int age){
	this->age = age;
}
string Human::GetName(){
	return name;
}
string Human::GetSurname(){
	return surname;
}
int Human::GetAge(){
	return age;
}