//Header File for Books Class
#ifndef BOOKS_H
#define BOOKS_H

class books {
  public:
    books();
	void assignBook(int newID, char newTitle[], char newAuthor[], int newCopies, int newCheckOuts, int newHolds);
	void printBooks(int numberOfBooks);
  private:
	int id;
    char title[250];
    char author[250];
    int copies;
    int checkOuts;
    int holds;
};

#endif
