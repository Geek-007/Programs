#include <iostream>
#include <cmath>
#include <iomanip>  
using namespace std;
class Equation{
private:
    int _a, _b, _c;
public:
    Equation(int a, int b, int c){
    	_a=a;
    	_b=b;
    	_c=c;
    }
    void solve(){
    	cout.setf(ios::fixed);  
    	float ans1, ans2, delta;
    	delta=_b*_b-4.0*_a*_c;
    	if(_a==0 && _b==0 && _c!=0){
    		cout << 4 << endl;
    		goto nums;
    	}else if (_a==0&& _b!=0 && _c!=0){
    		cout << 6 <<endl;
    		cout << fixed<< setprecision(2)<< 1.0*-_c/_b<<endl;
    		goto nums;
    	}else if(_a==0 && _b==0 && _c==0){
    		cout <<5<<endl;
    		goto nums;
    	}
    	if(delta>0){
    		ans1=(-_b+sqrt(delta))/(2.0*_a);
    		ans2=(-_b-sqrt(delta))/(2.0*_a);
    		cout << 1 <<endl;
    		if(ans1>ans2){
    			cout << fixed<< setprecision(2)<<ans2 << " " <<ans1 <<endl;
    		}else{
    			cout << fixed<< setprecision(2)<<ans1 <<" " <<ans2 <<endl;
    		}
    	}else if (delta==0){
    		ans1 = -_b/(2.0*_a);
    		cout << 2 <<endl;
    		cout << fixed<< setprecision(2) <<ans1 <<endl;
    	}else if (delta<0){
    		cout << 3 <<endl;
    	}
nums:;
    }
};
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    Equation tmp(a, b, c);
    tmp.solve();
}