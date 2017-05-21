//Dan Siegel
//Project 3
//Header File for Catalog Class
#ifndef CATALOG_H
#define CATALOG_H
#include "book.h"

class Book; 
class Catalog {
  public:
	Catalog();
	~Catalog();
    void menu();
	void activity(int uActivity);
	const void printAllBooks();
	const void searchByAuthor();
  private:
	char tempTitle[250];
	char tempAuthor[250];   
	int tempID, tempCopies, tempCheckOuts, tempHolds, numberOfBooks; 
	Book *booklist;
		
};

#endif
