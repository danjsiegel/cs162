#include <iostream>
#include <cstring>
#include "books.h"

using namespace std;

books::books(){ //constructor
	
}

//Printing Functions
void books::printBook(){
	cout << "-----" << id << "-----" << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Number of Copies: " << copies << endl;
	cout << "Number of Holds: " << holds << endl;
	cout << "-------------------------" << endl;
}
//Returning functions
//Return ID
int books::returnID(){
	return id; 
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
//change ID
void books::changeID(int newID){
	id = newID;
}
