#include "Header.h"
#include "Admin.h"
#include "Reader.h"
#include "Book.h"
#include "Seller.h"
#include"Bookstore.h"
using namespace std;
int i = 0;
void SalaryNew(Admin admin);//13 перевантаженння
void SalaryNew(Admin* &admin);//14
int Admin::salary;
int Admin::premium;
int Admin::wallet;
int Book::object_count;
int main() {
	setlocale(LC_ALL, "Ukrainian");

	Human* ptr = new Seller;
	ptr->who_is_this_man;
	delete ptr;
	ptr = new Admin;
	ptr->who_is_this_man;
	delete ptr;

	Admin admin("John", "Mcgill", "Young admin", 456783, 5000, 24, 650);
	Seller seller;
	Human*ptr;
	ptr = &admin;
	ptr->who_is_this_man;
	ptr = &seller;
	ptr->who_is_this_man;
	delete ptr;

	Reader reader("Walter", "White", 1111, 2000, 1234, 24);

	Admin*ptr = &admin;
	ptr->who_is_this_man;
	ptr = (Admin*)&reader;
	ptr->who_is_this_man;
	bool active = true;
	Human* human = new Admin;//робота віртуального деструктора 3
	delete human;
	Human*man;
	man = new Admin;//10 пізнє зв'язування
	man->funcs();
	delete man;
	Human*funcс;
	funcс = new Admin;//10 раннє зв'язування
	funcс->GetName();
	delete funcс; 

	while (active) {
		int choose = 0;
		cout << "Авторизація:\nАдмін - введіть 1\nКористувач - введіть 2" << endl;;
		try{
			Admin *admin = new Admin("John", "Mcgill", "Young admin", 456783, 5000, 24, 650);
			if (admin == NULL){
				throw(Admin::admin_creating());
			}
			admin->Business_card();
			admin->funcs();
			admin->Human::funcs();//11
			Seller seller("ManagerName", "ManagerSurname", 27, 123456);
			seller.cardnumber = 1000;
			/*	Admin *p = &admin;*/

		

			Admin::SetWallet(0);
			cin >> choose;
			if (choose == 1) {
				choose = 0;
				cout << "Введіть кількість книг, які хочете додати\n";
				int count;
				cin >> count;
				for (; i < count; i++){
					admin->AddBook("Ritchi", "C++", 2114, 89, 1999, i);
				}

			}
			else if (choose == 2) {
				Reader *reader = new Reader("Walter", "White", 1111, 2000, 1234, 24);
				if (reader == NULL){
					throw(Reader::reader_creating());
				}
				cout << "Що ви хочите: \nЗнайти книгу за назвою, введіть 1\nВибрати книгу зі списку, натисність 2" << endl;

				cin >> choose;
				if (choose == 1){
					choose = 0;
					//Book *books = new Book[i];//item 6 //item 7 //item 11
					string title;
					cout << "Введіть назву" << endl;
					cin >> title;
					Book book = reader->FindBook(*admin, i, title); //item 8 //item 10
					Seller *seller1= new Seller("ManagerName", "ManagerSurname", 27, 123456);
					Bookstore bookstore(admin, reader, seller1, book, "", "", 5, 9, 3467, 3, 7);

				}
				else if (choose == 2){
					choose = 0;
					Book *books = new Book[i];//item 6// item 7
					if (books == NULL){
						throw(Book::book_creating());
					}
					cout << "Count of added books " << Book::ObjectCount() << endl;//8
					reader->FindBook(books, *admin, i);
					for (int j = 0; j < i; j++){
						cout << "Number: " << j << endl;
						books[j].ShowBook();
					}
					cout << "Please, enter number of book what want" << endl;
					int number;
					cin >> number;
					if (number>i || number < 0){
						cout << "Wrong number" << endl;
					}
					else{
						reader->MakeOrder(books[number], *admin);
						delete reader;
						throw(Reader::reader_deleting());
						delete[] books;
						throw(Book::book_deleting());
						delete admin;
						throw(Admin::admin_deleting());
					}

				}
			}
			else{
				char response;
				cout << "Чи сподобалось вам обслуговування?";
				cin >> response;
				if (response == 'yes'){
					cout << "Зарплата з премією складатиме";
					SalaryNew(admin);//13-14
				}
				cout << "Вихід";
				active = false;
			}
		}

		catch (Admin::admin_creating){//5
			cout << "Admin wasn`t added!" << endl;
		}
		catch (Reader::reader_creating){
			cout << "Reader wasn`t added!" << endl;
		}
		catch (Book::book_creating){
			cout << "Book wasn`t added!" << endl;
		}
		catch (Admin::admin_deleting){//5
			cout << "Admin wasn`t deleted!" << endl;
		}
		catch (Reader::reader_deleting){
			cout << "Reader wasn`t deleted!" << endl;
		}
		catch (Book::book_deleting){
			cout << "Book wasn`t deleted!" << endl;
		}
	}

	getchar();
	getchar();
	return 0;
}
void SalaryNew(Admin  admin){//13
	cout << "Admin receives a salary " << admin.getSalary() + admin.GetPremium() << endl;
}

void SalaryNew(Admin* &admin){//14
	cout << "Admin receives a salary " << admin->getSalary() + admin->GetPremium() << endl;
}