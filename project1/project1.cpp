#include <cstdlib>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <string.h>

using namespace std;
void int sumcalculation (int&d){
	int sum = 0;
	int die1 = (rand() % 6) + 1;
	int die2 = (rand() % 6) + 1;
	sum = die1 + die2;
	int rollArray[3] = {die1, die2, sum}; 
	return rollArray;	
}

int main (){
	char name[20];
	int count = 1;
	int die1, die2;
	int sum[3];
	cout << "What is your name? ";
	cin >> name;
	while (count < 6){
		sum[3] = sumcalculation();
	
		
		cout << sum[0] << " " << sum[1] << sum[2] << endl;
		count ++;
	}

	return 0;
	

}


