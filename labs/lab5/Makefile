
prog: studentmain.o student.o
	g++  studentmain.o student.o -o prog

studentmain.o: studentmain.cpp
	g++ -c studentmain.cpp

student.o: student.cpp student.h
	g++ -c student.cpp
clean:
	rm -rf *.o

