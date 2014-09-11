#include <iostream>
#include "Code.h"
#include "match_stack.h"

using namespace std;

/**
 * purp: override c++ bulit in mod function, which can return negative values
 * note: if c++ (a%b) operation returns negative value, add b which produces (b-1)
 */
int mod (int a, int b);

/**
 * purp: initialize source class with string parameter, tape head set to beginning of memory,
 *	   memory initially set to 10 memory cells, all set to 0
 */
Source::Source(string brainfuck) {
	source_code	 = brainfuck;
	tape_head_loc	 = 0;
	memory_size	 = 10;
	memory_tape	 = new int[memory_size];
	debug		 = in_debug(source_code);
	if (debug) {
		int source_length = source_code.length();
		source_code.erase(source_length - 1, 1);
		source_code.erase(source_length - 2, 1);
	}
		

	for (int i = 0; i < memory_size; i++)
		memory_tape[i] = 0;
}

/**
 * purp: ensure that the memory tape storage is properly deleted
 */
Source::~Source() {
	delete [] memory_tape;
}

/**
 * purp: check every character in the brainfuck code, return false on invalid commands
 * note: prints out location of first located invalid command
 */
bool Source::is_valid() {
	int str_len = source_code.length();
	bool at_signal = false;
	bool debug_command = false;

	char valid_symbols[10] = {'<', '>', '+', '-', '[', ']', '.', ',', '@', 'd'};
	for (int i = 0; i < str_len; i++) {
		if (!in(source_code[i], valid_symbols)) {
			cout << "INVALID COMMAND AT " << i + 1 << ": '" << source_code[i] << "'" << endl;
			return false;
		}
		else if (source_code[i] == '@')
			at_signal = true;

		if (source_code[i] == 'd' && !at_signal) {
			cout << "INVALID COMMAND AT " << i + 1 << ": '" << source_code[i] << "'" << endl;
			return false;
		}
		else if (source_code[i] == 'd')
			debug_command = true;
	}

	
	if (at_signal && !debug_command) {
		cout << "COMMAND SIGNAL '@' SENT; NO COMMAND FOUND" << endl;
		return false;
	}
	return true;
}

/**
 * purp: check to see if char parameter is included in the list of valid symbols
 *	   returns true at first valid character that matches the given parameter
 */
bool Source::in(char character, char valid_symbols[]) {
	/// 10 valid characters to check
	for (int i = 0; i < 10; i++)
		if (valid_symbols[i] == character)
			return true;

	return false;
}

/**
 * purp: check to see if all brackets are matched correctly
 * note: utilizes char_stack class in match_stack.h
 */
bool Source::is_matched() {
	Stack char_stack;
	int str_len = source_code.length();

	for (int i = 0; i < str_len; i++) {
		if (source_code[i] == '[')
			/// if open bracket, push the bracket onto the stack
			char_stack.push(source_code[i]);
		else if (source_code[i] == ']' && !char_stack.stack_empty())
			/// if open brackets are on the stack, pop one off (pop off matching open bracket)
			char_stack.pop();
		else if (source_code[i] == ']' && char_stack.stack_empty()) {
			/// if close bracket but empty stack, indicates no matching open bracket
			cout << "IMPROPERLY MATCHED BRACKETS" << endl;
			return false;
		}
	}

	if (!char_stack.stack_empty()) {
		/// if stack is not empty by the end of the code, indicates hanging open bracket
		cout << "IMPROPERLY MATCHED BRACKETS" << endl;
		return false;
	}
	return true;
}

bool Source::in_debug(string source) {
	int source_length = source.length();
	if (source[source_length - 1] == 'd' &&
		source[source_length - 2] == '@')
		return true;
	return false;
}

/// download more RAM here
/**
 * purp: expand the dynamic array containing the memory tape
 */
void Source::expand() {
	int new_memory_size = memory_size * 2 + 1;
	int *downloaded_RAM = new int[new_memory_size];

	/// copy old memory values into new expanded array
	for (int i = 0; i < new_memory_size; i++)
		if (i < memory_size)
			downloaded_RAM[i] = memory_tape[i];
		else
			downloaded_RAM[i] = 0;

	/// update memory to increased size, update pointer to memory
	memory_size = new_memory_size;
	memory_tape = downloaded_RAM;
}

/****************************************************
*		      EVALUATE          	    *
****************************************************/

/**
 * purp: code valuation manager
 */
void Source::evaluate() {
	int_Stack loop_loc_stack;

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
		loop_loc_stack.push(index);		
			}
			else
				while (source_code[index] != ']')
					index++;
		}
		else if (command == ']' && memory_tape[tape_head_loc] != 0) {
		index = loop_loc_stack.pop();
		loop_loc_stack.push(index);	
	}
		else if (command == ']' && memory_tape[tape_head_loc] == 0)
		loop_loc_stack.pop();
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

		if (debug) {
			for (int i = 0; i < memory_size; i++) {
				if (i == tape_head_loc)
					cout << "*";

				cout << memory_tape[i] << " ";
			}
			cout << endl;

			for (int i = 0; i < source_code_length; i++) {
				if (i == index) cout << "*";
					cout << source_code[i] << " ";
			}
			cout << endl << endl;

			string wait;
			getline(cin, wait);
			if (wait == "done") break;
		}
	}

	for (int i = 0; i < memory_size; i++)
		cout << memory_tape[i] << " ";
	cout << endl;

	if (output_string.length())
		cout << output_string << endl;

}

int mod (int a, int b) {
   int result = a % b;
   if(result < 0)
	 result += b;
	 
   return result;
}
