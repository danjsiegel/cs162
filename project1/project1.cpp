#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string.h>

using namespace std;
void sumcalculation (int& roll1, int& roll2, int& total);

int main (){
	string name;
	string cont = "y";
	int die1, die2, sum;
	int wins = 0;
	cout << "What is your name? ";
	cin >> name;	    
		while(cont == "y"){
			for (int i = 1; i < 6; i++){
				//Function which rolls the dice, passes the values back by reference
				//srand((unsigned)time(0));
				sumcalculation(die1, die2, sum);
				cout << "rolling dice..." << endl;
				cout << name << " you rolled a " << die1 << " and a " << die2 << endl;
				cout << "For a total of " << sum << endl;
				//If the values are winning or losing end the for loop
				if (sum == 2 || sum == 3 || sum == 7 || sum == 11 || sum == 12){
						break;
					}
				//if not a winning or losing value and the script hasn't gone through 5 iterations	
				else if (i != 5) {
					cout << "re-roll dice." << endl;
				}	
			} 
			//Values have been returned, either it has a winning or losing value or it ran 5times with a bad ending value
			//winning values
			if (sum == 11 || sum == 7) {
				wins= wins + 3; 
				cout << name << " Wins! Three points earned" << endl;
			} else if (sum == 2 || sum == 3 || sum == 12){ //losing values
				cout << name << " lost the game. No points." << endl;
			} else { //if not a winner or loser, it's a draw
				wins++; 
				cout << name << " draws. One point earned" << endl;
			}
			cout << "+++END GAME+++" << endl;
			cout << name << ", do you want to play again? (y or n)" << endl;
			cin >> cont;
		}
	cout << name << "'s wins earned: " << wins << endl;
	return 0;
	

}
void sumcalculation (int& roll1, int& roll2, int& total){
	roll1 = (rand() % 6) + 1;
	roll2 = (rand() % 6) + 1;
	total = roll1 + roll2;
	
}
