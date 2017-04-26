//Dan Siegel
//Lab3
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <iomanip>

using namespace std;

struct book {
		int id;
		char title[250];
		char author[250];
		double price;
	};

int main() {
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
	struct book s[numberOfBooks];
	ifstream bookList("books.txt");
	ofstream sales("sales.txt");
	for (int i = 0; i < numberOfBooks; i++){
		bookList.getline(s[i].title, 250, '\n');
		bookList.getline(s[i].author, 250, '\n');
		bookList >> s[i].price;
		bookList.ignore(250, '\n');
		cout << s[i].title << "\nauthor " << s[i].author << "\nprice " << s[i].price << endl;
		cout << "&&&&&&&&&&&&&&&&&&&&&&7" << endl;
		
	}
	cout << "Total number of books: " << numberOfBooks << endl;
	cout << "Reducing prices..." << endl;
	cout << fixed << setprecision(2);
	for (int i = 0; i < numberOfBooks; i++){
		s[i].price = s[i].price * 0.8;
		cout << s[i].title << " is now " << s[i].price << endl;
		sales << s[i].title << '\n' << s[i].author << '\n' << s[i].price << endl;
	}

	cout << '\n' << "Prices have been written to sales.txt" << endl;

	sales.close(); 
	bookList.close(); 
	return 0;
}
