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
	head = NULL;
	current = NULL;
	temp = NULL;
	previous = NULL;
	deleteNode = NULL; 
	numberOfBooks = 0;
	ifstream libraryBooks("library.txt");
	if(libraryBooks){ //if file opens correctly, read in contents. 
		libraryBooks >> numberOfBooks;
		for (int i = 0; i < (numberOfBooks); i++){
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
void Catalog::menu(){
	cout << "\n*********"  << "Main Menu" << "*********" << endl;
	cout << "1 - Print Catalog\n" << "2 - Add New Book\n" << "3 - Modify a Book\n" << "4 - Delete Book\n" << "5 - Quit\n" << "Enter choice: " << endl;
}

void Catalog::newBook(){
	int currentId;
	cout << "ID" << endl;
	cin >> tempID;
	current = head;
	previous= head;
	currentId = head->data.returnID();
	if (currentId == tempID){
		cout << "ID already exists" << endl;
		return;
	}
	while (current->next != NULL && tempID != currentId){
		previous = current;
		current = current-> next;
		currentId = current->data.returnID();
		if (tempID == currentId){
			cout << "ID already exists" << endl;
			return;
		}
	}
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Title: ";
	cin.getline(tempTitle, 250, '\n');
	cout << "Author: ";
	cin.getline(tempAuthor, 250, '\n');
	cin.clear();
	cout << "Number of Copies" << endl;
	cin >> tempCopies;
	tempCheckOuts = 0;
	tempHolds = 0;
	addToList(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
	cout << "value added" << endl;
	numberOfBooks = numberOfBooks + 1;
	return;
}

void Catalog::addToList(int id, char title[], char author[], int copies, int checkOuts, int holds){
	temp = new Node;
	temp->next = NULL;
	temp->data.assignBook(id, title, author, copies, checkOuts, holds);
	current = head;
	previous = head;
	char returnTitle[250];
	if (head == NULL){
		head = temp;
		return;
	} else {
		head->data.returnTitle(returnTitle);
		if (strcmp(returnTitle, title) >= 0){
			temp->next = head;
			head =temp;
			return;
		} else {
			while (current->next != NULL){
				previous = current;
				current=current->next;
				current->data.returnTitle(returnTitle);
				if (strcmp(returnTitle, title)  >= 0){
						previous->next = temp;
						temp->next = current;
						return;	
				}
			}
		}
	}
	if (current->next == NULL){
				current->next = temp;
				temp->next = NULL;
				return;
	}
}

void Catalog::printList(){
	current = head;
	cout << "%%%%%% Book Catalog %%%%%%" << endl;
	while (current != NULL){
		current->data.printBook();
		if (current != NULL){
			current=current->next;
		}
	}
}

//void Catalog::deleteNodes(){
Catalog::~Catalog(){
	Node *transverse = head;
	Node *last = NULL;
	while (last!=NULL){
		last = transverse;
		if (transverse != NULL){
			transverse = transverse->next;
		}
		delete last;
	}
	delete transverse;
}

void Catalog::deleteBook(int ID){
	int currentId;
	if (ID == -1){
		printList();
		cout << "Enter ID to Delete" << endl;
		cin >> ID; 
	}
	current = head;
	Node *previous = head;
	Node *deleteNode = NULL;
	currentId = head->data.returnID();
	if (currentId == ID){
		deleteNode = head;
		head = head->next;
		delete deleteNode;
		numberOfBooks = numberOfBooks-1;
		return;
	}
	while (current->next != NULL && ID != currentId){
		previous = current;
		current = current->next;
		currentId = current->data.returnID();
		if (ID == currentId){
			deleteNode = current; 
			current = current->next;
			previous->next = current;
			delete deleteNode;
			numberOfBooks = numberOfBooks-1;
			return;
		}
	}
	if (current->next == NULL){
		cout << "value not found" << endl;
		return;
	} 
}

void Catalog::menuSelection(int selection){
	switch(selection){
		case 1:
			printList();
			break;
		case 2:
			newBook();
			break;
		case 3:
			updateBook();
			break;
		case 4:
			cout << "Enter ID to Delete" << endl;
			cin >> selection;
			deleteBook(selection); 
			break;
		case 5:
			writeFile();
			break;
		default:
			cin.clear();
			cin.ignore();
			cout << "invalid" << endl;
	}

}


void Catalog::writeFile(){
	ofstream newLibrary("newlibrary.txt");
	newLibrary << numberOfBooks << '\n';
	current = head;
	while(current != NULL){
		current->data.returnAllVar(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		newLibrary << tempID << '\n' << tempTitle << '\n' << tempAuthor << '\n' << tempCopies << '\n' << tempCheckOuts << '\n' << tempHolds << '\n';
		if (current != NULL){
			current = current->next;
		}
	}
	cout << "*** Catalog Written Out ***" << endl;
	newLibrary.close();
}

void Catalog::updateBook(){
	int action;
	cout << "What Field to change" << endl;
	cout << "1 - ID\n2 - Title\n3 - Author\n4 - Copies\n5 - Checkouts\n6 - Holds\n7 - Quit\nEnter Choice: " << endl;
	cin >> action;
	switch(action){
		case 1:
			newID();
			break;	
		case 2:
			changeTitle();
			break;
		case 3:
			changeAuthor();
			break;
		case 4:
			cout << "case 4" << endl;
			break;
		case 5:
			cout << "case 5" << endl;
			break;
		case 6:
			cout << "case 6" << endl;
			break;
		case 7:
			cout << "Exiting Menu" << endl;
			break;
		default:
			cout << "Not a valid choice" << endl;
			cin.clear();
			cin.ignore();

	}
}
void Catalog::newID(){
	int currentId;
	cout << "Enter ID to change: " << endl;
	cin >> tempID;
	current = head;
	previous= head;
	currentId = head->data.returnID();
	if (currentId == tempID){
		cout << "Enter New ID: " << endl;
		cin >> tempID;
		current->data.changeID(tempID);
		cout << "ID Changed" << endl;
		return;
	}
	while (current->next != NULL && tempID != currentId){
		previous = current;
		current = current-> next;
		currentId = current->data.returnID();
		if (tempID == currentId){
			cout << "Enter New ID: " << endl;
			cin >> tempID;
			current->data.changeID(tempID);
			cout << "ID Changed" << endl;
			return;
		}
	}
	cout << "ID not found" << endl;
	return;
}
void Catalog::changeTitle(){
	int currentId;
	cout << "ID of Book to change: ";
	cin >> tempID; 
	current = head;
	previous= head;
	char newTitle[250];
	currentId = head->data.returnID();
	if (currentId == tempID){
		current->data.returnAllVar(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		deleteBook(tempID);
		cout << "New Title: ";
		cin.clear();
		cin.ignore();
		cin.getline(newTitle, 250, '\n');
		addToList(tempID, newTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
		return;
	}
	while (current->next != NULL && tempID != currentId){
		previous = current;
		current = current-> next;
		currentId = current->data.returnID();
		if (tempID == currentId){
			current->data.returnAllVar(tempID, tempTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
			deleteBook(tempID);
			cout << "New Title: ";
			cin.clear();
			cin.ignore();
			cin.getline(newTitle, 250, '\n');
			addToList(tempID, newTitle, tempAuthor, tempCopies, tempCheckOuts, tempHolds);
			return;
		}
	}
	cout << "Book Not Found" << endl;
}
void Catalog::changeAuthor(){
	int currentId;
	cout << "ID of Book to change: ";
	cin >> tempID; 
	current = head;
	previous= head;
	char newAuthor[250];
	currentId = head->data.returnID();
	if (currentId == tempID){
		cout << "New Author: ";
		cin.clear();
		cin.ignore();
		cin.getline(newAuthor, 250, '\n');
		current->data.changeAuthor(newAuthor);
		return;
	}
	while (current->next != NULL && tempID != currentId){
		previous = current;
		current = current-> next;
		currentId = current->data.returnID();
		if (tempID == currentId){
			cout << "New Author: ";
			cin.clear();
			cin.ignore();
			cin.getline(newAuthor, 250, '\n');
			current->data.changeAuthor(newAuthor);
			return;
		}
	}
	cout << "Book Not Found" << endl;
}
void Catalog::changeCopies(){

}


