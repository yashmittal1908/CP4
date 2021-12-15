all:	CP4

CP4:	CP4.o UserTree.o VoteHeap.o
	g++ $^ -o $@.exe

%.o : %.cpp
	g++ -c $< -o $@

clean:
	rm -f *.o CP4.exe
