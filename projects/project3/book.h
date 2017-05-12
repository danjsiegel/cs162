//Dan Siegel
//Project 3
//Header File for Book Class
#ifndef BOOK_H
#define BOOK_H

class Book {
  public:
    void book();
	void assignBook(int newID, char newTitle[], char newAuthor[], int newCopies, int newCheckOuts, int newHolds);
	void printBook();
	void changeID(int newID);
	void changeTitle(char newTitle[]);
	void changeAuthor(char newAuthor[]);
	void changeCopies(int newCopies);
	void changeCheckouts(int newCheckOuts);
	void changeHolds(int newHolds);
	int returnID();
	void returnAllVar(int &currentid, char currentTitle[], char currentAuthor[], int &currentCopies, int &currentCheckouts, int &currentHolds);
  private:
	int id;
    char title[250];
    char author[250];
    int copies;
    int checkOuts;
    int holds;
};

#endif
