#include<bits/stdc++.h>
using namespace std;

void foo1(){
    /*
        map <- implemented using self balancing binary search tree O(log n)
        unordered_mao <- implemented using hash map // operations O(1)
    */
    map<int,int> mp;
    unordered_map<int,int> ump1;

    for(int i=0;i<10;i++){
        mp.insert(make_pair(i,i*2 + i*3));
    }
    for(auto x: mp){
        ump1.insert(make_pair(x.first,x.second));
    }

    unordered_map<int,int> ump2(mp.begin(),mp.end());

    cout<<"map elements printing"<<endl;
    for(auto x : mp){
        cout<<"( "<<x.first <<" "<< x.second<<" ) ";
    }cout<<endl;

    cout<<"unordered map elements printing 1"<<endl;
    for(auto x : ump1){
        cout<<"( "<<x.first <<" "<< x.second<<" ) ";
    }cout<<endl;

    cout<<"unordered map elements printing 2"<<endl;
    for(auto x : ump2){
        cout<<"( "<<x.first <<" "<< x.second<<" ) ";
    }cout<<endl;
}
void foo2(){
    map<int,int> mp;
    multimap<int,int> mmp;
    for(int i=0;i<10;i++){
        mp.insert(make_pair(i,i*2));
        mp.insert(make_pair(i,i*3));
        mmp.insert(make_pair(i,i*2));
        mmp.insert(make_pair(i,i*3));
    }
    cout<<" count of key 2 in map "<<mp.count(2)<<endl;
    cout<<" count of key 2 in multi map "<<mmp.count(2)<<endl;
}
int main(){
    foo1();
    foo2();
    return 0;
}
