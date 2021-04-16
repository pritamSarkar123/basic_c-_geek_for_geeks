#include<bits/stdc++.h>
#define MIN INT_MIN
#define MAX INT_MAX
using namespace std;
//https://www.youtube.com/watch?v=34WE6kwq49U

// worst soltion will be 2 for loop O(n^2), dont need to implement that
void stock_moderate(int arr[],int len){
    //O(n) time and O(n) space
    int next_max[len];
    fill(next_max,next_max+len,0);
    next_max[len-1]=arr[len-1];
    int i=len-2;
    while(i>=0){
        next_max[i]=max(next_max[i+1],arr[i]);
        i--;
    }
    int min_untill=MAX;
    int max_profit=MIN;
    int max_untill=MIN;
    for(i=0;i<len;i++){
        if(next_max[i]-arr[i]>max_profit){
            max_profit=next_max[i]-arr[i];
            min_untill=arr[i];
            max_untill=next_max[i];
        }
    }
    cout<<"buy the stock at Rs."<<min_untill<<" sell it at Rs."<<max_untill<<" to get max profit of Rs."<<max_profit<<endl;
}

void stock_optimized(int arr[],int len){
    //O(n) time and O(1) space
    int min_untill=MAX;
    int max_profit=MIN;
    int max_untill=MIN;
    for(int i=0;i<len;i++){
        if(arr[i]<min_untill) min_untill=arr[i];
        if(max_profit<arr[i]-min_untill){
            max_profit=arr[i]-min_untill;
            max_untill=arr[i];
        }
    }
    cout<<"buy the stock at Rs."<<min_untill<<" sell it at Rs."<<max_untill<<" to get max profit of Rs."<<max_profit<<endl;
}





int main(){
    int arr[]={3,1,4,8,7,2,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    stock_optimized(arr,len);
    stock_moderate(arr,len);
    return 0;
}
