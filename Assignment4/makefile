all: bsim

bsim: BankSimApp.o EmptyDataCollectionException.o Event.o BinaryHeap.h
	g++ -Wall -o bsim BankSimApp.o EmptyDataCollectionException.o Event.o

BankSimApp.o: BankSimApp.cpp
	g++ -Wall -c BankSimApp.cpp
		
Event.o: Event.h Event.cpp
	g++ -Wall -c Event.cpp
		
EmptyDataCollectionException.o: EmptyDataCollectionException.h EmptyDataCollectionException.cpp
	g++ -Wall -c EmptyDataCollectionException.cpp

clean:
	rm -f bsim *.o