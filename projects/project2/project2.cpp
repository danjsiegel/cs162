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
	int numOfBooks, action, tempID;
	char line[250];
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
/*
	do {i
		cout <<"*"  << "Main Menu" << "*" << endl;
		cout << "1 - Print Catalog\n" << "2 - Search by Title\n" << "3 - Search by Author\n" << "4 - Do Action\n" << "5 - Quit\n" << "Enter choice: " << endl;
		cin >> action;

		switch (action){
		case 1:
			cout << "case1" << endl;
			break;
		case 2:
			cout << "case2" <<endl;
			break;
		case 3:
			cout << "case3" << endl;
			break;
		case 4:
			cout << "case4" << endl;
			break;
		default:
			cout << "default" << endl;
			break;
		}
		if ((action > 5) || (!action) || (action < 1)){
			cout << "Invalid selection" << endl;
			cin.clear();
			cin.ignore(100, '\n'); 	
		}

	} while (action != 5);

*/	
	bookList.close();
	return 0;
}
