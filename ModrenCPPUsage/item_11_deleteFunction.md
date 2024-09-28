# prefer delete function over private undefined function.

## Usage of delete function :

1. There might be situations where c++ compailer implictly convert the parameters passed to function.
    And we dont want that to be happend. (Like we dont want chars to get converted to int and call that function.)
```cpp
    class Calculator {
    public:
        int addition(int a, int b) { return a + b; }
    };

    Calculator calculator;
    calculator.addition(20,25);      // VALID
    calculator.addition(2.3F,5.4F);  // VALID : float converts to int
    calculator.addition('a','b');    // VALID : char converts to int.
```
to prevent the call of addition when we pass char's then we will be overloading it and deleting that function.
```cpp
    class Calculator {
    public:
        int addition(int a, int b) { return a + b; }
        int addition(char a,char b) = delete;
        int addition(double a,double b) = delete;
    };

    Calculator calculator;
    calculator.addition(20,25);
    calculator.addition(2.3F,5.4F);  // ERROR : ambiguity to call this. (to call int based or char based method) 
    calculator.addition('a','b');    // ERROR : as we are calling deleted function
```

2. We may declare a template which accept only few types but rejects to do operations on some specific typename. Then we can delete that types using delete. The below calculate template method can be used to calculate **char** addition as well which is not valid.
```cpp
    template<typename T>
    T calculate(T&& a, T&& b) {
        return a + b;
    }
```

To make **char** not available for operations, then we will be using delete method to do that.

```cpp
template<> 
char calculate(char&&,char&&) = delete;
```
We may also want to delete the **const char** and **const volatile char** as well.
``