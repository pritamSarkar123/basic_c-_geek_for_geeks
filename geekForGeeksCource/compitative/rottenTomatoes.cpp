#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=CxrnOTUlNJE&t=37s
struct node{
    int timeStamp;
    int x,y;
};
int doRotten(vector<vector<int>> &arr){
    queue<node> rotten;
    int count_fresh=0;
    // we will start from all the rotten tomatoes together
    // thats why we are using queue
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]==2){
                rotten.push(node());
                rotten.back().timeStamp=0;
                rotten.back().x=i;
                rotten.back().y=j;
            }
            if(arr[i][j]==1) count_fresh++;
        }
    }
    node n;
    while(!rotten.empty()){
        n=rotten.front();
        rotten.pop();
        //out<<"ts = "<<n.timeStamp<<" x= "<<n.x<<" y= "<<n.y<<"\n";
        if(n.x-1 >=0 && arr[n.x-1][n.y]==1){
            //push the node details in queue
            rotten.push(node());
            rotten.back().timeStamp=n.timeStamp+1;
            rotten.back().x=n.x-1;
            rotten.back().y=n.y;
            //make the node rotten
            arr[n.x-1][n.y]=2;
            //decrease the fresh count
            count_fresh--;
        }
        if(n.x+1 < arr.size() && arr[n.x+1][n.y]==1){
            //push the node details in queue
            rotten.push(node());
            rotten.back().timeStamp=n.timeStamp+1;
            rotten.back().x=n.x+1;
            rotten.back().y=n.y;
            //make the node rotten
            arr[n.x+1][n.y]=2;
            //decrease the fresh count
            count_fresh--;
        }
        if(n.y+1 < arr[0].size() && arr[n.x][n.y+1]==1){
            //push the node details in queue
            rotten.push(node());
            rotten.back().timeStamp=n.timeStamp+1;
            rotten.back().x=n.x;
            rotten.back().y=n.y+1;
            //make the node rotten
            arr[n.x][n.y+1]=2;
            //decrease the fresh count
            count_fresh--;
        }
        if(n.y-1 >=0 && arr[n.x][n.y-1]==1){
            //push the node details in queue
            rotten.push(node());
            rotten.back().timeStamp=n.timeStamp+1;
            rotten.back().x=n.x;
            rotten.back().y=n.y-1;
            //make the node rotten
            arr[n.x][n.y-1]=2;
            //decrease the fresh count
            count_fresh--;
        }
    }
    if(count_fresh) return -1;
    else return n.timeStamp;
}

int main(){
    vector<vector<int>> arr{{2,1,0,2,1},{1,0,1,2,1},{1,0,0,2,1}};
    cout<<doRotten(arr)<<"\n";
    return 0;
}
