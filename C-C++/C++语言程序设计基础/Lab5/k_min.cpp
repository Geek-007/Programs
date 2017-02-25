#include <iostream>  
#include <vector>  
using namespace std;  
  
void swap(int &a,int &b){  
    int temp;  
    temp=a;  
    a=b;  
    b=temp;  
}  
  
int Partition(vector<int> &array,int low,int high){  
    int pivot=array[low];  
    while(low<high){  
        while(low<high&&array[low]<=array[high])   high--;  
        swap(array[low],array[high]);  
        while(low<high&&array[low]<=array[high])   low++;  
        swap(array[high],array[low]);         
    }  
    array[high]=pivot;  
    return high;  
}  
  
  
void QuickSort(vector<int> &array,int low,int high){  
    if(low<high){  
        int pivot=Partition(array,low,high);  
        QuickSort(array,low,pivot-1);  
        QuickSort(array,pivot+1,high);  
    }  
    return;  
}  
  
int main(){  
    int n,k;  
    cin>>n;  
    if(n<0||n>5000)   return false;  
    cin>>k;  
    if(k<0||k>n)      return false;  
    vector<int>array(n);  
    for(int i=0;i<n;i++){  
        cin>>array[i];  
        if(array[i]<-5000||array[i]>5000)  return false;  
    }  
    QuickSort(array,0,n-1);  
    cout<<array[k-1]<<endl;  
    return 0;  
}   