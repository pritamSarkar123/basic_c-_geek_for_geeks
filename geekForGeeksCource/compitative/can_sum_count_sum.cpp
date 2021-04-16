#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=F7wqWbqYn9g
bool can_sum(vector<int> &arr,int &target){
    vector<vector<bool>> table;
    for(int i=0;i<=arr.size();i++){
        table.push_back(vector<bool>(target+1,false));
    }
    for(int i=0;i<arr.size();i++) table[i][0]=true; // if target=0 any blank set can meet target
    for(int j=1;j<=target;j++) table[0][j]=false; // blank set can not meet to target except target=0
    for(int i=1;i<table.size();i++){
        for(int j=1;j<table[0].size();j++){
            if(arr[i-1] > j){
                table[i][j]=table[i-1][j];
            }else{ //not adding the element or adding the element
                table[i][j]=table[i-1][j] || table[i-1][j-arr[i-1]];
            }
        }
    }
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].size();j++){
            cout<<table[i][j]<<" ";
        }cout<<endl;
    }
    return table[arr.size()][target];
}
int count_sum(vector<int> &arr,int &target){
    vector<vector<int>> table;
    for(int i=0;i<=arr.size();i++){
        table.push_back(vector<int>(target+1,0));
    }
    for(int i=0;i<arr.size();i++) table[i][0]=1; // if target=0 any blank set can meet target
    for(int j=1;j<=target;j++) table[0][j]=0; // blank set can not meet to target except target=0
    for(int i=1;i<table.size();i++){
        for(int j=1;j<table[0].size();j++){
            if(arr[i-1] > j){
                table[i][j]=table[i-1][j];
            }else{//not adding the element + adding the element
                table[i][j]=table[i-1][j] + table[i-1][j-arr[i-1]];
            }
        }
    }
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table[i].size();j++){
            cout<<table[i][j]<<" ";
        }cout<<endl;
    }
    return table[arr.size()][target];
}
int main(){
    vector<int> arr{2,3,5,8,10};
    int target=10;
    cout<<can_sum(arr,target)<<"\n";
    cout<<count_sum(arr,target)<<"\n";
    return 0;
}
