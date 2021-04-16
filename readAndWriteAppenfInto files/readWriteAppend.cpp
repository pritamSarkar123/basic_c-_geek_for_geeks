#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

vector<string> readFromFile(string fileName){
    ifstream file(fileName);
    vector<string> p;
    if(file.is_open()){
        string inp;
        while(getline(file,inp)){
            p.emplace_back(inp);
        }
        file.close();
    }else{
        cout<<"file did not open\n";
    }
    return p;
}
bool writeFromFile(const vector<string>& page,string fileName){
    ofstream file(fileName,ios::app);
    if(file.is_open()){
        for(int i=0;i<page.size();i++){
            file<<page[i]<<"\n";
        }
        file.close();
        return true;
    }
    return false;
}
int main(){
    vector<string> page=readFromFile("jobs.txt");
    for(string s:page){
        cout<<s<<"\n";
    }
    writeFromFile(page,"abc.txt");
    return 0;
}
