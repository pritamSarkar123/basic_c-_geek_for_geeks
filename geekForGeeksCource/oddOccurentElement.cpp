#include<bits/stdc++.h>
using namespace std;
//Problem description:-https://www.youtube.com/watch?v=lanI1HAE19A&feature=emb_logo
//problem description:- https://www.youtube.com/watch?v=ZPYNb5-Xkr0&feature=emb_logo
void brutForce(){
    //lots of space required
    //time O(n)
    vector<int> v {10,20,10,30,10,30,20};
    unordered_map<int,int> mp;
    for(int x : v){
        if(mp.find(x)==mp.end()){
            //not present
            mp.insert(make_pair(x,1));
        }else{
            mp[x]--;
        }
    }
    for(auto x:mp){
        if(x.second!=0){
            cout<<x.first<<" repeats odd no of times"<<endl;
            return;
        }
    }
    cout<<"all repeats even no of times"<<endl;
}
void optimized(){
    vector<int> v {10,20,10,30,10,30,20};
    //exor with same no gives us zero
    int ans=0;
    for(int x : v){
        ans^=x;
    }
    cout<<ans<<" repeats odd no of times"<<endl;
}
void bitcount(){
    //this is not the method of c++ standard library
    //or not c++ standard function
    // its the function of gcc compiler itself
    //__builtin_popcount()   <- for integer
    //__builtin_popcountl()   <- for long
    //__builtin_popcountll()  <- for long long
    int a=4;
    cout<<__builtin_popcount(a)<<endl;
}
int main(){
    brutForce();
    optimized();
    bitcount();
    return 0;
}
