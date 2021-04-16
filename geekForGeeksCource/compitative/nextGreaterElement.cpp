#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=sDKpIO2HGq0&t=2s


int main(){
	vector<int> arr{13,8,5,12,15};
	vector<int> next_greater(arr.size(),0);
	stack<int> s;

	int i=0;
	// s.push(i); //pushing the 1st element of the array
	// i++;
	while(i<arr.size()){
		while(!s.empty() && arr[i] > arr[s.top()] ){
			next_greater[s.top()]=arr[i];
			s.pop();
		}s.push(i);
		i++;
	}
	while(!s.empty()){
		next_greater[s.top()]=-1;
		s.pop();
	}

	for(int i=0;i<next_greater.size();i++){
		cout<<next_greater[i]<<" ";
	}cout<<"\n";
	return 0;
}



