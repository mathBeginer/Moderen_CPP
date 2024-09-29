#include<iostream>

using namespace std;

int add(const int &a , const int &b) {
    return a + b;
}

constexpr int sum(const int &a, const int &b) {
    return add(a , b); // ERROR : call to non-'constexpr' function 'int add(const int&, const int&)' 
}

int main() {
    auto a = sum( 2 , 4);
    return 0;
}