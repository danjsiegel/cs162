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
	void updateBook();
	const void printAllBooks();
	const void searchByAuthor();
	const void searchByTitle();
	void updateFoundBook(int bookToUpdate);
	void checkOutBook(int bookToUpdate, int action);
	void holdBook(int bookToHold, int action);
	void writeFile();
  private:  
	int tempID, tempCopies, tempCheckOuts, tempHolds, numberOfBooks; 
	Book *booklist;
	bool found;
		
};

#endif
