all: brainfck_1

main.o: main.cpp
	g++ -c main.cpp -o main.o

Code.o: Code.cpp Code.h
	g++ -c Code.cpp -o Code.o

Stack.o: match_stack.h stack.cpp
	g++ -c stack.cpp -o Stack.o

brainfck_1: main.o Code.o Stack.o
	g++ main.o Code.o Stack.o -o brainfck_1

clean:
	$(RM) brainfck_1 *.o
