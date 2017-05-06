//Implementation File for Catalog Class
#include <iostream>
#include <fstream>
#include "catalog.h"
#include "books.h"


class catalog {
  public:

    catalog::catalog(){ //constructor
      ifstream libraryBooks(libraryfile);
      libraryBooks.open();
      int count;
      libraryBooks >> count;
      while (!libraryBooks.eof()){
        count++;
      }
    }
    void catalog::menu(){
      cout << "\n*********"  << "Main Menu" << "*********" << endl;
		  cout << "1 - Print Catalog\n" << "2 - Add New Book\n" << "3 - Modify a Book\n" << "4 - Quit\n" << "Enter choice: " << endl;
    }
    void catalog::writeToFile(){

    }

  private:
    const char libraryfile = 'library.txt'
    const int maxBooks = 100;
    books booklist[maxBooks]; //Declares array of class books
};
