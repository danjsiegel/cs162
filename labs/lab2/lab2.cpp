#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;




int main() {
	int numOfBooks, action, tempID;
	ifstream bookList("library.txt");

	bookList >> numOfBooks;
	
	struct book {
		int id;
		char title[250];
		char author[250];
		int copies;
		int checkOuts;
		int holds;
	};
	for (int i = 0; i < numOfBooks; i++){
		bookList >> tempID;
		book tempID;
		book[tempID].id = tempID; 
		getline(bookList, book[tempID].title);
		getline(bookList, book[tempID].author);
		bookList >> book[tempID].copies;
		bookList >> book[tempID].checkOuts;
		bookList >> book[tempID].holds;	
	}

	do {
		cout <<"*"  << "Main Menu" << "*" << endl;
		cout << "1 - Print Catalog\n" << "2 - Search by Title\n" << "3 - Search by Author\n" << "4 - Do Action\n" << "5 - Quit\n" << "Enter choice: " << endl;
		cin >> action;

		switch (action){
		case 1:
			cout << "case1" << endl;
			break;
		case 2:
			cout << "case2" <<endl;
			break;
		case 3:
			cout << "case3" << endl;
			break;
		case 4:
			cout << "case4" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
		}
		if ((action > 5) || (!action) || (action < 1)){
			cout << "Invalid selection" << endl;
			cin.clear();
			cin.ignore(100, '\n'); 	
		}

	} while (action != 5);

	
	bookList.close();
	return 0;
}
