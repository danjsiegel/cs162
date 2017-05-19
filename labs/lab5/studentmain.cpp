/* Dan Siegel
Lab5
 *
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

int main(){
	char name[201];
	float g;
	int numbOfStudents;
	cout << "Number of students: ";
	cin >> numbOfStudents;
	Student *list;
	list = new Student[numbOfStudents];
	for (int i = 0; i < numbOfStudents; i++){
		cout << "Student " << i << " first name: ";
		cin.ignore(200,'\n');		
		cin.get(name, 200, '\n');
		(list+i)->setFirstName(name);
		cout << "Student " << i << " last name: ";		
		cin.ignore(200,'\n');		
		cin.get(name, 200);
		(list+i)->setLastName(name);
		cout << "Student " << i << " GPA: ";
		cin >> g;
		(list+i)->setGpa(g);
	}
	cout << "***Printing List of Students***" << endl;
	for (int i = 0; i < numbOfStudents; i++){
		cout << "======Student======" << endl;
		cout << "First Name: " << (list+i)->getFirstName() << endl;
		cout << "Last Name: " << (list+i)->getLastName() << endl;
		cout << "GPA: " << (list+i)->getGpa() << endl;
	}
	delete [] list;
  return 0;
}
