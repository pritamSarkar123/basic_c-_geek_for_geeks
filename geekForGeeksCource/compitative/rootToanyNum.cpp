#include<bits/stdc++.h>
using namespace std;
int rootBy(int a,int b){
    int l=1;
    int h=a/3;
    while(l<=h){
        int m=(l+h)/2;
        int ms=1,ms_1=1;
        for(int i=0;i<b;i++,ms*=m) ms_1*=(m+1);
        if(ms==a) return m;
        else if(ms<a){
            if(ms_1>a) return m;
            else l=m+1;
        }
        else h=m-1;
    }
}

int main(){
    cout<<rootBy(17,3)<<endl;
    cout<<rootBy(171,3)<<endl;
    cout<<rootBy(125,3)<<endl;
    cout<<rootBy(17,5)<<endl;
    cout<<rootBy(171,5)<<endl;
    cout<<rootBy(125,5)<<endl;
    return 0;
}
