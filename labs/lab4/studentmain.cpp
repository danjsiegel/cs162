/* Dan Siegel
 * Stundent program
 * For Lab 4
 * 
 * Create two separate files called student.cpp and student.h
 * to be compiled with this file.
 * DO NOT CHANGE THIS FILE!.  I will be using an exact copy of this file
 * to compile your code with so whatever changes are made will not be
 * used when I grade your lab submission.
 *
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

int main()
{	
  char name[201];
  char first[] = "Penny";
  char last[] = "Hall";
  float g;
  Student stud1(first, last, 3.5);
  Student stud2;
  
  stud1.print();
  stud2.print();
  
  cout << "Changing stud1, ";
  cout << "First Name: " << endl;
  cin.get(name, 200, '\n');
  cin.ignore(200,'\n');
  stud1.setFirstName(name);
  stud1.print();
  stud2.print();
  
  cout << "Changing stud2, ";
  cout << "First Name: " << endl;
  cin.get(name, 200, '\n');
  cin.ignore(200, '\n');
  stud2.setFirstName(name);
  stud1.print();
  stud2.print();
  
  cout << "Changing stud2, ";
  cout << "Last Name: " << endl;
  cin.get(name, 200);
  cin.ignore(200, '\n');
  stud2.setLastName(name);
  stud1.print();
  stud2.print();
  
  cout << "Changing stud2, ";
  cout << "Enter new gpa: ";
  cin >> g;
  cin.ignore(10, '\n');
  stud2.setGpa(g);
  stud1.print();
  stud2.print();
  
  cout << "changing stud1, ";
  cout << "Enter new gpa ";
  cin >> g;
  cin.ignore(10,'\n');
  stud1.setGpa(g);
  stud1.print();
  stud2.print();
  
  cout << "getting gpa of  stud1, ";
  cout << stud1.getGpa() << endl;
  
  return 0;
}
