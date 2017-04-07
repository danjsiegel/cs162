/* Largest of Three Numbers
 * Demo for using nested
 * if/else statements
 * and compound conditionals
 */
 
#include <iostream>

using namespace std;

int main() 
{
    int a, b, c;
    int largest;
    
    // get the three numbers
    cout << "Enter three integers: " << endl;
    cin >> a >> b >> c;
    
    // test for a
    if((a >= b)&&(a >= c))
    {
		largest = a;
	}
	else if((b >= a)&&(b >= c)) // now, test for b 
	{
		largest = b;
	}
	else // if neither a nor b are largest, choose c
	{
		largest = c;
	}
	
	cout << "The largest number is: " << largest << endl;
	
    return 0;
}
