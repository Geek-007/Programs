#include <iostream>
#include <math.h>
using namespace std;

unsigned long fib(unsigned long n);

int main(){
	unsigned long n;
	cin >>n;
	cout << fib(n+1);
	return 0;
}

unsigned long fib(unsigned long n){
	return (long)( sqrt(5)/5.0 * (pow((1+sqrt(5))/2.0,n) - pow((1-sqrt(5))/2.0,n)) );
}
