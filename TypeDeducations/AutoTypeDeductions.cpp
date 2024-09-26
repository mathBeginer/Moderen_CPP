#include<iostream>
#include<typeinfo>
#include<deque>

template<typename container, typename index>
auto authAndAccessWithDeclareType(container& c, index i) -> decltype(c[i]) {
    // some method to authenticate user.
    return c[i]; // c[i] return type is T&
}

template<typename container, typename index>
auto authAndAccessWithAuto(container& c, index i) { // returnType is managed by auto.
    // some method to authenticate user.
    return c[i]; // this just returns the value present inside the c[i].
}

int main() {

    auto x1 = 1;                    // type = int
    auto x2(2);                     // type = int
    auto x3 = {3};                  // type = std::initializer_list<int> 
    auto x4{3};                     // type = std::initializer_list<int> 

    const int x5 = 10;
    auto x6 = x5;
    auto& x7 = x5;

    // x1 = "a";
    // x1 = 4;
    // x2 = "a";
    // x3 = x4;
    // x4 = "a";
    // x6 = "a";
    // x7 = "a";


    /* auto return types */
    std::deque<int> q = {5,4,6,3,7};
    authAndAccessWithDeclareType(q,2) = 0;
    authAndAccessWithAuto(q,1); // we will get int but not reference.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
    for(int& ele: q) std::cout<<ele<<" ";std::cout<<"\n";
    return 0;
}