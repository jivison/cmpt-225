all: main

main: Main.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o
	g++ -Wall -o main Main.o ElementAlreadyExistsException.o ElementDoesNotExistException.o EmptyDataCollectionException.o

Main.o: Main.cpp
	g++ -Wall -c Main.cpp
		
WordPair.o: WordPair.h WordPair.cpp
	g++ -Wall -c WordPair.cpp

ElementDoesNotExistException.o: ElementDoesNotExistException.h ElementDoesNotExistException.cpp
	g++ -Wall -c ElementDoesNotExistException.cpp

ElementAlreadyExistsException.o: ElementAlreadyExistsException.h ElementAlreadyExistsException.cpp
	g++ -Wall -c ElementAlreadyExistsException.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f translate *.o