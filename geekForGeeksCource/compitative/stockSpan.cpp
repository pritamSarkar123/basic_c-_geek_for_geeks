#include<bits/stdc++.h>
using namespace std;
//1st half//https://www.youtube.com/watch?v=-IFmgue8sF0
//second half//https://www.youtube.com/watch?v=XlD5VsOZsyA&t=68s
//O(2n)->O(n)
vector<int> stockSpan(const vector<int> &prices){
    vector<int> ans;
    stack<pair<int,int>> s; //{price,days}
    for(int price:prices){
        int days=1;
        while(!s.empty() && s.top().first<=price){
            days+=s.top().second;
            s.pop();
        }s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}
int main(){
    vector<int> prices{100,80,60,70,60,75,85};
    vector<int> ans=stockSpan(prices);
    for(int x:ans){
        cout<<x<<" ";
    }cout<<"\n";
}
