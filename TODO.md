* change the loop location array to a stack/dynamic array
* if above is kept as an array, delete int_stack class
* change the type of the "source code" to an array
    (this eliminates the need to remove spaces from the string; loop through the string and place valid chars into
    a dynamic array, then call .is_matched()/.is_valid() on the array [shouldn't have to change parameters])
* add debugging option (commented code in code.cpp towards end of evaluate())
* debug branch: throw error if '@d' is located anywhere other than the end of the code
