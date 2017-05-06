//Dan Siegel
//Project 2
#include <iostream>
#include <fstream>
#include <cstring>
#include "books.h"
#include "catalog.h"


using namespace std;

int main() {
	int choice;
	catalog catalog1;
	do {
		catalog1.menu();
		cin >> choice; 
		if (choice > 0 && choice < 5){
			cout << "invoke action functions and then display the menu" << endl;
			/*switch(choice):
				case 1:	//print catalog
				case 2:	//add new book	
				case 3:	//modify book
				case 4: */ //quit and write to file
		} else {
			cout << "invalid selection, try again" << endl;
		}
		cin.clear();
		cin.ignore();
	} while (choice != 4);

	return 0;
}
