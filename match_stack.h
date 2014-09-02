#ifndef MATCH_STACK_H_INCLUDED
#define MATCH_STACK_H_INCLUDED

#include <iostream>
using namespace std;

class Stack {
public:
    Stack();
    ~Stack();
    void push(char character);
    char pop();
    bool stack_empty();

private:
    char *char_stack;
    int stack_index;
    int mem_size;

    void expand();
};

class int_Stack {
public:
    int_Stack();
    ~int_Stack();
    void push(int location);
    int pop();
    bool stack_empty();

private:
    int *int_stack;
    int stack_index;
       
    int mem_size;
    void expand();
};

#endif // MATCH_STACK_H_INCLUDED
