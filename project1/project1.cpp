#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string.h>

using namespace std;
void sumcalculation (int& roll1, int& roll2, int& total);

int main (){
	char name[20];
	string cont = "y";
	int die1, die2, sum;
	int wins = 0;
	cout << "What is your name? ";
	cin >> name;	    
		while(cont == "y"){
		for (int i = 1; i < 6; i++){
			sumcalculation(die1, die2, sum);
			cout << "rolling dice..." << endl;
			cout << name << " you rolled a " << die1 << " and a " << die2 << endl;
			cout << "For a total of " << sum << endl;
			if (sum == 2 || sum == 3 || sum == 7 || sum == 11 || sum == 12){
					break;
				}
			else if (i != 5) {
				cout << "re-roll dice." << endl;
			}	
		} 
		if (sum == 11 || sum == 7) {
			wins++; 
			cout << name << " wins one point earned" << endl;
		} else if (sum == 2 || sum == 3 || sum == 12){
			cout << name << " lost" << endl;
		} else {
			wins++; 
			cout << name << " draws one point earned" << endl;
		}
		cout << "wins earned " << wins << endl;
		cout << "Continue? " << endl;
		cin >> cont;
		}
	return 0;
	

}
void sumcalculation (int& roll1, int& roll2, int& total){
	roll1 = (rand() % 6) + 1;
	roll2 = (rand() % 6) + 1;
	total = roll1 + roll2;
	
}

