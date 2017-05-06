//Header File for Catalog Class
#ifndef CATALOG_H
#define CATALOG_H
#include "books.h"


class books; 

class catalog {
  public:
	catalog();//constructor
    void menu();
  private:
	char* library;    
	int maxBooks;
	int numberOfBooks; 
};

#endif
