#include <iostream>
#include <cstring>

using namespace std;

// command line args are passed into the program when it is run
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
	// 0 1 2 3 4
	// f o o d \0
	// #include <cstring> you can use several
	// C-string functions
	// strlen()
	char myWord[] = "food";
	cout << myWord << endl;
	cout << strlen(myWord) << endl;
	cout << sizeof(myWord) << endl; // 5 chars * 1 byte per char = 5 bytes
	// other useful cstring functions
	// strcat() +
	// strcmp() < > <=...
	// strcpy() copy

	return 0;
}
