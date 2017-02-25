#include <iostream>
using namespace std;

int fib(int n);

int main(){
	int n;
	cin >>n;
	cout << fib(n);
	return 0;
}

int fib(int n){
	int f0 = 1;
	int f1 = 1;
	int tmp;
	if(n==0||n==1){
		return 1;
	}else{
		return fib(n-1) + fib(n-2);
	}
}
