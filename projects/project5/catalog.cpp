//Dan Siegel
//Project 3
//Implementation File for Catalog Class

#include <iostream>
#include <fstream>
#include <cstring>
#include "catalog.h"
#include "book.h"

using namespace std; 

Catalog::Catalog(){ //constructor
	head = new Node;
	head->next = NULL;
	numberOfBooks = 0;
	ifstream libraryBooks("library.txt");
	if(libraryBooks){ //if file opens correctly, read in contents. 
		libraryBooks >> numberOfBooks;
		//Read In First Book
		libraryBooks >> tempID;
		libraryBooks.clear();
		libraryBooks.ignore(100, '\n');
		libraryBooks.getline(tempTitle, 250, '\n');
		libraryBooks.getline(tempAuthor, 250, '\n');
		libraryBooks.clear();
		libraryBooks >> tempCopies >> tempCheckOuts >> tempHolds; 
		head->data.assignBook(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		//Read In Rest
		for (int i = 0; i < (numberOfBooks-1); i++){
			libraryBooks >> tempID;
			libraryBooks.clear();
			libraryBooks.ignore(100, '\n');
			libraryBooks.getline(tempTitle, 250, '\n');
			libraryBooks.getline(tempAuthor, 250, '\n');
			libraryBooks.clear();
			libraryBooks >> tempCopies >> tempCheckOuts >> tempHolds;
			addToList(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		}
		libraryBooks.close();
	} 
}
void Catalog::addToList(int id, char title[], char author[], int copies, int checkOuts, int holds){
	Node *temp = new Node;
	temp->next = NULL;
	temp->data.assignBook(id, title, author, copies, checkOuts, holds);
	Node *current = head;
	Node *previous = head;
	char returnTitle[250];
	head->data.returnTitle(returnTitle);
	if (strcmp(returnTitle, title)>=0){
		temp->next = head;
		head =temp;
		return;
	} else {
		while (current->next != NULL){
			previous = current;
			current=current->next;
			current->data.returnTitle(returnTitle);	
			if (strcmp(returnTitle, title) >=0){
				previous->next = temp;
				temp->next = current;
				cout << "value added" << endl;
				return;
			}
		}
		if (current->next == NULL){
			current->next = temp;
			temp->next = NULL;
		}
	}
}

void Catalog::printList(){
	Node *transverse = head;
	cout << "%%%%%% Book Catalog %%%%%%" << endl;
	while (transverse != NULL){
		transverse->data.printBook();
		transverse=transverse->next;
	}
	delete transverse;
}

void Catalog::deleteNodes(){
	Node *transverse = head;
	Node *last = NULL;
	while (transverse!=NULL){
		last = transverse;
		transverse = transverse->next;
		delete last;
	}
	delete transverse;
}
void Catalog::menu(){
	cout << "\n*********"  << "Main Menu" << "*********" << endl;
	cout << "1 - Print Catalog\n" << "2 - Add New Book\n" << "3 - Modify a Book\n" << "4 - Delete Book\n" << "5 - Quit\n" << "Enter choice: " << endl;
}

void Catalog::menuSelection(int selection){
	switch(selection){
		case 1:
			printList();
			break;
		case 2:
			break;
		case 3: 
			break;
		case 4:
			break;
		case 5:
			deleteNodes();
			break;
		default:
			cin.clear();
			cin.ignore();
			cout << "invalid" << endl;

	}

}
/*


void catalog::writeFile(){
	ofstream newLibrary("newlibrary.txt");
	newLibrary << numberOfBooks << '\n';
	for (int i=0; i < numberOfBooks; i++){
		booklist[i].returnAllVar(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		newLibrary << tempID << '\n' << tempTitle << '\n' << tempAuthor << '\n' << tempCopies << '\n' << tempCheckOuts << '\n' << tempHolds << '\n';
	}
	cout << "*** Catalog Written Out ***" << endl;
	newLibrary.close();
}

void catalog::updateBook(){
	int bookToModify, updateAction, tempIDtoCompare, newID, bookFoundIteration, bookWorkingOn;	
	bool bookFound = false;
	bool updateIDvalid = false;  
	do {
		cout << "enter ID of book: (or enter -1 to see a list of books) or 0 to exit ";
		cin >> bookToModify;
		idCompare(numberOfBooks, bookFound, bookToModify, tempIDtoCompare, bookFoundIteration);
		while (bookFound == true && updateAction != 7){
			bookWorkingOn = bookFoundIteration;
			cout << "Which field to change?\n" << "1 - ID\n" << "2 - Title\n" << "3 - Author\n" << "4 - Copies\n" << "5 - Checkouts\n" << "6 - Holds\n" << "7 - Quit" << endl;
			cin >> updateAction;		
			switch(updateAction){
				case 1:
					cout << "New Book ID? ";
					do {
						updateIDvalid = false;					
						cin >> newID;
						idCompare(numberOfBooks, updateIDvalid, newID, tempIDtoCompare, bookFoundIteration);
						if (updateIDvalid == true){
							cout << "Pick another number, that one is being used" << endl;
							cin.clear();
							cin.ignore();							
						}
					} while (updateIDvalid == true);
					booklist[bookWorkingOn].changeID(newID);
					break;
				case 2:
					cout << "Title of book?"; 
					cin.clear();
					cin.ignore();	
					cin.getline(tempTitle, 250);
					booklist[bookWorkingOn].changeTitle(tempTitle);
					break;
				case 3:
					cout << "Author of book?"; 
					cin.clear();
					cin.ignore();	
					cin.getline(tempAuthor, 250);
					booklist[bookWorkingOn].changeAuthor(tempAuthor);
					break;
				case 4:
					cout << "New Number of Copies: ";
					tempCopies = -1;
					while (tempCopies < 0){
						cin >> tempCopies;
						if (!tempCopies || tempCopies < 0){
						cout << "Enter a valid number of copies: " << endl;
					 	cin.clear();
						cin.ignore();
						} 					
					}
					booklist[bookWorkingOn].changeCopies(tempCopies);
					break;
				case 5:
					cout << "New Number of Checkouts: " << endl;
					tempCopies = booklist[bookWorkingOn].returnCopies();	
					tempCheckOuts = -1;
					while (tempCheckOuts < 0){
						cin >> tempCheckOuts;
						if (!tempCheckOuts || tempCheckOuts < 0){
						cout << "Enter a valid number of checkouts " << endl;
					 	cin.clear();
						cin.ignore();
						} else if (tempCheckOuts > tempCopies){
							cout << "Only " << tempCopies << " number of copies" << endl;
							tempCheckOuts = -1;
						}
					}
					booklist[bookWorkingOn].changeCheckouts(tempCheckOuts);
					break;
				case 6:
					cout << "New Number of Holds: " << endl;
					tempCopies = booklist[bookWorkingOn].returnCopies();
					tempHolds = -1;
					while (tempHolds < 0){
						cin >> tempHolds;
						if (!tempHolds || tempHolds < 0){
						cout << "enter a valid number of Holds " << endl;
					 	cin.clear();
						cin.ignore();
						} else if (tempHolds > tempCopies){
							cout << "Only " << tempCopies << " number of copies" << endl;
							tempCheckOuts = -1;
						}					
					}
					booklist[bookWorkingOn].changeHolds(tempHolds);
					break;
				case 7:
					break;
				default:
					cout << "Invalid Entry" << endl;
					cin.clear();
					cin.ignore(100, '\n');
					break; 
			}
		} 
		if (bookToModify == -1){
			printAllBooks();
		} else if(updateAction == 7 || bookToModify == 0) {
			break;	
		}else {
			cout << "Invalid Entry" << endl;
			cin.clear();
			cin.ignore(100, '\n');	
		}
	} while(updateAction != 7 || bookToModify != 0);
}
void catalog::newBook(){
	int requestedID, tempCompareID, foundAt;
	bool idExists = false;	
	cout << "ID of book? ";
	cin >> requestedID;
	while (!cin || (requestedID < 0)){
		cout << "invalid entry" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ID of book? ";
		cin >> requestedID;
	}
	idCompare(numberOfBooks, idExists, requestedID, tempCompareID, foundAt);
	while (idExists == true){
		cout << "ID already taken. Enter unique ID. " << endl;
		cin >> requestedID;
		idExists = false;
		idCompare(numberOfBooks, idExists, requestedID, tempCompareID, foundAt);
	}
	
	tempID = requestedID;
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Title of book?"; 
	cin.getline(tempTitle, 250);
	cout << "Author name?";
	cin.getline(tempAuthor, 250);
	cout << "Number of copies?";
	cin >> tempCopies;
	while (!cin || tempCopies <= 0){
		cout << "Invalid number of copies" << endl;
		cout << "Number of copies? ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempCopies;	
	}
	tempCheckOuts = 0;
	tempHolds = 0;

	booklist[numberOfBooks].assignBook(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
	numberOfBooks++;
}

void catalog::idCompare(int bookNumber, bool &foundflag, int userNumber, int tempCompare, int &bookFoundAn){
	for (int i = 0; i < bookNumber; i++){
		tempCompare = booklist[i].returnID();
		if (tempCompare == userNumber){
			foundflag = true;
			bookFoundAn = i;
			break;
		}
	}
}*/

