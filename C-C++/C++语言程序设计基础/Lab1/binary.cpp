#include <iostream>
#include <math.h> 
using namespace std;

int main(){
	int bint=0, tmp=0, ii=0, out=0;
	cin >> bint;
	while(bint){
		tmp = bint % 10;
		out = out + tmp * pow(2, ii++);
		bint/=10;
	}
	cout << out;
	return 0;
}
