//Dan Siegel
//Lab1
#include <iostream>

using namespace std;

void weightCalc(double earthWeight, double planetGravity){
	const double earth = 9.81;
	double weight;
	weight = earthWeight * (planetGravity/earth);
	cout << "your weight is: " << weight << endl;
}

int main (){
	const double moon = 1.622;
	const double mars = 3.71;
	const double neptune = 11.15;
	const double jupiter = 24.79;
	
	char cont;
	int chosenPlanet;
	double userWeight;
	
	do {
		//Gets users weight. Validates that the input is both a valid input, and a double. If not, clears the input. 
		cout << "Please enter your weight on Earth: " << endl;
		cin >> userWeight;
		while (!cin || (userWeight <= 0)) {
			cout << "Invalid weight. Please re-enter" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Please enter your weight on Earth: " << endl;
			cin >> userWeight;
		}
		cout << "Chose a planet:\n" << "1 - Moon\n" << "2 - Mars\n" << "3 - Neptune\n" << "4 - Jupiter\n";
		//Switch through the different planets. 
		cin >> chosenPlanet;
		switch(chosenPlanet){
			case 1:
				weightCalc(userWeight, moon);
				break;
			case 2:
				weightCalc(userWeight, mars);
				break;
			case 3:
				weightCalc(userWeight, neptune);
				break;
			case 4:
				weightCalc(userWeight, jupiter);
				break;
			default:
				cout << "not a vaid selection" << endl;
				cin.clear();
				cin.ignore(100, '\n');
				break;
		}	
		cout << "Would you like to continue(y or no): " << endl;
		cin >> cont;
	} while (cont == 'y' || cont == 'Y');
	return 0;
}

