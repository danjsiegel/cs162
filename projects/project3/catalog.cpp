//Implementation File for Catalog Class
#include <iostream>
#include <fstream>
#include <cstring>
#include "catalog.h"
#include "books.h"

using namespace std; 

catalog::catalog(){ //constructor
	int tempID, tempCopies, tempCheckOuts, tempHolds;
	char tempTitle[250];
	char tempAuthor[250];	
	ifstream libraryBooks("library.txt");
	maxBooks = 100;
	books booklist[maxBooks];
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

void printAllBooks(){
	cout << "%%%%%% Book Catalog %%%%%%" << endl;
	for (int i = 0; i < numberOfBooks; i++){
	booklist[i].printBook;
	}
}
void catalog::menu(){
	cout << "\n*********"  << "Main Menu" << "*********" << endl;
	cout << "1 - Print Catalog\n" << "2 - Add New Book\n" << "3 - Modify a Book\n" << "4 - Quit\n" << "Enter choice: " << endl;
}
    //void catalog::writeToFile(){

    //}


