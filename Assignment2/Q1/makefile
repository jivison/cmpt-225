all:	x

x:	Stack.o StkTest.o
	g++ -o x Stack.o StkTest.o

Stack.o:	Stack.cpp Stack.h
	g++ -c Stack.cpp

StkTest.o:	StkTest.cpp Stack.h
	g++ -c StkTest.cpp

clean:
	rm -f x *.o

