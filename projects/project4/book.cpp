//Dan Siegel
//Project 3
#include <iostream>
#include <cstring>
#include "book.h"

using namespace std;

Book::Book(){ 	
	id = 0;
	title = NULL;
	author = NULL;
	copies = 0;
	checkOuts = 0;
	holds = 0;
}

//Printing Functions
//Print All Variables 
const void Book::printBook(){
	cout << "-----" << id << "-----" << endl;
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Number of Copies: " << copies << endl;	
	cout << "Number of Check Outs: " << checkOuts << endl;
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

void Book::returnAuthor(char temporary[]){
	strcpy(temporary, author);
}

void Book::returnTitle(char temporary[]){
	strcpy(currentTitle, title);
	}

const void Book::returnAllVar(int &currentid, char currentTitle[], char currentAuthor[], int &currentCopies, int &currentCheckouts, int &currentHolds){
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
	if (title != NULL){
		delete title;
	}
	if (author != NULL){
		delete author;
	}
	title = new char[strlen(newTitle) + 1];
	strcpy(title, newTitle);
	author = new char[strlen(newAuthor) + 1];
	strcpy(author, newAuthor);
	copies = newCopies;
	checkOuts = newCheckOuts;
	holds = newHolds;	
}
//Change Checkouts
void Book::changeCheckouts(int newCheckOuts){
	checkOuts = newCheckOuts;
}
//changeHolds
void Book::changeHolds(int newHolds){
	holds = newHolds;
}


