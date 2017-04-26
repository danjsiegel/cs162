//Dan Siegel
//Lab3
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

struct book {
		int id;
		char title[250];
		char author[250];
		double price;
	};

int lineRecognition(char getLineData[250]){
	int lineDataAsInt;
	istringstream iss(getLineData);
	iss >> lineDataAsInt;
	return lineDataAsInt;
}

int main() {
	int id = 1;
	int lineCount = 0;
	char line[250], compare[250];
	bool found = false;
	ifstream bookCounter("books.txt");
		while(getline(bookCounter, line)){
			lineCount++;
		}
	bookCounter.close();
	cout << "lines" << line << endl;
	/*
	struct book s[numOfBooks];//reading from lines is not triggering next line. Need to move bookList >> s[i].id to a getline and put bach in as sstream.
	ifstream bookList("books.txt");

	for (int i = 0; i < numOfBooks; i++){
		bookList.getline(line, 250, '\n');
		s[i].id = id;
		bookList.getline(s[i].title, 250, '\n');
		bookList.getline(s[i].author, 250, '\n');
		bookList.getline(line, 250, '\n');//copies
		s[i].copies = lineRecognition(line);
		bookList.getline(line, 250, '\n');//checkouts
		s[i].checkOuts = lineRecognition(line);
		bookList.getline(line, 250, '\n');//holds
		s[i].holds = lineRecognition(line);
		id++;
	}

	do {



	bookList.close(); */
	return 0;
}
