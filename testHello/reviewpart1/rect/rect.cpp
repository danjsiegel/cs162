/* Rectangle by Dona Hertel
 * Demos the use of cin/cout
 * variables and arithmetic
 */

#include <iostream>
using namespace std;

int main()
{
   double length;
   double width;
   double area;
   double perimeter;

   cout << "This program computes and prints out "
        << "the perimeter and area of a rectangle." 
        << endl << endl;

   cout << "Enter length and width: " << endl;
   cin >> length >> width;
  
   perimeter = 2*(length + width);
   area = length*width;

   cout << "The perimeter is: " << perimeter << endl;
   cout << "The area is: " << area << endl;

   return 0;
}
