//Dan Siegel
//Project 3
//Header File for Book Class
#ifndef BOOK_H
#define BOOK_H

class Book {
  public:
    Book();
	void assignBook(int newID, char newTitle[], char newAuthor[], int newCopies, int newCheckOuts, int newHolds);
	const void printBook();
	void changeCheckouts(int newCheckOuts);
	void changeHolds(int newHolds);
	int returnID();
	int returnCopies();
	const char returnTitle();
	void returnAuthor(char emporary[]);
	const void returnAllVar(int &currentid, char currentTitle[], char currentAuthor[], int &currentCopies, int &currentCheckouts, int &currentHolds);
  private:
	int id;
    char *title;
    char *author;
    int copies;
    int checkOuts;
    int holds;
};

#endif
