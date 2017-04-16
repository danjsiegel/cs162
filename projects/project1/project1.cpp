//Dan Siegel
//Project 1
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string.h>

using namespace std;
//void function to roll dice 
void sumcalculation (int& roll1, int& roll2, int& total){
	roll1 = (rand() % 6) + 1;
	roll2 = (rand() % 6) + 1;
	total = roll1 + roll2;
}
int main (){
	srand((unsigned)time(0));
	string name;
	string cont = "y";
	int die1, die2, sum;
	int wins = 0;
	cout << "&&&&& SIMPLE DICE GAME &&&&&&&&" << "\nWhat is your name? ";
	cin >> name;	    
		while(cont == "y"){
			//Game will run at most for a total of 5 sessions. If a winning or losing value is achieved, the loop will break.
			for (int i = 1; i < 6; i++){
				sumcalculation(die1, die2, sum);
				cout << "\nrolling dice...\n" << endl;
				cout << name << " you rolled a " << die1 << " and a " << die2 << endl;
				cout << "For a total of " << sum << endl;
				sleep(1);
				if (sum == 2 || sum == 3 || sum == 7 || sum == 11 || sum == 12){
						break;
					}
				//if not a winning or losing value and the script hasn't gone through 5 iterations	
				else if (i != 5) {
					cout << "\nre-roll dice." << endl;
				}	
			} 
			//Values have been returned to the sum and dice variables. Next step is to check the values to see if you won or lost. Winning and losing have specific numbers tied to them, all other values are draw.  
			if (sum == 11 || sum == 7) { //winning values
				wins= wins + 3; 
				cout << name << " Wins! Three points earned" << endl;
			} else if (sum == 2 || sum == 3 || sum == 12){ //losing values
				cout << name << " lost the game. No points." << endl;
			} else { //draw - all other values 
				wins++; 
				cout << name << " draws. One point earned" << endl;
			}
			cout << "+++END GAME+++" << endl;
			cout << name << ", do you want to play again? (y or n)" << endl;
			cin >> cont;
		}
	cout << "=======>" << name << "'s total score is: " << wins <<"\nGOODBYE!" <<endl;
	return 0;
	

}

