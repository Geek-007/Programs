//: C03: Assert.cpp
// Use of the assert() debugging macro
#include <iostream> // Contains the macro
#include <cassert>
using namespace std;

int main(){
	int i = 100;
	assert(i != 100); // Fails
}///:~
