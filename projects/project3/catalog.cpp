//Implementation File for Catalog Class
#include <iostream>
#include <fstream>
#include <cstring>
#include "catalog.h"
#include "books.h"

using namespace std; 

catalog::catalog(){ //constructor

	ifstream libraryBooks("library.txt");
	libraryBooks >> numberOfBooks;
	for (int i = 0; i < numberOfBooks; i++){
		libraryBooks >> tempID;
		libraryBooks.clear();
		libraryBooks.ignore(100, '\n');
		libraryBooks.getline(tempTitle, 250, '\n');
		libraryBooks.getline(tempAuthor, 250, '\n');
		libraryBooks.clear();
		libraryBooks >> tempCopies >> tempCheckOuts >> tempHolds; 
		booklist[i].assignBook(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
	}
}

void catalog::printAllBooks(){
	cout << "%%%%%% Book Catalog %%%%%%" << endl;
	for (int i = 0; i < numberOfBooks; i++){
	booklist[i].printBook();
	}
}
void catalog::menu(){
	cout << "\n*********"  << "Main Menu" << "*********" << endl;
	cout << "1 - Print Catalog\n" << "2 - Add New Book\n" << "3 - Modify a Book\n" << "4 - Quit\n" << "Enter choice: " << endl;
}

void catalog::updateBook(){
	int bookToModify, updateAction, tempIDtoCompare, newID, bookFound;	
	bool bookFound = false;
	bool updateIDvalid = false;  
	do {
		cout << "enter ID of book: (or enter -1 to see a list of books) or 0 to exit";
		cin >> bookToModify;
		idCompare(numberOfBooks, bookFound, bookToModify, tempIDtoCompare, bookFound);
	
		while (bookFound == true && updateAction != 7){
			cout << "Which field to change?\n" << "1 - ID\n" << "2 - Title\n" << "3 - Author\n" << "4 - Copies\n" << "5 - Checkouts\n" << "6 - Holds\n" << "7 - Quit" << endl;
			cin >> updateAction;		
			switch(updateAction){
				case 1:
					cout << "New Book ID? ";
					cin >> newID;
					
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					break;
				case 7:
					break;
				default:
					cout << "Invalid Entry" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					break; 
			}
		} 
		if (bookToModify == -1){
			printAllBooks();
		} else if(updateAction == 7 || bookToModify == 0) {
			break;	
		}else {
			cout << "Invalid Entry" << endl;
			cin.clear();
			cin.ignore(100, '\n');	
		}
	} while(updateAction != 7 || bookToModify != 0);
}
void catalog::newBook(){
	int requestedID, tempCompareID, foundAt;
	bool idExists = false;	
	cout << "ID of book? ";
	cin >> requestedID;
	while (!cin || (requestedID < 0)){
		cout << "invalid entry" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ID of book? ";
		cin >> requestedID;
	}
	idCompare(numberOfBooks, idExists, requestedID, tempCompareID, foundAt);
	while (idExists == true){
		cin >> requestedID;
		idExists = false;
		idCompare(numberOfBooks, idExists, requestedID, tempCompareID, foundAt);
		if (idExists == true){
			cout << "ID already taken. Enter unique ID. " << endl;
		}
	}
	
	tempID = requestedID;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Title of book?"; 
	cin.getline(tempTitle, 250);
	cout << "Author name?";
	cin.getline(tempAuthor, 250);
	cout << "Number of copies?";
	cin >> tempCopies;
	while (!cin || tempCopies <= 0){
		cout << "Invalid number of copies" << endl;
		cout << "Number of copies? ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempCopies;	
	}
	tempCheckOuts = 0;
	tempHolds = 0;

	booklist[numberOfBooks].assignBook(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
	numberOfBooks++;
}

void catalog::idCompare(int bookNumber, bool &foundflag, int userNumber, int tempCompare, int &bookFoundAn){
	for (int i = 0; i < bookNumber; i++){
		tempCompare = booklist[i].returnID();
		if (tempCompare == userNumber){
			foundflag = true;
			bookFoundIn = i;
			break;
		}
	}
}
