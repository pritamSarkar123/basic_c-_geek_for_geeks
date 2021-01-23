#include<bits/stdc++.h>
using namespace std;
/*
    A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. We can capture external variables from enclosing scope by three ways :
      Capture by reference
      Capture by value
      Capture by both (mixed capture)

Syntax used for capturing variables :
      [&] : capture all external variable by reference
      [=] : capture all external variable by value
      [a, &b] : capture a by value and b by reference




A lambda with empty capture clause [ ] can access only those variable which are local to it.
Capturing ways are demonstrated below :
*/

int var=10;

auto lambda1=[ = ](){ // runtime capturing , from local scope /*v*/
    return 2*var;
};
auto lambda2=[v=var](){ //compile time capturing , form local scope , and stores it in v
    return 2*v;
};
int main(){
    var=20;
    cout<<lambda1()<<endl;/*^*/
    cout<<lambda2()<<endl;
    return 0;
}
