#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=4ggF3tXIAp0
vector<vector<int>> fourSumOptimal(vector<int> arr,int target){
    vector<vector<int>> ans;
    if(!arr.size()) return ans;
    sort(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int new_target=target-arr[i]-arr[j];
            int p=j+1,q=n-1;
            while(p<q){
                int two_sum=arr[p]+arr[q];
                if(two_sum>new_target) q--;
                else if(two_sum<new_target) p++;
                else{
                    vector<int> quadruplet(4,0);
                    quadruplet[0]=arr[i];
                    quadruplet[1]=arr[j];
                    quadruplet[2]=arr[p];
                    quadruplet[3]=arr[q];
                    ans.push_back(quadruplet);
                    while(p<q && arr[p]==quadruplet[2]) p++;
                    while(p<q && arr[q]==quadruplet[3]) q--;
                }

            }
            while(j+1<n && arr[j+1]==arr[j]) ++j;
        }
        while(i+1<n && arr[i+1]==arr[i]) ++i;
    }
    return ans;
}
int main(){
    vector<int> arr{1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>> ans=fourSumOptimal(arr,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<"\n";
    }
    return 0;
}
