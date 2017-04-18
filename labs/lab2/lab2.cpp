//Dan Siegel
//Lab2
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
char letterSorter(char userInput[], int length){
	for (int i = 0; i < length; i++){
			int smallest = userInput[i];
			int smallestIndex = i;
			for (int j = i; j < length; j++){
				if (userInput[j] < smallest){
					smallest = userInput[j];
					smallestIndex = j;
				}
			}
		swap(userInput[i], userInput[smallestIndex]);
		} 
}
//checks length of the array. Not necessary for program to work. 
int arrayLength(char wordInput[]){
	int count = 0;
	while(wordInput[count] != '\0'){
		count++;	
		}	
	return count;
}

int main (){
	
	char cont, firstWord[20], secondWord[20];
	int firstLen, secondLen, equal;
	do {
		
		cout << "Enter the first word: ";
		cin >> firstWord;
		cout << "Enter the second word: ";
		cin >> secondWord;
		
		firstLen = arrayLength(firstWord);
		secondLen = arrayLength(secondWord);			
		
		if (firstLen != secondLen){ //checks if the length is the same
			cout << "The words are NOT anagrams of each other" << endl;		
		} else {
			letterSorter(firstWord, firstLen);
			letterSorter(secondWord, secondLen);
			equal = strcmp(firstWord, secondWord);	
				if (equal == 0){
					cout << "The words are anagrams of each other" << endl;
				} else {
					cout << "The words are NOT anagrams of each other" << endl;	
				}
		}
		cout << "Do you want to continue? (y or n)" << endl;
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
	return 0;
}

