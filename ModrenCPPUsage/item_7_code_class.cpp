#include<iostream>
#include<initializer_list>
#include<vector>

class Widget {
public:
    Widget() {std::cout<<"ctor Widget()\n";}
    Widget(int i , bool b) {std::cout<<"ctor Widget(int i, bool b)\n";}
    Widget(int i , double d) {std::cout<<"ctor Widget(int i, double b)\n";}
    Widget(std::initializer_list<std::string> il) { {std::cout<<"ctor Widget(initializer_list<float> il)\n";}}
};

int main() {
    double x = 5.0;
    Widget w1(10,true);
    Widget w2{10,true};
    Widget w3(10,5.0);
   // Widget w4{10,x};
    Widget w5{3.4F};

    return 0;
}