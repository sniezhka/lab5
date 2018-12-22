#pragma once
#include "Header.h"
using namespace std;
class  Book
{
	int price;
	int number_of_pages;
	string title;
	string author;
	int year;
	static int object_count;//8
public:
	int code;
	class book_creating{};
	class book_deleting{};
	Book(string, string, int, int, int, int);//конструктор
	Book() :price(100), title("noname"){
		this->author = "Author";
		this->number_of_pages = 0;
		this->year = 0;
		if (!object_count){
			object_count = 1;
		}
		else{
			object_count++;
		}
	};//5
	~Book(){
		cout << "Object Book was destructed" << endl;
		object_count--;
	}
	static int ObjectCount(){//8
		return object_count;
	}
	int GetPrice();
	int GetNumberOfPages();
	int GetYear();
	string GetTitle();
	string GetAuthor();
	void SetPrice(int price);
	int SetYear();
	string SetTitle();
	void RandMemory();//виділення рандомої к-ті пам'яті під цілочисельний масив
	void ShowBook();
	void Service_Dinamic(Book *array, int &lenAr, int number){//6
		try{
			if (number > lenAr || number < 1)
			{
				throw(book_deleting());
			}

			for (int ix = number - 1; ix < lenAr - 1; ix++)
			{
				array[ix] = array[ix + 1];
			}
			delete[lenAr] array;
			lenAr--;
		}
		catch (book_deleting){
			cout << "Wrong number of element" << endl;
		}
	}
	void Service_Static(Book *array, int &lenAr, int number){//6
		try{
			if (number > lenAr || number < 1)
			{
				throw(book_deleting());
			}

			for (int ix = number - 1; ix < lenAr - 1; ix++)
			{
				array[ix] = array[ix + 1];
			}
			//delete[lenAr] array;
			lenAr--;
		}
		catch (book_deleting){
			cout << "Wrong number of element" << endl;
		}

	}
};