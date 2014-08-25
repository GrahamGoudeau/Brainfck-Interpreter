Brainfck-Interpreter
====================

An interpreter for the esoteric programming language Brainfuck, written in C++.  The interpreter is able to check for matching brackets, check for invalid command characters, and implements the memory tape as a dynamic array that starts at memory cell 0 and is unbounded in the positive direction.

To compile, navigate to the program directory and type "make".  "make clean" removes the executable, *.o, and *~ files

Note: Brainfuck treats the memory cell values as ASCII values, so the cell values are always taken modulo 256

Errors that could be generated:
  * if tape_location is set to a value less than zero, the interpreter will return "ERROR: INVALID MEMORY INDEX ACCESS"
  * if the code contains unmatched brackets, the interpreter will return "ERROR: UNMATCHED BRACKETS"
  * the interpreter is unable to catch unbounded loops; if the user writes one (such as "+[>+]") the interpreter will crash
    as the program will have tried to allocate an infinite amount of memory
