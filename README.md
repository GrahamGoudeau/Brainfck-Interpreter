Brainfck-Interpreter
====================

An interpreter for the esoteric programming language Brainfuck, written in C++.  Brainfuck is a minimalistic programming language that operates on a memory tape (each cell contains an ASCII value 0-255), and the language itself consists of eight valid commands:
* ">": increment tape reader head
* "<": decrement tape reader head
* "+": increase current memory cell value (mod 256)
* "-": decrease current memory cell value (mod 256)
* "[": mark beginning of code to be looped
* "]": return to beginning of loop if the current cell value is not zero else continue
* ",": read in a single char from the keyboard 
* ".": print out the char that results from the current cell's ASCII value


The interpreter is able to check for matching brackets, check for invalid command characters, and implements the memory tape as a dynamic array that starts at memory cell 0 and is (effectively) unbounded in the positive direction (limited by available system memory).

To compile, navigate to the program directory and type "make".  "make clean" removes the executable, *.o, and *~ files

Note: Brainfuck treats the memory cell values as ASCII values, so the cell values are always taken modulo 256

Errors that could be generated:
  * if tape_location is set to a value less than zero, the interpreter will return "ERROR: INVALID MEMORY INDEX ACCESS"
  * if the code contains unmatched brackets, the interpreter will return "IMPROPERLY MATCHED BRACKETS"
  * if the interpreter reaches an invalid command it will return "INVALID COMMAND AT [LOCATION]"
  * the interpreter is unable to catch unbounded loops; if the user writes one (such as "+[]") the interpreter will crash
