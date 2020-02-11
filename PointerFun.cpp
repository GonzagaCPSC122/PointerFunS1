#include <iostream>

using namespace std;

void divide(int num, int den, int * res, int * rem);
void printArray(int * arr, int size);
void swapIt(int * xPtr, int * yPtr);
int * createRandomArray(int size);

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
	
	int x = 5;
	int y = 7;
	swapIt(p, q);
	cout << x << " " << y << endl;
	
	// DYNAMIC MEMORY ALLOCATION
	// recall: a local variable is a variable
	// define inside a function
	// when a function exits, local variables are deallocated
	// local variables are declared in a region of memory called the "stack"
	// NEVER return the address of a local variable
	// to return memory allocated in a function, that memory must be allocated in the "heap" AKA free store
	// heap memory is not deallocted when the function exits
	// it is deallocated when you (the programmer) "free" it
	// if you don't free it, then you program has a "memory leak"
	// use the "new" keyword to dyn allocate memory in the heap
	// use the "delete" keyword to free memory that from the heap
	// example: a function that allocates
	// an array and returns the array
	int * randArr = NULL;
	randArr = createRandomArray(10);
	printArray(randArr, 10);
	// don't forget to delete!!
	delete [] randArr; // deallocates AKA frees
	randArr = NULL; // good practice
	
	return 0;
}

int * createRandomArray(int size) {
	int i; // statically allocated on the stack
	int * arr = new int[size]; // dyn allocated on the heap
	for (i = 0; i < size; i++) {
		*(arr + i) = rand() % size;
	}
	return arr; // calling code's responisiblity to free arr when its done with it
}

void swapIt(int * xPtr, int * yPtr) {
	xPtr = yPtr;
	int temp = *xPtr; // 5
	*xPtr = *yPtr; // 7
	*yPtr = temp; // 5
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
