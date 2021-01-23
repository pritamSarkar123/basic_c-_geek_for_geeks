#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Heap{
public:
    vector<T> heap_arr;
    void heapify(const vector<T> &v);
    void insertElement(T element);
    T deleteElement();
    vector<T> heapSort();
};

template<typename T>
void Heap<T>::heapify(const vector<T> &v){
    if(heap_arr.size()==0) heap_arr.push_back(v[0]);
    for(auto x : v) heap_arr.push_back(x);
    int s=heap_arr.size();
    int i = s-1;
    while(i>0){
        int k=i;
        int j=k*2;
        while(j<s){
            if(j+1 <s && heap_arr[j+1] > heap_arr[j]) j=j+1;
            if(heap_arr[j] > heap_arr[k]){
                heap_arr[k]=heap_arr[k]^heap_arr[j];
                heap_arr[j]=heap_arr[k]^heap_arr[j];
                heap_arr[k]=heap_arr[k]^heap_arr[j];
            }
            else break;
            k=j;j=j*2;
        }
        i--;
    }

}
template<typename T>
void Heap<T>::insertElement(T element){
    if(heap_arr.size()==0) heap_arr.push_back(element);
    heap_arr.push_back(element);
    int i = heap_arr.size() - 1;
    T temp=element;
    while(i > 1 && temp > heap_arr[i/2]){
        heap_arr[i]=heap_arr[i/2];
        i=i/2;
    }
    heap_arr[i]=temp;
}
template<typename T>
T Heap<T>::deleteElement(){
    T temp = heap_arr[1];
    int s=heap_arr.size();
    heap_arr[1] = heap_arr[s - 1];
    int i=1,j=i*2;
    while(j < s-1){
        if(j+1 < s-1 && heap_arr[j+1] > heap_arr[j]) j= j+1;
        if(heap_arr[j] > heap_arr[i]){
            heap_arr[i]=heap_arr[i]^heap_arr[j];
            heap_arr[j]=heap_arr[i]^heap_arr[j];
            heap_arr[i]=heap_arr[i]^heap_arr[j];
        }
        else break;
        i=j;j=j*2;
    }
    heap_arr.pop_back();
    return temp;
}
template<typename T>
vector<T> Heap<T>::heapSort(){
    vector<T> v(heap_arr.size());
    int i = heap_arr.size()-1;
    T element;
    while(i>0){
        element=deleteElement();
        v[i]=element;
        i--;
    }
    for(int i=0;i<v.size();i++){
        insertElement(v[i]);
    }
    return v;
}


int main(){
    Heap<int> h;
    vector<int> v{15,125,4,1,2,4,8,12};
    h.heapify(v);
    h.insertElement(350);
    h.insertElement(69);
    for(int i=1;i<h.heap_arr.size();i++){
        cout<<h.heap_arr[i]<<" ";
    }cout<<endl;
    h.deleteElement();
    for(int i=1;i<h.heap_arr.size();i++){
        cout<<h.heap_arr[i]<<" ";
    }cout<<endl;
    vector<int> v1=h.heapSort();
    for(int i=1;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }cout<<endl;
    return 0;
}
