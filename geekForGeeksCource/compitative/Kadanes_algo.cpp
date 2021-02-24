#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=HCL4_bOd3-4
int maxSum(const vector<int> &v){
    bool all_neg=true;
    for(int i=0;i<v.size();i++){
        if(v[i]>0){
            all_neg=false;
            break;
        }
    }
    if(all_neg){
        int m=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(v[i]>m){
                m=v[i];
            }
        }
        return m;
    }
  int max_sum=0;
  int currentSum=0;
  int s=0,e=v.size()-1;
  for(int i=0;i<v.size();i++){
    currentSum+=v[i];
    if(currentSum>max_sum){
      max_sum=currentSum;
      e=i;
    }
    if(currentSum<0){
      currentSum=0;
      s=i+1;
    }
  }
  for(int i=s;i<=e;i++){
    cout<<v[i]<<" ";
  }cout<<endl;
  return max_sum;
}

int main(){
    //5,-4,3,-3,6,1,-1
  vector<int> v{-5,-4,-3,-3,-6,-1,-1};
  int m=maxSum(v);
  cout<<m<<endl;
  return 0;
}
