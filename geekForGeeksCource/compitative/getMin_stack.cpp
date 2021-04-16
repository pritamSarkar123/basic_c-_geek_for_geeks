#include<bits/stdc++.h>
using namespace std;
//https://www.youtube.com/watch?v=QMlDCR9xyd8&t=6s
//https://www.youtube.com/watch?v=gd9xEAnxXzc
class S1{ // get min O(1) time O(1) space
public:
    stack<int> s;
    int min_val=0;
    void push(int x){
        if(s.empty()){
            s.push(x);
            min_val=x;
        }
        else if(x>=min_val) s.push(x);
        else{ //if(x < min_val)
            min_val=x;
            s.push(2*x - min_val);
        }
    }
    int top(){
        if(s.empty()) return -1;
        int v= s.top();
        return v < min_val ? (v+min_val)/2 : v;
    }
    void pop(){
        if(s.empty()) return;
        int v=s.top();
        s.pop();
        if(v < min_val){
            min_val=2*min_val - v;
        }
    }
    int get_min(){
        if(s.empty()) return -1;
        return min_val;
    }
};
//implementing it in o(n) space
class S2{
public:
    stack<int> s;
    stack<int> m;
    void push(int x){
        if(s.empty()){
            s.push(x);
            m.push(x);
        }else if(x <= m.top()){
            s.push(x);
            m.push(x);
        }else{
            s.push(x);
            m.push(m.top());
        }
    }
    int get_min(){
        if(s.empty()) return -1;
        return m.top();
    }
    int top(){
        if(s.empty()) return -1;
        return s.top();
    }
    void pop(){
        if(s.empty()) return;
        s.pop();m.pop();
    }
};

int main(){
    vector<int> a{8,10,6,1,3,7};
    S1 s;
    S2 p;
    for(int i=0;i<a.size();i++){
        s.push(a[i]);
        cout<<a[i]<<" pushed min = "<<s.get_min()<<" top= "<<s.top()<<endl;
    }
    s.pop();
    cout<<"min = "<<s.get_min()<<" top= "<<s.top()<<endl;
    cout<<"---------------------------"<<endl;
    for(int i=0;i<a.size();i++){
        p.push(a[i]);
        cout<<a[i]<<" pushed min = "<<p.get_min()<<" top= "<<p.top()<<endl;
    }
    p.pop();
    cout<<"min = "<<p.get_min()<<" top= "<<p.top()<<endl;
    return 0;
}
