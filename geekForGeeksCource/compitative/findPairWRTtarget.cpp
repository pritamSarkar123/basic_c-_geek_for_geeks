#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=7xx1YcXXEYU

bool check_pair(const vector<int> &arr,const int &target){
	unordered_map<int,int> um;
	for(int i=0;i<arr.size();i++) um[arr[i]]++;
	for(auto x=um.begin();x!=um.end();x++){
		int number=x->first;
		int number_count=x->second;
		int pair = target - number;
		if(pair == number){
			if(number_count>1) return true;// both same number, and both present in array
		}else if(um.find(pair)!=um.end()) return true; //when pair != number, and pair present in array
	}
	return false; // pair is not present in array
}

int main(){
	//vector<int> arr{2,3,4,5,6,9};
	// vector<int> arr{2,3,5,5,6,9};
	vector<int> arr{2,3,5,6,9};
	int target=10;
	cout<<check_pair(arr,target)<<endl;
	return 0;
}
