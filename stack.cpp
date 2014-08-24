#include "match_stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    char_stack  = new char[50];
    stack_index = 0;
}

Stack::~Stack() {
    delete [] char_stack;
}

void Stack::push(char character) {
    char_stack[stack_index] = character;

    stack_index++;
}

char Stack::pop() {
    stack_index--;

    return char_stack[stack_index];
}

bool Stack::stack_empty() {
    return stack_index == 0;
}



int_Stack::int_Stack() {
    int_stack = new int[50];
    stack_index = 0;
}

int_Stack::~int_Stack() {
    delete [] int_stack;
}

void int_Stack::expand() {

}

void int_Stack::push(int location) {
    int_stack[stack_index] = location;

    stack_index++;
}

int int_Stack::pop() {
    stack_index--;

    return int_stack[stack_index];
}

bool int_Stack::stack_empty() {
    return stack_index == 0;
}
