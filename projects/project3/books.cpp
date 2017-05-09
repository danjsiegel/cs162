//Dan Siegel
//Project 3
#include <iostream>
#include <cstring>
#include "books.h"

using namespace std;

books::books(){ //constructor
	
}

//Printing Functions
//Print All Variables 
void books::printBook(){
	cout << "-----" << id << "-----" << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Number of Copies: " << copies << endl;
	cout << "Number of Holds: " << holds << endl;
	cout << "-------------------------" << endl;
}
//Return functions
//Return ID
int books::returnID(){
	return id; 
}

void books::returnAllVar(int &currentid, char currentTitle[], char currentAuthor[], int &currentCopies, int &currentCheckouts, int &currentHolds){
	currentid = id;
	strcpy(currentTitle, title);
	strcpy(currentAuthor, author);
	currentCopies = copies;
	currentCheckouts = checkOuts;
	currentHolds = holds;	
	
}
//void books::returnAllBookVariables(){}
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
//change Title
void books::changeTitle(char newTitle[]){
	strcpy(title, newTitle);
}
//change Author
void books::changeAuthor(char newAuthor[]){
	strcpy(author, newAuthor);
}
//ChangeCopies
void books::changeCopies(int newCopies){
	copies = newCopies;
}
//Change Checkouts
void books::changeCheckouts(int newCheckOuts){
	checkOuts = newCheckOuts;
}
//changeHolds
void books::changeHolds(int newHolds){
	holds = newHolds;
}


