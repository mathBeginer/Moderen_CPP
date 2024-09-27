#include<iostream>
#include<mutex>
#include<memory>

using namespace std;

using mutexGuard = std::lock_guard<std::mutex>;
mutex f1m , f2m ,f3m;

void fun(int a) {cout<<"func(int)\n";}
void fun(bool b) {cout<<"func(bool)\n";}
void fun(void* a) {cout<<"func(void*)\n";}


class Widget;
int f1(std::shared_ptr<Widget> spw){}
double f2(std::unique_ptr<Widget> upw){}
bool f3(Widget *w){}

template<typename funcType,
         typename mutexType,
         typename ptrType>
decltype(auto) lockAndCall(funcType func,
                           mutexType& mutex,
                           ptrType ptr)
{
    mutexGuard g(f1m);
    return func(ptr);
} 


int main() {
    // fun(0);
    // fun(NULL);
    // fun(nullptr);
    lockAndCall(f1,f1m,0);
    lockAndCall(f1,f1m,NULL);
    lockAndCall(f1,f1m,nullptr);
    return 0;
}