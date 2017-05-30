#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main(){
	int nums;
	int tmp;
	vector<int> out;
	cin >> nums;
	for(int ii=0; ii<nums; ii++) {
		cin >> tmp;
		out.push_back(tmp);
	}
	sort(out.begin(), out.end());
	vector<int>::iterator new_end = unique(out.begin(), out.end());
	out.erase(new_end,out.end());
	for(int ii=0; ii<out.size(); ii++)
		cout << out[ii] << endl;
}
