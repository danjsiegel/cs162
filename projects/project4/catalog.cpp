//Dan Siegel
//Project 4
//Implementation File for Catalog Class

#include <iostream>
#include <fstream>
#include <cstring>
#include "catalog.h"
#include "book.h"

using namespace std; 

Catalog::Catalog(){ //constructor
	numberOfBooks = 0;
	ifstream libraryBooks("library.txt");
	if(libraryBooks){ //if file opens correctly, read in contents. 
		libraryBooks >> numberOfBooks;
		booklist = new Book[numberOfBooks];
		char *tempTitle = new char[250];
		char *tempAuthor = new char[250];
		for (int i = 0; i < numberOfBooks; i++){
			libraryBooks >> tempID;
			libraryBooks.clear();
			libraryBooks.ignore(100, '\n');
			libraryBooks.getline(tempTitle, 250, '\n');
			libraryBooks.getline(tempAuthor, 250, '\n');
			libraryBooks.clear();
			libraryBooks >> tempCopies >> tempCheckOuts >> tempHolds; 
			(booklist+i)->assignBook(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		}
		delete tempTitle;
		delete tempAuthor;
	} else {
			cout << "No library.txt" << endl;
		}
	libraryBooks.close();
}
Catalog::~Catalog(){
	delete [] booklist;
}	
const void Catalog::printAllBooks(){
	cout << "%%%%%% Book Catalog %%%%%%" << endl;
	for (int i = 0; i < numberOfBooks; i++){
	(booklist+i)->printBook();
	}
}
void Catalog::writeFile(){
	ofstream newLibrary("library.txt");
	newLibrary << numberOfBooks << '\n';
	for (int i=0; i < numberOfBooks; i++){
		char *tmpt = new char[250];
		(booklist+i)->returnTitle(tmpt);
		char *tmpa = new char[250];
		(booklist+i)->returnAuthor(tmpa);
		newLibrary << (booklist+i)->returnID() << '\n' << tmpt << '\n' << tmpa << '\n' << (booklist+i)->returnCopies() << '\n' << (booklist+i)->returnCheckOuts() << '\n' << (booklist+i)->returnHolds() << '\n';
		delete tmpt;
		delete tmpa;
	}
	cout << "*** Catalog Written Out ***" << endl;
	newLibrary.close();
}
const void Catalog::searchByAuthor(){
	cin.clear();
	cin.ignore();
	found = false; 
	char *tempAuthor = new char[250];
	cout << "Name of Author" << endl;
	cin.getline(tempAuthor, 250, '\n');
	for (int i = 0; i < numberOfBooks; i++){
		char *temp = new char[250];
		(booklist+i)->returnAuthor(temp);
		if (strcmp(tempAuthor, temp) == 0){
			(booklist+i)->printBook();
			found = true;
		}
	delete temp, tempAuthor;
	}
	if (found == false){
	cout << "Author Not Found" << endl;
	
	}
}

const void Catalog::searchByTitle(){
	cin.clear();
	cin.ignore();
	bool found = false;
	char *tempTitle = new char[250];
	cout << "Name of Book" << endl;
	cin.getline(tempTitle, 250, '\n');
	for (int i = 0; i < numberOfBooks; i++){
		char *temp = new char[250];
		(booklist+i)->returnTitle(temp);
		if (strcmp(tempTitle, temp) == 0){
			(booklist+i)->printBook();
			found = true;
			break;
		} 
	delete temp, tempTitle;
	}
	if (found == false){
	cout << "Title Not Found" << endl;
	}
}
void Catalog::updateBook(){
	cout << "Enter id of Book or -1 to display all books: " << endl;
	int *actionToBook = new int[3];
	int *numberFound = new int[1];
	found = false;		
	cin >> actionToBook[0];
	if (actionToBook[0] == -1){			
		printAllBooks();
		cout << "Enter id of Book" << endl;	
		cin >> actionToBook[0];
	}	
	if (actionToBook[0] > 0) {			
		for (int i = 0; i < numberOfBooks; i++){			
			if (actionToBook[0] == (booklist+i)->returnID()){
				found = true;
				numberFound[0] = i;
				break;
			}
		}
	}	
	if (found == true){				
		updateFoundBook(numberFound[0]);
	} else {
		cout << "Book Not Found" << endl;		
	}
	delete actionToBook;
	delete numberFound;
}
void Catalog::checkOutBook(int bookToCheckOut, int action){
	if (action == 1 || action == 0){	
		(booklist+bookToCheckOut)->changeCheckouts(action);
		cout << "Book check Out action done" << endl;
	} else if (action == 2){
		(booklist+bookToCheckOut)->changeCheckouts(0);
	}
}
void Catalog::holdBook(int bookToHold, int action){
	if (action == 1 || action == 0){	
		(booklist+bookToHold)->changeHolds(action);
		cout << "Hold Action Done" << endl;
	} 
}
void Catalog::updateFoundBook(int bookToUpdate){
		cout << "What would you like to do?\n 1-Checkout Book\n 2-Return Book\n 3-Hold Book\n 4-Remove Hold" << endl;
		int actionToBook;
		cin >> actionToBook; 
		switch (actionToBook) {
			case 1:
				if ((booklist+bookToUpdate)->returnCopies() > (booklist+bookToUpdate)->returnCheckOuts()){
					checkOutBook(bookToUpdate, 1);	
				} else {
					cout << "All copies checked out, do you want to place on hold?" << endl;
					cout << "Enter 1 to add a new hold, enter 2 to skip" << endl;
					cin >> actionToBook;
					holdBook(bookToUpdate, actionToBook);					
				}
				break;
			case 2:
				if ((booklist+bookToUpdate)->returnCheckOuts() >= 1){
					checkOutBook(bookToUpdate, 0);						
				} else {
					cout << "Double check that you still have the book checked out" << endl;
				}
				break;
			case 3:
				if ((booklist+bookToUpdate)->returnCopies() > (booklist+bookToUpdate)->returnCheckOuts() && (booklist+bookToUpdate)->returnHolds() >= 5){
					cout << "Copies available Do you Want to Checkout Instead? 1 to checkout any other number to hold" << endl;
					cin >> actionToBook;					
					if (actionToBook == 1){
						checkOutBook(bookToUpdate, 1);
					} else {
						holdBook(bookToUpdate, 1);	
					}
				} else if ((booklist+bookToUpdate)->returnHolds() >= 5){
					cout << "Maximum holds reached, check back in soon" << endl;			
				} else {
					holdBook(bookToUpdate, 1);	
				}
				break;
			case 4:
				if ((booklist+bookToUpdate)->returnHolds() >= 1){							
					holdBook(bookToUpdate, 0);	
				} else {
					cout << "No holds to remove" << endl;
				}
				break;
			default:
				cout << "Invalid selection" << endl;
				cin.clear();
				cin.ignore(100, '\n'); 
				break; 
		}	
}
void Catalog::activity(int uActivity){
	switch(uActivity){
		case 1: 
			printAllBooks();
			break;
		case 2:
			searchByTitle();
			break;
		case 3:
			searchByAuthor();
			break;
		case 4: 
			updateBook();
			break;
		case 5:
			writeFile();
			cout << "Deleting Booklist, Goodbye" << endl; 
			break;
		default:
			cin.clear();
			cin.ignore();
			cout << "invalid selection" << endl; 
			break; 
	}
}
void Catalog::menu(){
	cout << "\n*********"  << "Main Menu" << "*********" << endl;
	cout << "1 - Print Catalog\n" << "2 - Search by Title\n" << "3 - Search By Author\n" << "4 - Do Action\n" << "5 - Quit\n " << endl;
	
	
}


