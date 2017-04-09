/* Favorite Color
 * Demo of cout/cin and
 * simple if/else statement
 */
 
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string color;
	
	cout << "What is your favorite color?" << endl;
	cin >> color;
	
	cout << "your favorite color is: " << color << endl;
	
	if(color == "red")
	{
        cout << "That is my favorite color!" << endl;
	}
	else
	{
		cout << "That color is okay with me." << endl;
	}
	
	return 0;
}
