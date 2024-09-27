#include<iostream>
#include<atomic>

int main() {
    std::atomic<int> num{10};
    std::atomic<int> num1(20);
   // std::atomic<int> num2 = 200; // cant call this as atomic's copy constructor got deleted.
    
    double a = 10 , b = 20 , c = 30;
    int d = a + b + c;
    int e(a + b + c);
    int f{a + b + c}; // THROWS WARNING..!!

    std::initializer_list<double> il{21,18.5};
    std::cout<<il.size()<<"\n";

    return 0;
}