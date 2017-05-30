#include <map>
#include <string>
#include <utility>
#include <iostream>
using namespace std;
int out[100]; 
int main(){
    map<string,int> m;
    string c;
    int i=0;
    while(true){
        cin>>c;
        if(c=="QUIT"){
            break;
        }
        out[i]=m[c];//这里的m[c]就是map m中c对应的个数int
        m[c]++;
        i++;
    }

    for(int j=0;j<i;j++)
    cout<<out[j]<<endl;

    return 0;
}