/* Guessing Game
 * Demo of simple while counter
 * and nested if/else statement.
 */ 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{	
	int guess, number, count; // guess is the user's guess,
	                   // number is the actual number.
	               // count is how many guesses the user has taken
	count = 0;
	
	// this is needed to get different values each time 
	// the game is played.
	srand((unsigned)time(0)); 
	//get random number between 1 and 100
	number = (rand() % 100) + 1;
	    
	while(count < 5)
	{	
	    // get a number from the user
	    cout << "Guess a number between 1 and 100." << endl;
	    cin >> guess;
	    	
	    // check if number is too high,low or equal and print appropriate
	    // message
	    if(guess < number)
	    {
			cout << "You're too low." << endl;
		}
		else if(guess > number)
		{
			cout << "You're too high." << endl;
		}
		else // here we can assume that guess == number
	    {
			cout << "You've guessed right!" << endl;
			return 0;
		}
		     
		count++; // need to increment count

    }
    // if they got this far, then they didn't guess right.
    cout << "Sorry! You've ran out of guesses." << endl;
    cout << "The number was: " << number << endl;
    
	return 0;
}



