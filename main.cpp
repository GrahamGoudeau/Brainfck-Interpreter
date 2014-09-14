#include <iostream>
#include <algorithm>
#include "Code.h"

using namespace std;

const string prompt = "\\ ";

void print_begin_prompt();
string remove_spaces(string brainfuck);

int main()
{
	print_begin_prompt();

	string brainfuck;
	cout << prompt;
	getline(cin, brainfuck);

	while (brainfuck != "exit") {
		brainfuck = remove_spaces(brainfuck);
		Source code = Source(brainfuck);
		if (code.is_valid() && code.is_matched())
			code.evaluate();

		cout << prompt;
		getline(cin, brainfuck);
	}
	return 0;
}

void print_begin_prompt() {
	cout << "BRAINFUCK INTERPRETER\n";
	cout << "End code with '@d' to enter debug mode; type 'done' to quit debugging\n";
	cout << "Type 'exit' to quit the interpreter\n\n";
}

string remove_spaces(string brainfuck) {
	brainfuck.erase(remove(brainfuck.begin(),brainfuck.end(),' '),brainfuck.end()); ///YOLO
	return brainfuck;
}


