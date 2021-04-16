#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mat_mul(const vector<vector<int>> &a,const vector<vector<int>> &b){
    vector<vector<int>> ans;
    int r1,c1,r2,c2;
    r1=a.size();r2=b.size();c1=a[0].size();c2=b[0].size();
    if(c1==r2){
        for(int i=0;i<r1;i++){
            vector<int> temp;
            for(int j=0;j<c2;j++){
                int result=0;
                for(int k=0;k<c1;k++){// the common one
                    result+=(a[i][k]*b[k][j]);
                }
                temp.push_back(result);
            }
            ans.push_back(temp);
        }
    }else{
        return ans; //blank
    }
}


int main(){
    vector<vector<int>> a{{1,2},{2,3}};
    vector<vector<int>> b{{1,1},{1,1}};
    vector<vector<int>> v=mat_mul(a,b);
    if(v.size()){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                cout<<v[i][j]<<" ";
            }cout<<endl;
        }
    }else{
        cout<<"Multiplication Not possible"<<endl;
    }
    return 0;
}
