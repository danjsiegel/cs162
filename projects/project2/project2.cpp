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
	int numOfBooks, action, tempID, foundIteration;
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
		case 1:
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
		case 2:
			cin.clear();
			cin.ignore();
			found = false; 
			cout << "Title of Book? " <<endl;
			cin.getline(compare, 250, '\n');
			for (int i = 0; i < numOfBooks; i++){
				int equal;				
				equal = strcmp(compare, s[i].title);
				cout << s[i].title << endl;
				cout << compare << endl;
				if (equal == 0){
				found = true;
				foundIteration = i;
				}
			}
			if (found == true){
				cout << "-----" << s[foundIteration].id << "-----" << endl;							
				cout << "Title: " << s[foundIteration].title << endl;
				cout << "Author: " << s[foundIteration].author << endl;
				cout << "Number of Copies: " << s[foundIteration].copies << endl;
				cout << "Number Checked out: " << s[foundIteration].checkOuts << endl;
				cout << "Number of Holds: " << s[foundIteration].holds << endl;	
			} else {
				cout << "Book Not Found" << endl;
			}
			break;
		case 3:
			cin.clear();
			cin.ignore();
			cout << "case3" << endl;
			break;
		case 4:
			cout << "case4" << endl;
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
