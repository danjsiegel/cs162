//Dan Siegel
//Project 3
#include <iostream>
#include <cstring>
#include "Book.h"

using namespace std;

Book::book(){ //constructor
	
}

//Printing Functions
//Print All Variables 
void book::printBook(){
	cout << "-----" << id << "-----" << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Number of Copies: " << copies << endl;
	cout << "Number of Holds: " << holds << endl;
	cout << "-------------------------" << endl;
}
//Return functions
//Return ID
int Book::returnID(){
	return id; 
}

void Book::returnAllVar(int &currentid, char currentTitle[], char currentAuthor[], int &currentCopies, int &currentCheckouts, int &currentHolds){
	currentid = id;
	strcpy(currentTitle, title);
	strcpy(currentAuthor, author);
	currentCopies = copies;
	currentCheckouts = checkOuts;
	currentHolds = holds;	
	
}
//void Book::returnAllBookVariables(){}
//mutator functions:
//Assign all data to a book
void Book::assignBook(int newID, char newTitle[], char newAuthor[], int newCopies, int newCheckOuts, int newHolds){
	id = newID; 
	strcpy(title, newTitle);
	strcpy(author, newAuthor);
	copies = newCopies;
	checkOuts = newCheckOuts;
	holds = newHolds;	
}
//change ID
void Book::changeID(int newID){
	id = newID;
}
//change Title
void Book::changeTitle(char newTitle[]){
	strcpy(title, newTitle);
}
//change Author
void Book::changeAuthor(char newAuthor[]){
	strcpy(author, newAuthor);
}
//ChangeCopies
void Book::changeCopies(int newCopies){
	copies = newCopies;
}
//Change Checkouts
void Book::changeCheckouts(int newCheckOuts){
	checkOuts = newCheckOuts;
}
//changeHolds
void Book::changeHolds(int newHolds){
	holds = newHolds;
}


