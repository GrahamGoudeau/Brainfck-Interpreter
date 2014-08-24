#include <iostream>
#include "Code.h"
#include "match_stack.h"

using namespace std;


int mod (int a, int b);


Source::Source(string brainfuck) {
    source_code     = brainfuck;
    tape_head_loc   = 0;
    memory_size     = 10;
    memory_tape     = new int[memory_size];

    for (int i = 0; i < memory_size; i++)
        memory_tape[i] = 0;
}

Source::~Source() {
    delete [] memory_tape;
}

bool Source::is_valid() {
    int str_len = source_code.length();

    char valid_symbols[8] = {'<', '>', '+', '-', '[', ']', '.', ','};
    for (int i = 0; i < str_len; i++) {
        if (!in(source_code[i], valid_symbols)) {
            cout << "INVALID COMMAND AT " << i + 1 << ": '" << source_code[i] << "'" << endl;
            return false;
        }
    }

    return true;
}

bool Source::in(char character, char valid_symbols[]) {
    /// 8 valid characters to check
    for (int i = 0; i < 8; i++)
        if (valid_symbols[i] == character)
            return true;

    return false;
}

bool Source::is_matched() {
    Stack char_stack;
    int str_len = source_code.length();

    for (int i = 0; i < str_len; i++) {
        if (source_code[i] == '[')
            char_stack.push(source_code[i]);
        else if (source_code[i] == ']' && !char_stack.stack_empty())
            char_stack.pop();
        else if (source_code[i] == ']' && char_stack.stack_empty()) {
            cout << "IMPROPERLY MATCHED BRACKETS" << endl;
            return false;
        }
    }

    if (!char_stack.stack_empty()) {
        cout << "IMPROPERLY MATCHED BRACKETS" << endl;
        return false;
    }
    return true;
}

/// download more RAM here
void Source::expand() {
    int new_memory_size = memory_size * 2 + 1;
    int *downloaded_RAM = new int[new_memory_size];

    for (int i = 0; i < new_memory_size; i++)
        if (i < memory_size)
            downloaded_RAM[i] = memory_tape[i];
        else
            downloaded_RAM[i] = 0;

    memory_size = new_memory_size;
    memory_tape = downloaded_RAM;
}

/****************************************************
*                   EVALUATE                        *
****************************************************/

void Source::evaluate() {
    /// make this dynamic array
    int *loop_locations = new int[50];
    int current_loop    = 0;

    /// do we need a stack?
    int_Stack int_stack;

    string output_string = "";
    int source_code_length = source_code.length();

    for (int index = 0; index < source_code_length; index++) {
        char command = source_code[index];

        if (command == '+')
            memory_tape[tape_head_loc] = mod(memory_tape[tape_head_loc] + 1, 256);
        else if (command == '-')
            memory_tape[tape_head_loc] = mod(memory_tape[tape_head_loc] - 1, 256);

        else if (command == '>') {
            if (tape_head_loc + 1 == memory_size)
                expand();
            tape_head_loc++;
        }
        else if (command == '<')
            if (tape_head_loc - 1 < 0) {
                cout << "ERROR: INVALID MEMORY INDEX ACCESS\n";
                return;
            }
            else
                tape_head_loc--;

        else if (command == '[') {
            if (memory_tape[tape_head_loc] != 0) {
                loop_locations[current_loop] = index + 1;
                current_loop++;
            }
            else
                while (source_code[index] != ']')
                    index++;
        }
        else if (command == ']' && memory_tape[tape_head_loc] != 0)
            index = loop_locations[current_loop - 1] - 1;

        else if (command == ']' && memory_tape[tape_head_loc] == 0)
            current_loop--;

        else if (command == '.') {
            char output_letter = memory_tape[tape_head_loc];
            output_string += output_letter;
        }
        else if (command == ',') {
            string input;
            getline(cin, input);
            if (input == "\0")
                memory_tape[tape_head_loc] = 0;
            else
                memory_tape[tape_head_loc] = input[0];
        }

        /**for (int i = 0; i < memory_size; i++)
            cout << memory_tape[i] << " ";
        cout << endl;

        for (int i = 0; i < source_code_length; i++) {
            if (i == index) cout << "*";
            cout << source_code[i] << " ";
        }
        cout << endl << endl;

        string wait;
        getline(cin, wait);*/
    }

    delete [] loop_locations;

    for (int i = 0; i < memory_size; i++)
        cout << memory_tape[i] << " ";
    cout << endl;

    if (output_string.length())
        cout << output_string << endl;

}

int mod (int a, int b)
{
   int ret = a % b;
   if(ret < 0)
     ret+=b;
   return ret;
}
