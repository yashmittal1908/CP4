all:	CP4

Activity:	CP4.o funcs.o
	g++ CP4.o funcs.o

CP4.o:	CP4.cpp
	g++ -c CP4.cpp

funcs.o: funcs.cpp
	g++ -c funcs.cpp

clean:
	rm -f *.o CP4.exe
