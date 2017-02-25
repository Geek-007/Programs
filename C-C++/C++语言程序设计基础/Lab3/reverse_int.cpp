#include <iostream>
using namespace std;
 
class Integer{
private:
    int _num;
    int getLength(){
        int len=0, tmp=_num;
        while(tmp){
            tmp/=10;
            len+=1;
        }
        return len;
    }
public:
    Integer(int num){
        _num=num;
    }
    int inversed(){
        int len=getLength();
        int tmp;
        int out=0;
        while(len){
            tmp=_num%10;
            out=out*10+tmp;
            len-=1;
            _num=_num/10;
        }
        return out;
    }
};
 
int main() {
    int n;
    cin >> n;
    Integer integer(n);
    cout << integer.inversed() << endl;
}