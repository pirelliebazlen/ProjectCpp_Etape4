.DEFAULT_GOAL: all

.SILENT:

all:	Test4


COMP = g++ -Wall -std=c++17 -DDEBUG 

Test4:	Test4.cpp Person.o Actor.o Client.o Employee.o
		g++ Test4.cpp Person.o Actor.o Client.o Employee.o -o Test4
		$(COMP) -c Person.cpp
		echo compilation Test4.cpp

Person.o:	Person.cpp Person.h
			g++ Person.cpp -c 
			$(COMP) -c Person.cpp
			echo compilation Person.o

Actor.o:	Actor.cpp Actor.h
			g++ Actor.cpp -c
			$(COMP) -c Actor.cpp
			echo compilation Actor.o

Client.o:	Client.cpp Client.h
			g++ Client.cpp -c
			$(COMP) -c Client.cpp
			echo compilation Client.o

Employee.o:	Employee.cpp Employee.h
			g++ Employee.cpp -c
			$(COMP) -c Employee.cpp
			echo compilation Employee.o

clean:
	rm -r -f *.o Test4

clobber:	clean

