//Dan Siegel
//lab4
#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

Student::Student(){
	firstName = NULL;
	lastName = NULL;
	gpa = 0;
}
void Student::setFirstName(char fname[]){
	if (firstName != NULL){
		delete firstName;
	}
	firstName = new char[strlen(fname) + 1];
	strcpy(firstName, fname);
}
void Student::setLastName(char lname[]){
	if (lastName != NULL){
		delete lastName;
	}
	lastName = new char[strlen(lname) + 1];
	strcpy(lastName, lname);
}
void Student::setGpa(double grade){
	if (!grade || (grade>4) || (grade<0)){
		gpa = 0;
	} else {	
		gpa = grade;
	}
}

const char *Student::getFirstName(){
	return firstName;
}
const char *Student::getLastName(){
	return lastName;
}
const double Student::getGpa(){
	return gpa;
}
