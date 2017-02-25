#include <iostream>
using namespace std;

int main(){
	int n=0, sum=0, max=0, min=0, tmp=0;
	cin >> n;
	for(int ii=0; ii<n; ii++){
		cin >> tmp;
		sum += tmp;
		if(ii==0){
			max = tmp;
			min = tmp;
		}
		if(tmp > max){
			max = tmp;
		}
		if(tmp < min){
			min = tmp;
		}
	}
	cout << sum << " " << min << " " << max << endl;
}
