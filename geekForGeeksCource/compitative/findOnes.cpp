#include<bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=2Yy9rKwkE7g&list=PLzjZaW71kMwQRAtBdJAq3u64ZEw-0wxgI&index=13
int findOnes(int arr[],int n){
    int l=0;
    int h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]==1){
            if(m+1==n || arr[m+1]==0) return m+1;
            else if(arr[m]==1 && (m+1<n &&arr[m+1]==1)) l=m+1;
        }
        else h=m-1;
    }
    return -1;
}

int main(){
    int arr[]={0,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<findOnes(arr,n)<<"\n";
    return 0;
}
