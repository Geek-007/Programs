#include <iostream>
#include <vector>
using namespace std;

int find_max_subarray_sum(int nums[], int n){
	int max_sum = 0;
	int sum = 0;
	for(int ii=0; ii<n; ii++){
		sum = sum + nums[ii];
		if(sum > max_sum){
			max_sum = sum;
		}else{
			if(sum < 0){
				sum = 0;
			}
		}
	}
	return max_sum;
}

int main(){
	int n;
	cin >> n;
	int nums[n];
	for(int ii=0; ii<n; ii++){
		cin >> nums[ii];
	}
	int max_sum;
	max_sum = find_max_subarray_sum(nums, n);
	cout << max_sum;
	return 0;
}
