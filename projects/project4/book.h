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
	int returnCheckOuts();
	int returnHolds();
	void returnTitle(char temporary[]);
	void returnAuthor(char emporary[]);
  private:
	int id;
    char *title;
    char *author;
    int copies;
    int checkOuts;
    int holds;
};

#endif
