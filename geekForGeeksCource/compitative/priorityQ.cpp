#include<bits/stdc++.h>
using namespace std;

class Point{
public:
	int x,y;
	Point(int a,int b){
		tie(x,y)=make_tuple(a,b);
	}
	int getx() const {return x;}
	int gety() const {return y;}
};

class MyComparator{
public:
	int operator() (const Point &p1,const Point &p2){
		return p1.getx() < p2.getx();
	}
};

void printQueue(priority_queue<Point,vector<Point>,MyComparator> pq){
	while(!pq.empty()){
		cout<<pq.top().getx()<<" "<<pq.top().gety()<<endl;
		pq.pop();
	}
}

int main(){
	priority_queue<Point,vector<Point>,MyComparator> pq;
	pq.push(Point(1,2));
	pq.push(Point(3,4));
	pq.push(Point(2,7));
	pq.push(Point(1,9));
	pq.push(Point(3,8));
	printQueue(pq);
	return 0;
}