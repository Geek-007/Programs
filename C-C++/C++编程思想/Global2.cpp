//: C03: Global2.cpp {o}
// Accessing external global variables
extern int globe;
// The linker resolves the reference
void func(){
	globe = 47;
}///:~
