#include <iostream> 
using namespace std; 
int main(){
	int n=0, tmp=0;
	cin >> n;
	for(int ii=1; ii<=2*n-1; ii++){
		tmp = ii<=n?ii:2*n-ii; 
		for(int jj=1; jj<=2*n-1; jj++){
			if(jj>(n-tmp) && jj < (n+tmp)){
				cout<<"*";
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}