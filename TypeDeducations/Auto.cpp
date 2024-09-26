#include<iostream>
#include<typeinfo>
#define printX(x,rx,px) std::cout<<#x<<":"<<x<<"   "<<#rx<<":"<<rx<<"   "<<#px<<":"<<*px<<"\n"
#define errorX(x) x = "abc"
/* 
    There might be times where its hard for us to declare the types of variables. We will say 
    compailer to fighure out the type of variable.

    Initializers of autotype must have some proper types defined to them.
*/

int func_normal(int x) {
    x = 1;
    return x;
}

auto func_auto(int x) {
    x = 2;
    return x;
}

int& func_ref_normal(int& rx) {
    rx = 3;
    return rx;
}

auto func_ref_auto(int& rx) { // expected rtype is [int&] but got [int]
    rx = 4;
    return rx;
}

int* func_pointer_normal(int* px) {
    *px = 5;
    return px;
}

auto func_pointer_auto(int* px) {
    *px = 6;
    return px;
}

int main() {
    int a = 10 , b = 20;
    double a1 = 10.50F;
    auto c = a + b;
    auto d = a + a1;
    
    std::cout<<typeid(c).name()<<std::endl;
    std::cout<<typeid(d).name()<<std::endl;
    
    int x = 0;
    int &rx = x;
    int *px = &x;
    
    std::string y = "abcd";
    y = func_normal(x);
    y = func_auto(x);
    y = func_ref_normal(x);
    y = func_ref_auto(x); 
    y = func_pointer_normal(px);
    y = func_pointer_auto(px);
    return 0;
}