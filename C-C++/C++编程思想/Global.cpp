//: C03: Global.cpp
// {L} Global2
// Demonstratoin of global variables
#include <iostream>
using namespace std;

int globe;
void func();
int main(){
	globe = 12;
	cout << globe << endl;
	func();// Modifies globe
	cout << globe << endl;
}
