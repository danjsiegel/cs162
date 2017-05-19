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
	const char *getLastName();
	const char *getFirstName();
	const double getGpa(); 
  private:
	char *firstName;
	char *lastName;
	double gpa;
};

#endif
