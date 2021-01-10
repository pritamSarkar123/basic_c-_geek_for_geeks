#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> v{1,2,3,4,5};
    auto update=[&v](int x)->void {for(auto &i:v){i+=x;}};
    update(5);
    for(auto x:v) cout<<x<<" "; cout<<endl;
    auto sum=[&v](int x) -> int {int sum=0;for(auto i: v){ sum+=i;} sum*=x;return sum;};
    cout<<sum(3)<<endl;
}
