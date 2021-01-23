#include<iostream>
#include<vector>
#include<algorithm>
#define all(x) x.begin(),x.end()

#define first_IO() {                            \
                    ios_base::sync_with_stdio(NULL); \
                    cin.tie(false); \
                    cout.tie(false); \
                    }

// \ <- is the line continuation character
using namespace std;

void elementCount(){
    vector<int> v{1,2,2,3,4,5,6,2};  // v.begin() -> 1's position v.end() -> after 7's position
    cout <<count(all(v),2)<<endl;
    cout<<count(v.begin(),v.begin()+4,2)<<endl; //(include,exclude,element)  [in,ex)
    string abc="ABCDEFGA";
    cout<<count(all(abc),'A')<<endl;
}

void rotateElements(){
    vector<int> v{1,2,2,3,4,5,6,2};
    cout<<"before rotate "<<endl;
    for(auto &x: v){
        cout<<x<<" ";
    }cout<<endl;
    reverse(all(v)); // [in,ex)
    cout<<"after rotate "<<endl;
    for(auto &x: v){
        cout<<x<<" ";
    }cout<<endl;
    vector<int> v1{1,2,2,3,4,5,6,2};
    cout<<"before rotate "<<endl;
    for(auto &x: v1){
        cout<<x<<" ";
    }cout<<endl;
    reverse(v1.begin()+2,v1.begin()+4); //elements [2,,,,3] -> [2,,,4)
    cout<<"after rotate "<<endl;
    for(auto &x: v1){
        cout<<x<<" ";
    }cout<<endl;

}

int main(){
    elementCount();
    rotateElements();
    return 0;
}

