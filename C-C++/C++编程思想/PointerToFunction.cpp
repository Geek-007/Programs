//: C03: PointerToFunction.cpp
// Definiting and using a pointer to a function
#include <iostream>
using namespace std;

void func(){
	cout << "func() called..." << endl;
}

int main(){
	void (*fp)(); // Define a function pointer
	fp = func;
	(*fp)(); // Dereferencing calls the function
	void (*fp2)() = func;
	(*fp2)();
}///:~
