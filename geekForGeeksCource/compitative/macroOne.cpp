#include<bits/stdc++.h>
//about:- https://www.youtube.com/watch?v=lFiTHc507N4
#define MAXN 1000000  // non paramitarized macro
#define print(x) cout<<#x<<" : " <<x<<endl; // non paramitarized macro
using namespace std;

void firstIO(){
    //for fase input
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[MAXN];
int N;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }for(int i=0;i<N;i++){
        print(arr[i]);
    }cout<<endl;
}
