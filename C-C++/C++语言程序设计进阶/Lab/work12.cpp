#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int res=0;
    for(int i=0;i<a.length()-b.length()+1;i++)
    {
        if(b==a.substr(i,b.length()))
        {
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}