//Dan Siegel
//Project 3
//Header File for Catalog Class
#ifndef CATALOG_H
#define CATALOG_H
#include "books.h"


class books; 

class catalog {
  public:
	catalog();
    void menu();
	void printAllBooks();
	void newBook();
	void idCompare(int bookNumber, bool &foundflag, int userNumber, int tempCompare, int &bookFoundAn);
	void updateBook();
	void writeFile();
  private:
	char tempTitle[250];
	char tempAuthor[250];   
	int tempID, tempCopies, tempCheckOuts, tempHolds;
	int numberOfBooks; 
	books booklist[100];
		
};

#endif
