#ifndef CODE_H_INCLUDED
#define CODE_H_INCLUDED

#include <iostream>
using namespace std;


class Source {

public:
    Source(string brainfuck);
    ~Source();

    bool is_valid();
    bool is_matched();
    void evaluate();

private:
    string source_code;
    int tape_head_loc;
    int memory_size;
    int *memory_tape;

    bool in(char character, char valid_symbols[]);
    void expand();
};

#endif // CODE_H_INCLUDED
