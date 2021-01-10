#include<bits/stdc++.h>
using namespace std;

void foo(const vector<int> &v){
    // const <- ensures values of vectors will not be changed
    // & <- no copies of vector the actual one
    for(auto &x : v){
        cout<<x<<" "<<endl;
    }
}
void foo1(int *arr,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<*((arr+i*n)+j)<<" ";
        }cout<<endl;
    }cout<<endl;
}
const int N =3;
void foo2(int arr[][N],int m){
    for(int i=0;i<m;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}

void foo3(const vector<vector<int>> &a){
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;
}
void deletingElementDuringTraversal(vector<int> &v){
    vector<int>::iterator it=v.begin();
    while(v.size()){
        it=v.erase(it); // erases the current element and returns the next element pointer
    }
    cout<<"Vector erased"<<endl;
}

void vectorToUnorderedSet(vector<int> &v){
    unordered_set<int> s(v.begin(),v.end());
    cout<<"Unordered set created"<<endl;
}


int main(){
    vector<int> v{1,2,3,4,5};
    foo(v);

    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    foo1(&arr[0][0],3,3);
    foo2(arr,3);

    vector<vector<int>> a{{1,2,3},{4,5,6},{7,8,9}};
    foo3(a);

    vector<int> v1{1,2,3,4,5};
    deletingElementDuringTraversal(v1);


    vector<int> v2{1,2,3,4,5};
    vectorToUnorderedSet(v2);

    //v.emplace_back("---") is better than v.push_back("---")
    /*
        as in push_back() 1st one intermediate string is created then it is moved into the vector
        using move, then the intermediate string is destroyed

        on the other hand in emplece_back() directly the string is created in the end of the vector
        so it is better
        see:-https://www.youtube.com/watch?time_continue=85&v=uWXoMo9WuiY&feature=emb_logo
    */

    return 0;
}
