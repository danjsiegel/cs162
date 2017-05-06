#include <iostream>
#include <cstring>
#include "books.h"

using namespace std;

books::books(){ //constructor
	
}

//Printing Functions
void printBook(){
	
}

//mutator functions:
//Assign all data to a book
void books::assignBook(int newID, char newTitle[], char newAuthor[], int newCopies, int newCheckOuts, int newHolds){
	id = newID; 
	strcpy(title, newTitle);
	strcpy(author, newAuthor);
	copies = newCopies;
	checkOuts = newCheckOuts;
	holds = newHolds;	
	}

