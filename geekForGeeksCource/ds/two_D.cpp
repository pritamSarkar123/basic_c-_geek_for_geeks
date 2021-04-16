#include<bits/stdc++.h>
using namespace std;

void two_d_(){
    //---------------------------------------------

    vector<list<int>> array_of_list;
    list<int> a{1,2,3,4};
    array_of_list.push_back(a);
    for(int i=0;i<array_of_list.size();i++){
        for(auto x:array_of_list[i]){
            cout<<x<<" ";
        }cout<<"\n";
    }
    //-----------------------------------------------

    vector<vector<int>> array_of_array;

    //------------------------------------------------
    list<list<int>> list_of_list;
    list<int> b{5,6,7,8};
    list_of_list.push_back(b);
    for(auto &x:list_of_list){
        for(auto &y:x){
            cout<<y<<" ";
        }cout<<"\n";
    }
    //------------------------------------------------
    list<vector<int>> list_of_array;
}


int main(){
    two_d_();
    return 0;
}
