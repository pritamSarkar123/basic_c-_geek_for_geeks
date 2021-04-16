#include<bits/stdc++.h>
using namespace std;

long long int squareRoot(long long int x){
    long long int low=1;
    long long int high=x/2; // square root of num always <= half of that number
    while(low<=high){
        long long int mid=(low+high)/2;
        long long int mids=mid*mid;
        long long int mids_plus_one=(mid+1)*(mid+1);
        if(mids==x) return mid;
        else if(mids<x){
            if(mids_plus_one>x) return mid;
            else low=mid+1;
        }
        else high=mid-1;
    }
}
int main(){
    cout<<squareRoot(15)<<endl;
    cout<<squareRoot(1)<<endl;
    cout<<squareRoot(5)<<endl;
    cout<<squareRoot(8)<<endl;
    cout<<squareRoot(25)<<endl;
    return 0;
}
