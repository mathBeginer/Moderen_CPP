# nullptr

# Problems solved

1. 0 and NULL are integral types and we cannot use them to assign to pointers.

```cpp
    void fun(int a) {cout<<"func(int)\n";}
    void fun(bool b) {cout<<"func(bool)\n";}
    void fun(void* a) {cout<<"func(void*)\n";}

    fun(0);        // func(int)
    fun(NULL);     // ERROR : call for func(NULL) is ambigious 
    fun(nullptr);  // calls fun(void*)
```

2. Handling when a function return is a 0 OR NULL , it is not considered as pointer when we use auto
variable while calling that function. and this can lead to unpredicetd logice written. So return nullptr
so that auto get deduced to pointer type.

3. real use of nullptr is seen when we use templates. Suppose we want to lock mutex for function we are calling. And lets assume that fucntion takes pointer as parameter. THen when we pass 0 or NULL, it will get
converted to integral type by template and when it is passed at location where pointer is expected will throw a error as it expect pointer but passed int(when 0 passed)

```cpp
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
        return func(ptr); // This func takes only pointer. any other types throws error.
    }


    lockAndCall(f1,f1m,0);       // ERROR.
    lockAndCall(f1,f1m,NULL);    // ERROR.
    lockAndCall(f1,f1m,nullptr); // Works fine.
```