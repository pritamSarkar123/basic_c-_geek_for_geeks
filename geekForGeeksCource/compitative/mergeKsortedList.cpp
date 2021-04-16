#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	ListNode *cur;
	int idx;
	Node(ListNode *a,int b){
		cur = a;idx=b;
	}
};
struct Comp{
	bool operator()(const Node &a,const Node &b){
		return a.cur->val > b.cur->val;
	}
};

ListNode * mergeLists(vector<ListNode *> &lists){
	int k=lists.size();
	if(k==0) return NULL;
	ListNode * head,*tail;
	head=tail=NULL;
	priority_queue<Node,vector<Node>,Comp> pq;
	vector<ListNode *> ptr(k); //optional otherwise we can directly use Lists
	//initialy insert all the 1st nodes of each of the lists
	for(int i=0;i<k;i++){
		ptr[i]=lists[i];
		if(ptr[i]) pq.push(Node(ptr[i],i));
	}
	if(pq.empty()) return NULL;
	head=tail=pq.top().cur; // 1st poping out
	int idx=pq.top().idx;
	pq.pop();
	ptr[idx]=ptr[idx]->next;
	if(ptr[idx]) pq.push(Node(ptr[idx],idx));
	while(!pq.empty()){
		ListNode * temp=pq.top().cur;
		idx=pq.top().idx;
		pq.pop();

		tail->next=temp; tail=tail->next;
		ptr[idx]=ptr[idx]->next;
		if(ptr[idx]) pq.push(Node(ptr[idx],idx));
	}
	return head;
}
int main(){
	// TODO code remaining -_-
	return 0;
}
