#include <iostream>
#include <cmath>
using namespace std;

bool triangle(int a, int b, int c);

int main(){
	int a, b, c;
	cin >> a, cin >> b, cin >> c;
	cout << (triangle(a, b, c)?"True":"False");
	return 0;
}

bool triangle(int a, int b, int c){
	if(a*a+b*b==c*c){
		return true;
	}
	if(b*b+c*c==a*a){
		return true;
	}
	if(a*a+c*c==b*b){
		return true;
	}
	return false;
}
