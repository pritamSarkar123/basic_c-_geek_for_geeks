#include<bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=Q7v239y-Tik
/*
    basic rules:
        buy when the point is local minima (left and right both higher)
        sell when the point is local maxima (left and right both lower)
                            OR
    make the profit increased when current point is greater than previous point
*/
void multiple_buy_sell_stock(int arr[],int l){
    int profit=0;
    for(int i=1;i<l;i++){
        if(arr[i]>arr[i-1]) profit+=(arr[i]-arr[i-1]);
    }
    cout<<"max profit : Rs."<<profit<<endl;
}


int main(){
    int arr[]={3,1,4,8,7,2,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    multiple_buy_sell_stock(arr,len);
    return 0;
}
