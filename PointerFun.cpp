#include <iostream>

using namespace std;

void divide(int num, int den, int * res, int * rem);
void printArray(int * arr, int size);

int main() {
	int i = 3, j = 5, k;
	int * p = &i, * q = &j, * r;
	r = &k;
	*r = *p * *q;

	cout << i << " " << j << " " << k << " " << endl;
	cout << *p << " " << *q << " " << *r << " " << endl;
	cout << &i << " " << &j << " " << &k << " " << endl;
	cout << p << " " << q << " " << r << " " << endl;
	
	// recall: a pointer is a variable that stores as its contents
	// the memory address of another variable
	// summary of the many uses of the *
	// 1) multiplication operator
	// e.g. 3 * x
	// 2) pointer type
	// e.g. int * ptr;
	// 3) unary indirection operator
	// e.g. *ptr = 5;
	// AKA "dereferences a pointer"
	// AKA "follow the pointer"
	// AKA "the contents of what the pointer points to"
	
	// summary of the two uses of the &
	// 1) declare a reference variable
	// e.g. int & result; // reference to an int
	// 2) address of operator
	// e.g. &i; // "address of i"
	
	// OUTPUT PARAMETERS
	// recall you can only return one value via the reutrn statement
	// but you can return multiple values via pass by reference
	// these are parameters that "output" results
	// we can use pointers for output parameters
	// a function that divides two integers and returns the
	// result AND the remainder
	int result, remainder;
	divide(13, 11, &result, &remainder);
	cout << "result: " << result << " remainder: " << remainder << endl;
	
	// POINTER ARITHMETIC AND POINTER NOTATION
	// recall: arrays are pass by reference...
	// but! what is happening is the memory address of the
	// first element of the array is passed (copied) into 
	// a pointer parameter
	int nums[] = {3, 56, 9, 1}; 
	int size = 4;
	printArray(nums, size);

	return 0;
}

void printArray(int * arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		//cout << arr[i] << " "; // array notation
		cout << *(arr + i) << " "; // pointer notation
		// i is the memory offset
		// add i memory cells (4 bytes for int) to
		// the memory address stored in arr
	}
	cout << endl;
}

void divide(int num, int den, int * res, int * rem) {
	*res = num / den; //int div
	// "the contents of what res points to is assigned num div den"
	*rem = num % den; // mod
}
