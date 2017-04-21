//Dan Siegel
//Project 2
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

struct book {
		int id;
		char title[250];
		char author[250];
		int copies;
		int checkOuts;
		int holds;
	};

int lineRecognition(char getLineData[250]){
	int lineDataAsInt;	
	istringstream iss(getLineData);
	iss >> lineDataAsInt;
	return lineDataAsInt;
}

int main() {
	int numOfBooks, action, tempID, numberFound, actionToBook, updateToBook;
	int foundIteration[numberFound];
	char line[250], compare[250];
	bool found = false;
	ifstream bookList("library.txt");

	bookList.getline(line, 250, '\n');
	istringstream iss(line);
	iss >> numOfBooks; 
	struct book s[numOfBooks];//reading from lines is not triggering next line. Need to move bookList >> s[i].id to a getline and put bach in as sstream. 


	for (int i = 0; i < numOfBooks; i++){
		bookList.getline(line, 250, '\n');
		s[i].id = lineRecognition(line);
		bookList.getline(s[i].title, 250, '\n');
		bookList.getline(s[i].author, 250, '\n');
		bookList.getline(line, 250, '\n');//copies
		s[i].copies = lineRecognition(line);
		bookList.getline(line, 250, '\n');//checkouts
		s[i].checkOuts = lineRecognition(line);
		bookList.getline(line, 250, '\n');//holds
		s[i].holds = lineRecognition(line);
	}

	do {
		cout << "\n*********"  << "Main Menu" << "*********" << endl;
		cout << "1 - Print Catalog\n" << "2 - Search by Title\n" << "3 - Search by Author\n" << "4 - Do Action\n" << "5 - Quit\n" << "Enter choice: " << endl;
		
		cin >> action;
		switch (action){
		case 1: //Print Catalog
			cout << "%%%%%%% Book Catalog %%%%%%%" << endl;
				for (int i = 0; i < numOfBooks; i++){
					cout << "-----" << s[i].id << "-----" << endl;							
					cout << "Title: " << s[i].title << endl;
					cout << "Author: " << s[i].author << endl;
					cout << "Number of Copies: " << s[i].copies << endl;
					cout << "Number Checked out: " << s[i].checkOuts << endl;
					cout << "Number of Holds: " << s[i].holds << endl;	
				}
			break;
		case 2: //Search by Title. Stops after title is found. 
				cin.clear();
				cin.ignore();
				found = false; 
				cout << "Name of Book? " <<endl;
				cin.getline(compare, 250, '\n');
				for (int i = 0; i < numOfBooks; i++){
					int equal;				
					equal = strcmp(compare, s[i].title);
					if (equal == 0){
						found = true;
						foundIteration[0] = i;
						break;
					}
				}
				if (found == true){
					cout << "-----" << s[foundIteration[0]].id << "-----" << endl;							
					cout << "Title: " << s[foundIteration[0]].title << endl;
					cout << "Author: " << s[foundIteration[0]].author << endl;
					cout << "Number of Copies: " << s[foundIteration[0]].copies << endl;
					cout << "Number Checked out: " << s[foundIteration[0]].checkOuts << endl;
					cout << "Number of Holds: " << s[foundIteration[0]].holds << endl;	
				} else {
					cout << "Book " << compare << " Not Found" << endl;
				}
				break;

		case 3: // Search by Author. Must check all author names. 
				cin.clear();
				cin.ignore();
				found = false;
			 	numberFound = 0;
				cout << "Name of Author? " <<endl;
				cin.getline(compare, 250, '\n');
				for (int i = 0; i < numOfBooks; i++){
					int equal;				
					equal = strcmp(compare, s[i].author);
					if (equal == 0){
						found = true;
						foundIteration[numberFound] = i;
						numberFound++;
					}
				}
				if (found == true){
					for (int i = 0; i < numberFound; i++){
						cout << "-----" << s[i].id << "-----" << endl;							
						cout << "Title: " << s[i].title << endl;
						cout << "Author: " << s[i].author << endl;
						cout << "Number of Copies: " << s[i].copies << endl;
						cout << "Number Checked out: " << s[i].checkOuts << endl;
						cout << "Number of Holds: " << s[i].holds << endl;	
					}
				} else {
					cout << "Book by Author " << compare << " Not Found" << endl;
				}
				break;
		case 4:
			cout << "Enter id of Book or -1 to display all books: " << endl;
			//cin.clear();
			//cin.ignore();	
			cin >> actionToBook;
			if (actionToBook == -1){			
				cout << "%%%%%%% Book Catalog %%%%%%%" << endl;
				for (int i = 0; i < numOfBooks; i++){
					cout << "-----" << s[i].id << "-----" << endl;							
					cout << "Title: " << s[i].title << endl;
					cout << "Author: " << s[i].author << endl;
					cout << "Number of Copies: " << s[i].copies << endl;
					cout << "Number Checked out: " << s[i].checkOuts << endl;
					cout << "Number of Holds: " << s[i].holds << endl;
				}	
				cout << "Enter id of Book" << endl;	
				cin >> actionToBook;
				} 
				found = false;	
				if (actionToBook > 0) {			
					for (int i = 0; i < numOfBooks; i++){			
						if (actionToBook == s[i].id){
							found = true;
							numberFound = i;
							break;
						}
					}
				}	
				if (found == true){				
					cout << "What would you like to do?\n 1-Checkout Book\n 2-Return Book\n 3-Hold Book\n 4-Remove Hold" << endl;
					cin >> updateToBook; 
					switch (updateToBook) {
						case 1:
							if (s[numberFound].copies <= s[numberFound].checkOuts){
								s[numberFound].checkOuts = 	s[numberFound].checkOuts + 1;		
							} else {
								cout << "All copies checked out" << endl;
							}
							break;
						case 2:
						case 3:
						case 4:
						default:
							cout << "Invalid selection" << endl;
							cin.clear();
							cin.ignore(100, '\n'); 
							break; 
						}		
				} else {
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Invalid entry" << endl;
				}
				break;
		case 5: 
			cout << "goodbye" << endl;
			break;
		default:
			cout << "Invalid selection" << endl;
			cin.clear();
			cin.ignore(100, '\n'); 
			break;
		}
	} while (action != 5);


	bookList.close();
	return 0;
}
