//Header File for Catalog Class
#include "books.h"
#ifndef CATALOG_H
#define CATALOG_H

class catalog {
  public:
    void menu(){
      cout << "\n*********"  << "Main Menu" << "*********" << endl;
		    cout << "1 - Print Catalog\n" << "2 - Search by Title\n" << "3 - Search by Author\n" << "4 - Do Action\n" << "5 - Quit\n" << "Enter choice: " << endl;
    }
  private:
    const char libraryfile = 'library.txt'
    const int maxBooks = 100;
    books booklist[maxBooks]; //Declares array of class books
};

#endif
