#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=V5-7GzOfADQ
//https://www.youtube.com/watch?v=GTJr8OvyEVQ
void table(string str,vector<int>& pi){
	int j=0;
	int i=j+1;
	while(i<pi.size()){
		if(str[i]==str[j]){
			pi[i]=j+1;
			j++;
		}
		else{
			while(j>0 && str[i]!=str[j]) j=pi[j-1];
			if(j==0 && str[i]!=str[j]) pi[i]=0;
			else{
				pi[i]=j+1;j++;
			}
		}
		i++;
	}
}
int find(string text,string pattern,vector<int>& pi){
	int i=0;
	int j=0;
	while(true){
		if(j==pattern.length()) return i-j;
		if(i==text.length()) return -1;
		if(pattern[i]==text[i]) j++;
		else{
			while(j>0 && pattern[j]!=text[i]) j=pi[j];
			if(j!=0 || pattern[j]==text[i]) j++;
		}
		i++;
	}
}
int main(){
// 	string str="aaaabaacd";
    string pattern="ababd";
	vector<int> pi(pattern.length(),0);
	table(pattern,pi);
	string text="ababcabcababababd";
	for(int k=0;k<pattern.length();k++){
		cout<<pi[k]<<" ";
	}cout<<endl;
	cout<<find(text,pattern,pi)<<endl;
	return 0;
}