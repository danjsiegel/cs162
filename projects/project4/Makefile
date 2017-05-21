
output: project4.o catalog.o book.o
	g++  project4.o catalog.o book.o -o output

project4.o: project4.cpp
	g++ -c project4.cpp

catalog.o: catalog.cpp catalog.h
	g++ -c catalog.cpp

book.o: book.cpp book.h
	g++ -c book.cpp
clean:
	rm -rf *.o

