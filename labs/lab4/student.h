//Dan Siegel
//Lab4
//Header File for Book Class
#ifndef STUDENT_H
#define STUDENT_H

class Student {
  public:
	Student();
	Student(char first[], char last[], double Ugpa); 
  	void setFirstName(char fname[]);
	void setLastName(char lname[]);
	void setGpa(double grade);
	void print();
	double getGpa(); 
  private:
	char firstName[200];
	char lastName[200];
	double gpa;
};

#endif
