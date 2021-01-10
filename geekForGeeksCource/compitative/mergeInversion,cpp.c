#include<bits\stdc++.h>
using namespace std;


int merge(vector<int> &arr,int low,int mid,int high,vector<int> &temp){
    int i,j,m,n,k;
    tie(i,k,j,m,n)=make_tuple(low,low,mid+1,mid,high);
    invert_count=0;

    while( i<=m && j<=n){
        if(arr[i] <= arr[j]){
            temp[k++]=arr[i++];
        }else{
            invert_count+=(mid - i + 1); // inversion counting condition
            temp[k++]=arr[j++];
        }
    }while( i < = m){
        temp[k++]=arr[i++];
    }while( j <= n){
        temp[k++]=arr[j++];
    }
    for(i = low;i<=high ;i++) arr[i]=temp[i];
    return invert_count;
}

int mergeSort(vector<int> &arr,int low,int high,vector<int> &temp){
    int invert_count=0;
    if(high > low){
        int mid=(low + high)/2;
        invert_count+=mergeSort(arr,low,mid,temp);
        invert_count+=mergeSort(arr,mid+1,high,temp);
        invert_count+=merge(arr,low,mid,high,temp);
    }
    return invert_count;
}

int main(){
    vector<int> arr{10,9,8,7,6,5,4,3,2,2,1};
    vector<int> temp(arr.size(),0);
    int invert_count=mergeSort(arr,0,arr.size()-1,temp);
    cout<< invert_count <<endl;
}
