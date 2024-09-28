#include<iostream>
using namespace std;

template<typename T>
T calculate(T&& a, T&& b) {
    return a + b;
}

template<> 
char calculate(char&&,char&&) = delete;

int main() {
    int addI = calculate(1,2);
    float addF = calculate(1.2F,2.3F);
    //char addC = calculate(' ','!');
    cout<<addI<<" "<<addF<<" "<<addC<<"\n";
    return 0;
}