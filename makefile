all: brainfck_1.0

brainfck_1.0: main.o Code.o Stack.o
	g++ main.o Code.o Stack.o -o brainfck_1.0
              
main.o: main.cpp
	g++ -c main.cpp -o main.p

Code.o: Code.cpp Code.h      
	g++ -c Code.cpp Code.h -o Code.o
	
Stack.o: match_stack.h stack.cpp
	g++ -c match_stack.h stack.cpp -o Stack.o
