//Dan Siegel
//Project 4
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include "book.h"
#include "catalog.h" 

using namespace std;

int main() {
	int choice;
	Catalog tempCatalog;
	do {
		tempCatalog.menu();
		cin >> choice; 
		tempCatalog.activity(choice);
	
	} while (choice != 5);
	return 0;
}
