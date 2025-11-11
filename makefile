.DEFAULT_GOAL: all

.SILENT:

all:	Test4


COMP = g++ -Wall -std=c++17 -DDEBUG 

Test4:	Test4.cpp Person.o
		g++ Test4.cpp Person.o -o Test4
		$(COMP) -c Person.cpp
		echo compilation Test4.cpp

Person.o:	Person.cpp Person.h
			g++ Person.cpp -c 
			$(COMP) -c Person.cpp
			echo compilation Person.o


clean:
	rm -r -f *.o Test4

clobber:	clean

