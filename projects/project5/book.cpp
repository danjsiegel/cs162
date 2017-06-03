//Dan Siegel
//Project 3
#include <iostream>
#include <cstring>
#include "book.h"

using namespace std;

Book::Book(){ 	
	id = 0;
	strcpy(title, "\0");
	strcpy(author, "\0");
	copies = 0;
	checkOuts = 0;
	holds = 0;
}
Book::~Book(){

}

//Printing Functions
//Print All Variables 
void Book::printBook(){
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
int Book::returnCopies(){
	return copies; 
}

void Book::returnTitle(char returnTitle[]){
	strcpy(returnTitle, title);
}
char Book::returnAuthor(){
	//return author;
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
/*change Title
void Book::changeTitle(char newTitle[]){
	strcpy(title, newTitle);
}*/
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


