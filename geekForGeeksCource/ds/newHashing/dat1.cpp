#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
//https://www.youtube.com/watch?v=G87TuBjByts&list=PLzjZaW71kMwQ-D3oxCEDHAvYu8VC1XOsS&index=3
bool HASH_TABLE[MAX+1][2]; // one col for +ve no and another for -ve
void fillTable(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            HASH_TABLE[arr[i]][0]=true;
        }else{
            HASH_TABLE[abs(arr[i])][1]=true;
        }
    }
}
bool check(int n){
    if(n>=0){
        return HASH_TABLE[n][0];
    }else{
        return HASH_TABLE[abs(n)][1];
    }
}
int main(){
    int arr[]={5,9,-10,24,-39,34,12,1,-1};
    int size=sizeof(arr)/sizeof(arr[0]);
    fillTable(arr,size);
    cout<<check(1)<<" "<<check(-10)<<" "<<check(-1)<<" "<<check(-9)<<endl;
    return 0;
}
