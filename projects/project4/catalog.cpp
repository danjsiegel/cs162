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
	} else {
			cout << "No library.txt" << endl;

		}
}
Catalog::~Catalog(){
	delete booklist;
}	
const void Catalog::printAllBooks(){
	cout << "%%%%%% Book Catalog %%%%%%" << endl;
	for (int i = 0; i < numberOfBooks; i++){
	(booklist+i)->printBook();
	}
}

const void Catalog::searchByAuthor(){
	cin.clear();
	cin.ignore();
	bool found = false; 
	cout << "Name of Author" << endl;
	cin.getline(tempAuthor, 250, '\n');
	for (int i = 0; i < numberOfBooks; i++){
		int equal;
		char *temp = new char[250];
		(booklist+i)->returnAuthor(temp);
		equal = strcmp(tempAuthor, temp);
		if (equal == 0){
			(booklist+i)->printBook();
			found = true;
		} 
	if (found == false){
		cout << "Author Not Found" << endl;
	}
	delete temp;
	}
}

void Catalog::activity(int uActivity){
	switch(uActivity){
		case 1: 
			printAllBooks();
			break;
		case 2:
			
		case 3:
			searchByAuthor();
			break;/*
		case 4:*/
		case 5:
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


