#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=KpjXziZMHwI

int firstNonRepeatingEelement(int arr[],int len){
    unordered_map<int,int> um;
    for(int i=0;i<len;i++) um[arr[i]]++;
    for(int i=0;i<len;i++){
        if(um[arr[i]]==1) return arr[i];
    }
    return 0; // if everything repeated
}

int main(){
    int arr[]={-1,2,3,-1,2};
    cout<<firstNonRepeatingEelement(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
    return 0;
}
