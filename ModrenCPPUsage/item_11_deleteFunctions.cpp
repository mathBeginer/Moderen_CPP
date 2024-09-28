#include<iostream>

using namespace std;

class Calculator {
public:
    int addition(int a, int b) { return a + b; }
    int addition(char a,char b) = delete;
    int addition(double a,double b) = delete;
};

int main() {
    Calculator calculator;
    calculator.addition(20,25);
    // calculator.addition(2.3,5.4);
   // calculator.addition('a','b');
    return 0;
}