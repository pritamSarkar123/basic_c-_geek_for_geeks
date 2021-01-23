#include<iostream>
#include<iomanip> // for manipulating precision
#include<cmath> // for floor and ceil and log10()
#include<numeric> //for accumulate
#include<vector>
#include<algorithm> // for min() min({})
using namespace std;

#define all(x) x.begin(),x.end()

void seePrecisions(){
    /*
        float -> 32 bit, upto 6 -7 decimal places
        double -> 64 bit, upto 15 - 16 decimal places
    */
    float f= 89.666666666666666666666666666f;
    double d=89.6666666666666666666666666666;
    cout<<"Befor manipulation"<<endl;
    cout<<f<<endl<<d<<endl;
    cout<<"After maipulation"<<endl;
    cout<<setprecision(30); //precision from begining of the number
    //OR cout.precision(100)
    cout<<f<<endl<<d<<endl;
    cout<<setprecision(30);
    cout<<fixed;// precision from point
    cout<<"Precision from point"<<endl;
    cout<<f<<endl<<d<<endl;

}
void floorAndCeil(){
    int a=5;
    int b=2;
    cout<<setprecision(4);
    cout<<floor((float)a/b)<<endl;
    cout<<ceil((float)a/b)<<endl; // delivering the float val of a, not storing to a
    //for accurate ceil answer if we know the a/b is float then
    cout<<(a+b-1)/b<<endl;
}
void efficientlyPrimeFinding(int n){
    // sqrt(n) takes O(log n) time , so total loop cost O(n^(1/2)* log(n))
    bool notPrime=false;
    for(int i=2 ; i< sqrt(n);i++){
        if(n%i==0){
            cout<<n<<" is not prime"<<endl;
            notPrime=true;
            break;
        }
    }
    if(!notPrime)
        cout<<n<<" is prime"<<endl;
    notPrime=false;
    // i*i takes O(1) time so overall loop takes O(n^(1/2)) times
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<n<<" is not prime"<<endl;
            notPrime=true;
            break;
        }
    }
    if(!notPrime)
        cout<<n<<"is prime"<<endl;
}
void noOfdigitCount(int n){
    int cnt=0;
    int n1=n;
    while(n1){ // takes O(log 10(n))
        cnt++;
        n1/=10;
    }
    cout<<"No of digits "<<cnt<<endl;
    cout<<"No of digits "<<(int)(log10(n)+1)<<endl; //takes O(1) time
}
void getAnswers(){
    vector<int> v{1,2,3,4,5};
    // accumulate directly returns the value
    int sumresult=0;
    cout<<accumulate(all(v),sumresult)<<endl; //be deault do sum
    int subresult=100;
    cout<<accumulate(all(v),subresult,minus<int>())<<endl; // for subtraction int, minus<int>() blank unary - obj
    int mulresult=1;
    cout<<accumulate(all(v),mulresult,[](int x,int y)->int{return x*y;})<<endl; // lambda or any function for mult

}
void minMax(){
    cout<<min(5,6)<<endl;
    cout<<min({2,5,1,2,5,80,8})<<endl; // same for max
    vector<int> v{1,2,3,4,5};
    cout<<*min_element(all(v))<<endl;
    cout<<*max_element(all(v))<<endl;
}
void someGCCFunctions(){
    cout<<__gcd(12,56)<<endl;
    cout<<"no of ones "<<__builtin_popcount(12)<<endl; // popcountl popcountll for long and long
    cout<<" parity "<<__builtin_parity(7)<<endl; // odd no of ones 1
    cout<<" parity "<<__builtin_parity(5)<<endl; //even no of ones 0
}
int main(){
    seePrecisions();
    floorAndCeil();
    efficientlyPrimeFinding(17);
    efficientlyPrimeFinding(54);
    noOfdigitCount(234);
    getAnswers();
    minMax();
    someGCCFunctions();
    return 0;
}
