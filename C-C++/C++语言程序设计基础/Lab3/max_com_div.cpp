#include <iostream>
using namespace std;
class Integer {
private:
    int _num;
public:
    Integer(int num) {
	    _num = num;
    }
    int gcd(Integer b) {
	    int tmp, MAX, MIN;
	    if (_num > b._num){
	    	MAX = _num;
		MIN = b._num;
	    }else{
	    	MAX = b._num;
		MIN = _num;
	    }
	    while (MAX % MIN != 0 ){
	    	tmp = MIN;
		MIN = MAX % MIN;
		MAX = tmp;
	    }
	    return MIN;
    }
};
int main(){
    int a, b;
    cin >> a >> b;
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
    return 0;
}
