#include<bits/stdc++.h>
using namespace std;

void besicVsClassesLowerBound(){
    /*
        bi-directional iterators of set, map....
        random access iterators of vector,unordered_set,unordered_map....

        1> lower_bound(obj.begin(),obj.end(),value)
            for random access iterator it does it in O(log n) time
            otherwise it does it in O(n) time

        2> obj.lowe_bound(value)
            for bidirectional iterator it does it in O(log n) time

        so, for bidirectional iterator we use obj.lowe_bound(value)
        and for random access iterator we simply uses lower_bound(obj.begin(),obj.end(),value)
        for O(log n ) exe
    */

    vector<int> v{9,8,7,7,6,5,6,4,5,6,3,2,1}; //random access iterator
    sort(v.begin(),v.end());
    cout<< *lower_bound(v.begin(),v.end(),6)<<endl; // O(log n) as random access iterator

    set<int> s(v.begin(),v.end());
    cout<< *lower_bound(s.begin(),s.end(),6)<<endl; // O(n) as bi-directional iterator -_-

    //recommended for bidirectional iterator
    cout<< *s.lower_bound(6)<<endl; //O(log n)

}


void countDistinctElements(int arr[],int n){
    /*
        map,set <- avl tree(unique key) //O(log n)
        multimap,multiset<- avl tree(non unique key) //O(log n)


        unordered_map,unordered_set <- hash map(unique key) //O(1)
        unordered_multimap,unordered_multiset<- hash map(non unique key) //O(1)
    */


    set<int> s(arr,arr+n);
    cout<<s.size()<<endl;
    /*
        takes O(n log n ) times as set internaly uses self balancing bst O(log n)
        and for inserting n elements it takes atmost O(n log n) time
    */
    unordered_set<int> us(arr,arr+n);
    cout<<us.size()<<endl;
    /*
        takes O(n) times as unordered_set internally uses hashMap O(1)
        and for inserting n elements it takes atmost O(n) times
    */
}

int main(){
    besicVsClassesLowerBound();
    int arr[]={9,8,7,7,6,5,6,4,5,6,3,2,1};
    countDistinctElements(arr,13);
    return 0;
}
