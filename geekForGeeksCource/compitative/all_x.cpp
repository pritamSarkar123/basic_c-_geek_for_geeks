#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
void foo(){
    vector<int> v{5,4,2,2,3,1};
    cout<<" before sorting "<<endl;
    for(auto x: v){
        cout<<x<<endl;
    }cout<<endl;
    sort(all(v));
    cout<<" after sorting "<<endl;
    for(auto x: v){
        cout<<x<<endl;
    }cout<<endl;
    set<int> s(all(v));
    cout<<"after becoming set "<<endl;
    for(auto x : s){
        cout<<x<<endl;
    }
}



int main(){
    foo();
    return 0;
}
