Brainfck-Interpreter
====================

Interpreter for the esolang Brainfuck.  This interpreter is able to check for matching brackets, checks for invalid command characters, and implements the memory tape as a dynamic array that starts at memory cell 0 and is unbounded in one direction.

An error is raised if a brainfuck code causes the memory_tape_location < 0 ("ERROR: INVALID MEMORY ACCESS"); bad_alloc error is raised if the user accidentally writes an unbounded loop (such as: "+[>+]").  The interpreter will not catch this and will crash.
