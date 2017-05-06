
output: project3.o catalog.o books.o
	g++  project3.o catalog.o books.o -o output

project3.o: project3.cpp
	g++ -c project3.cpp

catalog.o: catalog.cpp catalog.h
	g++ -c catalog.cpp

books.o: books.cpp books.h
	g++ -c books.cpp
clean:
	rm *.o output

