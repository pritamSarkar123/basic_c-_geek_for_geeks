#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
void multiply(long long F1[2][2],long long F2[2][2]);
void power(long long F[2][2],long long n);
int fib(long long n);

int main(){
    long long n;
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
int fib(long long n){
    if(n==0) return 0;
    long long F[2][2]={{1,1},{1,0}};
    power(F,n-1);
    return (int)(F[0][0]%MOD);
}
void power(long long F[2][2],long long n){
    if(n==1 || n==0) return;
    long long M[2][2]={{1,1},{1,0}};
    power(F,n/2);
    multiply(F,F);
    if(n&1) multiply(F,M);
}
void multiply(long long F1[2][2],long long F2[2][2]){
    long long w=((F1[0][0]*F2[0][0])%MOD+(F1[0][1]*F2[1][0])%MOD)%MOD;
    long long x=((F1[0][0]*F2[0][1])%MOD+(F1[0][1]*F2[1][1])%MOD)%MOD;
    long long y=((F1[1][0]*F2[0][0])%MOD+(F1[1][1]*F2[1][0])%MOD)%MOD;
    long long z=((F1[1][0]*F2[0][1])%MOD+(F1[1][1]*F2[1][1])%MOD)%MOD;
    tie(F1[0][0],F1[0][1],F1[1][0],F1[1][1])=make_tuple(w,x,y,z);
}
