#include<bits/stdc++.h>
using namespace std;

void rain_water_catch_one(int arr[],int len){
        /*
            takes O(n) in time and space both
            and complex too
        */
    int forward_pass[len],backward_pass[len];
    fill(forward_pass,forward_pass+len,0);
    fill(backward_pass,backward_pass+len,0);
    // forward pass
    int leader=arr[0];
    for(int i=0;i<len-1;i++){
        if(arr[i]<leader){
            forward_pass[i]=leader-arr[i];
            if(arr[i]>arr[i+1]) leader=arr[i]; //from next point decreasing
        }else{
            leader=arr[i];
        }
    }
    // backward pass
    leader=arr[len-1];
    for(int i=len-2;i>=0;i--){
        if(arr[i]<leader){
            backward_pass[i]=leader-arr[i];
            if(arr[i]<arr[i-1]) leader=arr[i-1]; //from next point increasing
        }else{
            leader=arr[i];
        }
    }
    int ans=0;
    for(int i=0;i<len;i++){
        ans+=min(forward_pass[i],backward_pass[i]);
    }
    cout<<ans<<endl;
}
void rain_water_catch_two(int arr[],int len){
    /*
        time and space both O(n)
        but easier one
        anuj bhai: https://www.youtube.com/watch?v=UZG3-vZlFM4
    */
    int left_higher_building[len],right_higher_building[len];
    fill(left_higher_building,left_higher_building+len,0);
    fill(right_higher_building,right_higher_building+len,0);
    left_higher_building[0]=arr[0];
    for(int i=1;i<len;i++){
        left_higher_building[i]=max(left_higher_building[i-1],arr[i]);
    }
    right_higher_building[len-1]=arr[len-1];
    for(int i=len-2;i>=0;i--){
        right_higher_building[i]=max(right_higher_building[i+1],arr[i]);
    }
    int ans=0;
    for(int i=0;i<len;i++){
        ans+=(min(left_higher_building[i],right_higher_building[i])-arr[i]);
    }
    cout<<ans<<endl;
}

void rain_water_catch_three(int arr[],int len){
    /*
        time O(n) but space O(1)
    */
    int left_high_building=arr[0],right_high_building=arr[len-1];
    int max_el=*max_element(arr,arr+len)+1; //max_element returns a pointer
    for(int i=0;i<len;i++){
        left_high_building=max(arr[i],left_high_building);
        arr[i]+=(max_el*left_high_building);
    }
    for(int i=len-1;i>=0;i--){
        right_high_building=max(arr[i]%max_el,right_high_building);
        arr[i]=min(right_high_building,arr[i]/max_el)-arr[i]%max_el;
    }
    int ans=0;
    for(int i=0;i<len;i++){
        ans+=arr[i];
    }
    cout<<ans<<endl;
}

int main(){
    int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    rain_water_catch_one(arr,len); //wrong
    rain_water_catch_two(arr,len);
    rain_water_catch_three(arr,len);
    return 0;
}
