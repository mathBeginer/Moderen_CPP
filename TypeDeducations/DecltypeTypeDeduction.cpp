#include<iostream>
#include<typeinfo>

using namespace std;
int gx = 20;

auto ex(int& rx) {
    return rx;
}

int main() {
    int x = 5;
    int* px = new int(4);
    auto y = &x;
    auto py = px;
    int &z = x;
    cout<<typeid(y).name() <<" " <<typeid(py).name()<<" " <<typeid(z).name()<<"\n";
    
    auto exvar = ex(x);
    exvar = 20;
    cout<<typeid(exvar).name() <<"\n";
    cout<<x;
    return 0;
}