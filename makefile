CXX=g++
CFLAGS=-Wall -Wextra -c


all: brainfck_1

main.o: main.cpp
        $(CXX) $(CFLAGS) main.cpp -o $@

Code.o: Code.cpp Code.h
        $(CXX) $(CFLAGS) Code.cpp -o $@
        
Stack.o: match_stack.h stack.cpp
        $(CXX) $(CFLAGS) stack.cpp -o $@

brainfck_1: main.o Code.o Stack.o
        $(CXX) main.o Code.o Stack.o -o $@

clean:
        $(RM) brainfck_1 *.o *~
