/* Midterm proctor exam version A
 * 
 * INSTRUCTIONS:  Write two functions in the space 
 * indicated below.
 * 
 * printArray function:  This should take an array of ints 
 * and a count.  It should then print out the array of numbers
 * one number per line.
 * 
 * remove function:  This should take an array, a number
 * to find and an amount. It will then remove the elements
 * up to the given amount starting after the first
 * instance of the given number. If the given number is not
 * found, it should do nothing.
 * It should move elements to fill in where the removed 
 * elements were located (see examples below).
 * Assume that the amount is less than or equal to the
 * number of elements after the found number. 
 * 
 * You can change this file all you want during
 * the exam but keep in mind that I will ONLY BE
 * USING YOUR FUNCTIONS by copying them to another
 * main.cpp file (with different variable values)
 * for grading. So don't code to the given data values.
 * 
 * Do not use global variables/constants
 * or goto's in your code.  Please only make two
 * functions (there's really no need for more than two).
 * 
 * Don't ask the user for information.  The main
 * function will get all information needed and pass it
 * into your functions (see main function for
 * how your functions will be called).
 * 
 * 
 * three example runs are below:
 Original Array
-----------
10
32
3
41
60
7
18
77
3
5
90
----------------
remove after what number?3
number of elements to remove?3
After Removal
-----------
10
32
3
18
77
3
5
90
----------------
Original Array
-----------
10
32
3
41
60
7
18
77
3
5
90
----------------
remove after what number?101
number of elements to remove?3
After Removal
-----------
10
32
3
41
60
7
18
77
3
5
90
----------------
Original Array
-----------
10
32
3
41
60
7
18
77
3
5
90
----------------
remove after what number?60
number of elements to remove?6
After Removal
-----------
10
32
3
41
60
----------------



 * 
 */

#include <iostream>
#include <cstring>

using namespace std;

// PLEASE PUT YOUR FUNCTIONS BELOW THIS LINE

void printArray(int array[], int count){
	for (int i = 0; i < count; i++){
	cout << array[i] << endl;
	}
}
void remove(int find, int num, int array[], int &count){
	bool found = false;
	int foundIteration, numberLeft, tempNum;
	
	for (int i = 0; i < count; i++){
		if (array[i] == find){
			found = true;
			foundIteration = i;			
			break;	
		}
	}
	if (found == true){
		numberLeft = count - (foundIteration + num + 1);
		int tempCount = numberLeft + (foundIteration + 1);
		int tempArray[tempCount];
		for (int i = 0; i < (foundIteration + 1); i++){ //up to found iteration
			tempNum = array[i];
			tempArray[i] = tempNum;		
		}
		for (int i = (foundIteration + num); i < count; i++){
			tempNum = array[i];
			tempArray[i] = tempNum;	
		}
		for (int i = 0; i < count; i++){ //clear array
			array[i] = 0;
		}
		for (int i = 0; i < tempCount; i++){
			array[i] = tempArray[i]; 
		}
		count = tempCount;
	}
	

}

//  END OF FUNCTIONS



int main()
{
    int array[200] = {10,32,3,41,60,7,18,77,3,5,90};
    int count = 11;
	int find, num;
	
    cout << "Original Array" << endl;
    cout << "-----------" << endl;
	printArray(array, count);
    cout << "----------------" << endl;
	           
	cout << "remove after what number?";
	cin >> find;
    cout << "number of elements to remove?";
    cin >> num;
	
    remove(find, num, array, count);
	
    cout << "After Removal" << endl;
    cout << "-----------" << endl;
	printArray(array, count);
    cout << "----------------" << endl;
	
	return 0;
}
