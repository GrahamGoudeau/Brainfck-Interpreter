CXX=g++
CFLAGS=-Wall -Wextra


all: brainfck_1

main.o: main.cpp
        $(CXX) $(CFLAGS) -c main.cpp -o $@

Code.o: Code.cpp Code.h
        $(CXX) $(CFLAGS) -c Code.cpp -o $@
        
Stack.o: match_stack.h stack.cpp
        $(CXX) $(CFLAGS) -c stack.cpp -o $@

brainfck_1: main.o Code.o Stack.o
        $(CXX) $(CFLAGS) main.o Code.o Stack.o -o $@

clean:
        $(RM) brainfck_1 *.o *~
