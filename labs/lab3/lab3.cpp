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
	double lineDataAsDbl;
	istringstream iss(getLineData);
	iss >> lineDataAsDbl;
	return lineDataAsDbl;
}

int main() {
	int id = 1;
	int lineCount = 0;
	int numberOfBooks;
	char line[250], compare[250];
	bool found = false;
	ifstream bookCounter("books.txt");
		while(bookCounter.getline(line, 250, '\n')){
			lineCount++;
		}
	bookCounter.close();
	numberOfBooks = (lineCount / 3);
	cout << numberOfBooks << endl;
	
	struct book s[numberOfBooks];
	ifstream bookList("books.txt");

	for (int i = 0; i < numberOfBooks; i++){
		s[i].id = id;
		bookList.getline(s[i].title, 250, '\n');
		bookList.getline(s[i].author, 250, '\n');
		bookList >> s[i].price;
		bookList.ignore(250, '\n');
		id++;
		cout << " book " << s[i].id << " title: " << s[i].title << " author " << s[i].author << " price " << s[i].price << endl;
	}




	bookList.close(); 
	return 0;
}
