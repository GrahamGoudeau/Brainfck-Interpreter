#include "match_stack.h"
#include <iostream>
using namespace std;

Stack::Stack() {
    mem_size    = 50;
    char_stack  = new char[mem_size];
    stack_index = 0;
}

Stack::~Stack() {
    delete [] char_stack;
}

void Stack::expand() {
    int new_mem_size = mem_size * 2 + 1;
    char *new_stack = new char[new_mem_size];
    for (int i = 0; i < new_mem_size; i++) {
  	if (i < mem_size)
	    new_stack[i] = char_stack[i];
    }

    delete [] char_stack;
    mem_size = new_mem_size;
    char_stack = new_stack;

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
    mem_size    = 50;
    int_stack   = new int[mem_size];
    stack_index = 0;
}

int_Stack::~int_Stack() {
    delete [] int_stack;
}

void int_Stack::expand() {
    int new_mem_size = mem_size * 2 + 1;
    int *new_stack = new int[new_mem_size];
    for (int i = 0; i < new_mem_size; i++) {
  	if (i < mem_size)
	    new_stack[i] = int_stack[i];
    }

    delete [] int_stack;
    mem_size = new_mem_size;
    int_stack = new_stack;
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
