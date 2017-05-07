//Dan Siegel
//Project 2
#include <iostream>
#include <fstream>
#include <cstring>
#include "books.h"
#include "catalog.h"


using namespace std;

void callFunction(int selection, catalog& usersClass){
	switch(selection){
		case 1:	usersClass.printAllBooks(); //print catalog 
				break;
		case 2:	usersClass.newBook();//add new book	
		case 3:	
			usersClass.updateBook();
			break; /*
		case 4: */ //quit and write to file
	}
}

int main() {
	int choice;
	catalog catalog1;
	do {
		catalog1.menu();
		cin >> choice; 
		if (choice > 0 && choice < 5){
			callFunction(choice, catalog1);
			if (choice != 4){
				cin.clear();
				cin.ignore();
			}
		} else {
			cout << "invalid selection, try again" << endl;
			cin.clear();
			cin.ignore();
		}

	} while (choice != 4);

	return 0;
}
