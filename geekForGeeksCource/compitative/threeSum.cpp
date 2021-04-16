#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=BCLfxQja9dI
bool threeSum(int arr[],int len,int target){
    sort(arr,arr+len);
    for(int i=0;i<len;i++){
        int p=0;
        int q=len-1;
        while(p<q){
            if(p==i) p++;
            else if(q==i) q--;
            else{
                int current=arr[i]+arr[p]+arr[q];
                if(current == target){
                    cout<<arr[i]<<" "<<arr[p]<<" "<<arr[q]<<endl;
                    return true;
                }
                if(current>target) q--;
                else if(current<target) p++;
            }
        }
    }
    return false;
}
int main(){
    int arr[]={12, 3, 4, 1, 6, 9};
    int target=24;
    cout<<threeSum(arr,(sizeof(arr)/sizeof(arr[0])),target);
    return 0;
}
