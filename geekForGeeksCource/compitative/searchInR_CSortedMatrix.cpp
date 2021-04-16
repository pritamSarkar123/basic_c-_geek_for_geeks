#include<bits/stdc++.h>
using namespace std;
//https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
//time O(m+n) space O(1)
bool search_in_vector(const vector<vector<int>> &arr,int x){
    int r=0,c=arr[0].size()-1;
    while(r<arr.size() && c>=0){
        if(arr[r][c]==x) return true;
        else if(arr[r][c]>x) c--; // remaining below elements in col greater than x, discard col
        else r++; // remaining left elements in row smaller than x, discard the row
    }
    return false;
}
int main(){
    vector<vector<int>> arr{{3,30,38},{36,43,60},{40,51,69}};
    int a[]={2,43,42,41,63,64,65,69,70,51};
    for(int x:a)
        cout<<search_in_vector(arr,x)<<"<-"<<x<<endl;
    return 0;
}
