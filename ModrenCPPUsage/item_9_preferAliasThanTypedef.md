#   alias (using) & typedef

1. prefer alias rather than typedef

```cpp
    typedef std::unique_ptr<std::map<int,std::string>> uptr_mapSS; // TYPEDEFs
    using uptr_mapSS = std::unique_ptr<std::map<int,std::string>>; // ALIAS

    typedef void (*FP)(int,double);
    using FP = void(*)(int,double);
```

2. Power of alias is seen when we use templates. Alias can be templeteaized but typedef's cannot.

```cpp
    template<typename T>
    using MyAllocList = std::list<T , MyAlloc<T>>;

    MyAllocList<Widget> lw; // lw type = list<Widget , MyAlloc<Widget>>;

    template<typename T>
    struct MyAllocList {
        typedef list<T, MyAlloc<T>> type; 
    }
    
    MyAllocList<Widget>::type lw; // lw type = list<Widget, MyAlloc<Widget>>
```