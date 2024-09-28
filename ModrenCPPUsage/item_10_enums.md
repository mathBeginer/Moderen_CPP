# enum

### un-scoped enum 

The names of ennumurators is the block in which enumurators is defined : UN-SCOPED ENUMS

```cpp
    class Brush {
    private:
        enum Colour {black , white , red };
        bool white{false}; // ERROR : white conflicts with a previous declaration.
    };
```

### scoped enum : (enum class)

The names of ennumurators are with in the block they defined.
(add class after enum keyword)
```cpp
    class Brush {
private:
    enum class Colour {black , white , red };
    bool white{false};
};
```

## Which one to use ? scoped enums. but why ? 

1. scoped enums are strongly typed which stopes name pollution.

2. scoped enums are strongly typed when compare to unscoped enums.
    Like unscoped enum names will get converted to int and then to float , but scoped enums will not convert
    like that and throws error.

```cpp
    class Brush {
        int someFunc() {
            if(white < 1.5) // VALID CODE (white converts to 1.0)
                return 10;
            return 20;      
        }
    private:
        enum Colour {black , white , red }; // names are not strongly typed here.
    };


    class Brush {
        int someFunc() {
            if(white < 1.5) // ERROR : Color::white should be called and it cannot compare with int or float.
                return 10;
            return 20;      
        }
    private:
        enum class Colour {black , white , red };
    };
```

3. scoped enums can be forward declared but unscoped enums cannot do that.

```cpp
    enum Colour; //ERROR
    enum class Colour; // VALID
```