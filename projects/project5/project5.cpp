//Dan Siegel
//Project 5
#include <iostream>
#include <fstream>
#include <cstring>
#include "book.h"
#include "catalog.h"


using namespace std;

int main() {
	int choice;
	Catalog catalog1;
	do {
		catalog1.menu();
		cin >> choice; 
		catalog1.menuSelection(choice);
	} while (choice != 5);
	return 0;
}
