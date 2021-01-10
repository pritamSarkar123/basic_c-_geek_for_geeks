#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

bool myComparator(const Point &p1,const Point &p2){
    if(p1.x==p2.x){
        return (p1.y<p2.y);
    }else{
        return (p1.x<p2.x);
    }
}

void sortPoints(){
    vector<Point> v{{1,2},{3,4},{5,6},{1,9}};
    sort(v.begin(),v.end(),myComparator);
    for(const auto &point:v){
        cout<<"x = "<<point.x<<" y = "<<point.y<<endl;
    }cout<<endl;
}


int main(){
    sortPoints();
    return 0;
}
