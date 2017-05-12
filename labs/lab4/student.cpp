//Dan Siegel
//lab4
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(){
	strcpy(firstName, "\0");
	strcpy(lastName, "\0");
	gpa = 0;
}
Student::Student(char first[], char last[], double Ugpa){
	strcpy(firstName, first);
	strcpy(lastName, last);
	gpa = Ugpa;
}
void Student::setFirstName(char fname[]){
	strcpy(firstName, fname);
}
void Student::setLastName(char lname[]){
	strcpy(lastName, lname);
}
void Student::setGpa(double grade){
	if (!grade || (grade>4) || (grade<0)){
		cout << "invalid grade, grade needs to be between 0.0 and 4.0" << endl;
	} else {gpa = grade;
	}
}
void Student::print(){
	cout << "===== Student =====\n" << "First Name: " << firstName << "\nLast Name: " << lastName << "\n GPA: " << gpa << endl;
}
double Student::getGpa(){
	return gpa;
}
