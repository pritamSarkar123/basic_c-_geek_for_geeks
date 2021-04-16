#include<bits/stdc++.h>
using namespace std;
class ListNode{
	public:
		int val;
		ListNode* next;
		ListNode(int v,ListNode* n=NULL){
			val=v;
			next=n;
		}
};
class List{
public:
	ListNode* head;
	int length;
	List(){
		head=NULL;
		length=0;
	}
	void add(int n){
		if(!head){
			head=new ListNode(n);
		}else{
			ListNode* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=new ListNode(n);
		}
		length++;
	}
	~List(){
		// cout<<"inside destructor"<<endl;
		// while(length>0){
		// 	if(length==1){
		// 		cout<<"deleting "<<head->val<<endl;
		// 		delete head;
		// 		head=NULL;
		// 	}else{
		// 		ListNode* temp=head;
		// 		while(temp->next->next!=NULL){
		// 			temp=temp->next;
		// 		}
		// 		ListNode* t=temp->next;
		// 		cout<<"deleting "<<t->val<<endl;
		// 		delete t;
		// 		temp->next=NULL;
		// 	}
		// 	length--;
		// }
		while(head!=NULL){
			ListNode* temp=head;
			cout<<"deleting "<<temp->val<<endl;
			head=head->next;
			delete temp;
		}
	}	
};
ListNode* find_middle(List &l){
	ListNode* slow=l.head;
	ListNode* fast=l.head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

void get_mid(const forward_list<int> &f){
	forward_list<int>::const_iterator slow=f.begin();
	forward_list<int>::const_iterator fast=f.begin();
	while(fast!=f.end() && next(fast)!=f.end()){
		advance(slow,1);
		advance(fast,2);
	}
	cout<<*slow<<endl;
}

int main(){
	int arr[]={1,2,3};
	List l;
	for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
		l.add(arr[i]);
	}
	cout<<find_middle(l)->val<<endl;

	//OR
	forward_list<int> f{1,2,3};
	get_mid(f);
	return 0;
}