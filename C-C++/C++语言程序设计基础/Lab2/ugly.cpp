#include <iostream>
#include <math.h>
using namespace std;

bool ugly(int n){
	int tmp = 0, tmp1 = 0;
	for(int ii=2; ii<=n; ii++){
		if(n % ii == 0){
			tmp += 1;
			if(ii % 2 !=0 && ii % 3 !=0 && ii % 5 !=0){
				tmp1 += 1;
			}
		}
	}
	if(tmp == 0) {
		return false;
	}
	else {
		if (tmp1 ==0) {
			return true;
		}
		return false;
	}
}

int main(){
	int n;
	cin >> n;
	cout << (ugly(n)?"True":"False");
	return 0;
}
