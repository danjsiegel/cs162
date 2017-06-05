//Dan Siegel
//Project 3
//Header File for Catalog Class
#ifndef CATALOG_H
#define CATALOG_H
#include "book.h"


class Book; 

class Catalog {
	private:
		char tempTitle[250];
		char tempAuthor[250];   
		int tempID, tempCopies, tempCheckOuts, tempHolds, numberOfBooks; 
		struct Node{
			Book data;
			Node *next;
		};
		Node *head;
		Node *current;
		Node *temp;
		Node *previous;
		Node *deleteNode; 
	
	public:
		Catalog();
		~Catalog();
		void menu();
		void printList();
		void deleteBook(int ID);
		void menuSelection(int selection);
		void newBook();
		//void idCompare(int bookNumber, bool &foundflag, int userNumber, int tempCompare, int &bookFoundAn);
		void updateBook();
		void writeFile();
		void addToList(int id, char title[], char author[], int copies, int checkOuts, int holds);
		void newID();
		void changeTitle();
		void changeAuthor();
		void changeCopies();
};

#endif
