#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=MN37co8M37g

char firstNonRepeatingCharacter(string s){
    int chars=256;
    int arr[chars];
    fill(arr,arr+chars,0);
    int n=s.size();
    for(int i=0;i<n;i++){
        arr[s[i]]++;
    }
    for(int i=0;i<n;i++){
        if(arr[s[i]]==1) return s[i];
    }
    return '$';
}

int main(){
    string s="abcdancdsesb";
    cout<<firstNonRepeatingCharacter(s)<<endl;
    return 0;
}
