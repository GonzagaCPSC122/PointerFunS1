#include <iostream>

using namespace std;

// comnand line args are passed into the program when it is run
// main() is overloaded to accepts these arguments
int main(int argc, char * argv[]) {
	// C-string is a null terminated char array
	// \0 is the null terminator
	cout << argc << endl;
	cout << argv[0] << endl;
	int i;
	for (i = 0; i < argc; i++) {
		string arg = argv[i]; // assign C-string to C++ string
		cout << arg << endl; // print out C++ string
	}

	return 0;
}
