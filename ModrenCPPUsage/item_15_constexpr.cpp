#include<iostream>
#include<array>
#include<type_traits>

using namespace std;

constexpr int calculateVal(int n) {
    if(std::_Is_constant_evaluated())  // used to distinguish whether code is evaluated during compile time or runtime
        return n * 5;
    else
        return n*2;
}

int main() {
    const int c_val1 = calculateVal(10);
    const int c_val2 = calculateVal(20);
    
    int n = 10;
    cin>>n;
    constexpr int ce_val = calculateVal(40);
  //  constexpr int ce_val = x;
    cout<<c_val1<<" "<<c_val2<<"\n"<<ce_val<<"\n";
    return 0;
}