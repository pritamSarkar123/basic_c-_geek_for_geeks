#include <bits/stdc++.h>
using namespace std;
class Point{
	private:
	int x; //readonly
	int y; //readonly
	public:
	Point(int x, int y){
		// tie(x,y)=make_tuple(a,b);
		this->x=x;
		this->y=y;
	}
	int getX()const{
		return x;
	}
	int getY()const{
		return y;
	}
};

class MyComparator{
	public:
	bool operator() (const Point &one,const Point &two){
		//ascending order on X
		return one.getX()>two.getX();
	}
};
class MyComparatorForPair{
	public:
	bool operator() (pair<int,int> &one,pair<int,int> &two){
		return one.first>two.first;
	}
};

void heapPQcustonClass(){
	priority_queue<Point,vector<Point>,MyComparator> pq;
	pq.push(Point(1,2));
	pq.push(Point(5,2));
	pq.push(Point(2,3));
	pq.push(Point(2,5));
	while(!pq.empty()){
		cout <<pq.top().getX() <<" "<<pq.top().getY()<<endl;
		pq.pop();
	}
}
void heapPQpair(){
	priority_queue<pair<int, int>,vector<pair<int, int>>,MyComparatorForPair> pq;
	pq.push(make_pair(1,2));
	pq.push(make_pair(5,2));
	pq.push(make_pair(2,3));
	pq.push(make_pair(2,5));
	while(!pq.empty()){
		cout <<pq.top().first <<" "<<pq.top().second <<endl;
		pq.pop();
	}
}
void minHeapBasic(){
	priority_queue<int,vector<int>,greater<int>> pq; //mih heap
	pq.push(1);pq.push(5);pq.push(2);pq.push(4);pq.push(3);
	while(!pq.empty()){
		cout <<pq.top()<<" ";
		pq.pop();
	}cout<<endl;
}
void maxHeapBasic(){
	//by default max heap
	priority_queue<int> pq;
	pq.push(1);pq.push(5);pq.push(2);pq.push(4);pq.push(3);
	while(!pq.empty()){
		cout <<pq.top()<<" ";
		pq.pop();
	}cout<<endl;
}
int main(){
	heapPQcustonClass();
	// heapPQpair();
	// minHeapBasic();
	// maxHeapBasic();
	return 0;
}