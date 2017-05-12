#include <iostream>
using namespace std;
 
/*请在这里填充代码*/
template<typename T>
T getSum(const T *array, int n) {
       T result = 0;
       for(int ii=0; ii<n; ii++) {
              result += array[ii];
       }
       return result;
} 

int main()
{
       int n, m;
       cin >> n >> m;
       int* arr_int = new int[n];
       double* arr_double = new double[m];
       for (int i = 0; i < n; ++i)
              cin >> arr_int[i];
       for (int i = 0; i < m; ++i)
              cin >> arr_double[i];
       cout << getSum(arr_int, n) << endl;
       cout << getSum(arr_double, m) << endl;
       return 0;
}