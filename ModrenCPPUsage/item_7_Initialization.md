# Initializations

1. Different initializations types :
```cpp
    int x = 0;
    int x(0);
    int x{0};    // C++11 PREFERED
    int x = {0}; // C++11 

    std::vector<int> v{1,2,3,4,5};
```

2. Default values initialization in class :
```cpp
    class Widget {
        private:
            int x{0};
            int x = 0;
            int x(0);   // ERROR (not allowed)
    };
```

3. Initializating uncopiyable objects made easier using {} initialization.
```cpp
    std::atomic<int> ai{0};
    std::atomic<int> ai(0);
    std::atomic<int> ai = 0; // ERROR 
```

4. Prohibits implicit type narrowing. IT throws warning or error when ever implict narrowing happens.
```cpp
 double a = 10 , b = 20 , c = 30;
    int d = a + b + c;
    int e(a + b + c);
    int f{a + b + c}; // THROWS WARNING..!!
```

5. what is the below code means ?

```cpp
    Widget w(); // Fuction declartion which returns widget OR object with default ctor
    Widget w{}; // EASY TO IDENTIFY as obj with default ctor called.
```

6. when a constructor have initializer_list as it arguments, them compailer will strictly tries to match to
it only when ever we initialize object with intializer list.
```cpp
class Widget {
public:
    Widget() {std::cout<<"ctor Widget()\n";}
    Widget(int i , bool b) {std::cout<<"ctor Widget(int i, bool b)\n";}
    Widget(int i , double d) {std::cout<<"ctor Widget(int i, double b)\n";}
    Widget(std::initializer_list<float> il) { {std::cout<<"ctor Widget(initializer_list<float> il)\n";}}
};

    double x = 5.0;
    Widget w1(10,true); // ctor Widget(int i, bool b)
    Widget w2{10,true}; // ctor Widget(initializer_list<float> il) (as true converted to float only.)
    Widget w3(10,5.0);  // ctor Widget(int i, double b)
    Widget w4{10,x};    // ERROR : narrowing of double(x) to float is not possible.
    Widget w5{3.4F};    // ctor Widget(initializer_list<float> il)
```