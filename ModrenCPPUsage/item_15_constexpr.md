# const & constexpr

## Difference between const & constexpr : 

    
#### const:
    
    Evaluates value at compile time or runtime.
    used for variables , functions , objects.
    Can be initialized at runtime.

```cpp
    int calculate(int n) {
        return n * 5;
    }

    const int c_val = calculate(10); // WILL BE EVALUATED AT RUNTIME.
```

####    constexpr:

        ALWAYS evaluate at compile time only.
        usage in variables , functions , literals.
        Must be initialized with literals. ( some const value OR constexpr value)

```cpp
    int n = 10;
    constexpr int ce_val = n; // ERROR: as n is not const or constexpr.                         
    const int n = 10;   // making int as const or constexpr will resolve the above error.  
    
    
    int calculate(int n) {
        return n * 5;
    }
    constexpr int c_val = calculate(10); // ERROR : asks us to make calculate method as constexpr
    constexpr int calculate(int n) {     // this resolves the error. (calculates the result at compailer time.)
        reutrn n * 5;
    }

```

## Suggustions :

1. Prefer constexpr where ever possible. It enhances the performance a lot. as it stores values at compaile time only.
2. try to combine const and constexpr when ever possible.
3. constexpr have great role in TMP.

4. If values passed to constexpr function are available during compile-time, then that function will get computed during compile time only. Or else it will compute and return result at runtime.

```cpp
    constexpr int fun(int a , int b) {
        if(std::_Is_constant_evaluated())  // used to distinguish whether code is evaluated during compile time or runtime
        return n * 5;
    else // RUNTIME CODE
        return n*2;
    }

    // fun will evaluate during compile time in below case
    constexpr int a = 10;
    constexpr int b = 230;
    constexpr auto c = fun(a , b); // compileTime evaluated this value.
```

5.  Userdefined Objects also can be used as literals only if their constructor is defined as constexpr. The methods like getters and setters can also make as constexpr. (return type of setters is void and making constexpr of void is not possible in c++11 and resolved this in c++14.)

```cpp
    // constexpr of Point constructor makesure that point can be calculated at compile-time.
    // Then we can assign this for values required at compile time.
    class Point {
    public:
        constexpr Point(int x, int y): _x{x} , _y{y} {}
        
        constexpr int getX() const { return _x;}
        
        constexpr int getY() const { return _y;}

        constexpr void setX(int x){  _x = x; }
        
        constexpr void setY(int y){  _y = y;}
    private:
        int _x{0} , _y{0};
    };

    // if both p1 & p2 are constexprs while passing, its values then mid will calculated at compiule time.
    // else it will get calculated at runtime. ()
    constexpr Point mid(const Point& p1 ,const Point& p2)  noexcept{  
        if(std::__is_constant_evaluated())
            return {(p1.getX() + p2.getX()) / 2 , (p1.getY() + p2.getY()) / 2 };
        return {-1,-1};
    }

    constexpr Point p1(20.4,8.2); 
    constexpr Point p2(1.2,3.4);
    constexpr auto m = mid(p1,p2); // Compile time.

    Point p3(3,4);
    auto m2 = mid(p3,p1); // RUNTIME : as p3 is not const
```

6. Take care while declaring something as constexpr. because, its value is evaluated at compile time and client will assume that he wil get values evaluated at compile time only. Then he writes his code accordingly. but in future if we want to change it to runitme evaluation, then there is lot of changes required for client code. (if client uses m2 example then its fine but problem arrises only when client uses m example.)

7. We cannot call non-constexpr functions inside constexpr functions. even if we are using constexpr function at runtime.

```cpp
   int add(const int &a , const int &b) {
        return a + b;
    }

    constexpr int sum(const int &a, const int &b) {
        return add(a , b); // ERROR : call to non-'constexpr' function 'int add(const int&, const int&)' 
    }

    int main() {
        auto a = sum( 2 , 4);
        return 0;
    } 
```