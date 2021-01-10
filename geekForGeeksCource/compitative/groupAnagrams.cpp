#include<bits/stdc++.h>
using namespace std;

void getChars(vector<char> &account,string s){
    for(char c : s) account.push_back(c);
}

void groupAnagrams(vector<string> str){
    unordered_map<string,vector<string>> ump;
    for(string s:str){
        vector<char> account;
        getChars(account,s); //string to char vector
        sort(account.begin(),account.end()); // sorting the char vector
        string sorted(account.begin(),account.end()); // char vector to string
        if(ump.find(sorted)==ump.end()){
            ump.insert(make_pair(sorted,vector<string>())); //initiating null vector->vector<string>()
        }// null + anonymous vector
        ump.at(sorted).emplace_back(s); //better then push_back() <- 3 step
    }
    for(auto x : ump){
            cout<<" [ ";
        for(auto y: x.second){
            cout<<y<<" ,";
        }cout<<"]\n";
    }
}


int main(){

    vector<string> str {"dog","cat","god","dgo","tac"};
    groupAnagrams(str);
    return 0;
}
