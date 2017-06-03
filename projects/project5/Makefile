
output: project5.o catalog.o book.o
	g++  project5.o catalog.o book.o -o output

project3.o: project5.cpp
	g++ -c project5.cpp

catalog.o: catalog.cpp catalog.h
	g++ -c catalog.cpp

book.o: book.cpp book.h
	g++ -c book.cpp
clean:
	rm -rf *.o

