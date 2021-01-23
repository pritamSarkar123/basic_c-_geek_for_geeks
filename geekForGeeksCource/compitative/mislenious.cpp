#include<bits/stdc++.h>
using namespace std;
void greater_function(){
    /*
        in sorting
        vector<int> v{......};
        sort(v.begin(),v.end()); <- default ascending order
        sort(v.begin(),v.end(),greater<int>()); <- descending order
    */
    vector<int> v{3,4,51,1,2,4,79,123,2,90};
    cout<<"Before sorting"<<endl;
    for(int x:v){
        cout<<x<<" ";
    }cout<<endl;
    sort(v.begin(),v.end());
    cout<<"After ascending sorting"<<endl;
    for(int x:v){
        cout<<x<<" ";
    }cout<<endl;
    sort(v.begin(),v.end(),greater<int> ()); // blank object of greater class
    cout<<"After descending sorting"<<endl;
    for(int x:v){
        cout<<x<<" ";
    }cout<<endl;
    /*
        in set and map
        set<int> s; <- ascending order
        set<int,greater<int>> s; <- descending order

        map<int,int> m;<- ascending order //order according to keys
        map<int,int,greater<int>> <-descending order  //order according to keys
    */
    map<int,int> m1;
    m1.insert(make_pair(1,2));
    m1.insert(make_pair(2,3));
    m1.insert(make_pair(3,4));
    cout<<"Ascending map"<<endl;
    map<int,int>::iterator iter;
    for(iter=m1.begin();iter!=m1.end();iter++){
        cout<<"( "<<iter->first<<" "<<iter->second<<" ) ";
    }
    map<int,int,greater<int>> m2;
    m2.insert(make_pair(1,2));
    m2.insert(make_pair(2,3));
    m2.insert(make_pair(3,4));
    cout<<"Descending map"<<endl;
    for(iter=m2.begin();iter!=m2.end();iter++){
        cout<<"( "<<iter->first<<" "<<iter->second<<" ) ";
    }cout<<endl;
    /*
        in priority_queue
        priority_queue<int> pq; <- ascending / min heap
        priority_queue<int,vector<int>,greater<int>> pq; <- descending / max heap
    */
}
void about_pair(){
    /*
        pair<int,int> p;  <- always initialized by default values of the type
        p = make_pair(1,2); Or p={1,2};
        then access using p.first p.second
    */
}
void about_deque(){
    /*
        random access allowed like vector, internal implementation different
    */
}
int main(){
    greater_function();
    return 0;
}
