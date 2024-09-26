# auto

## Problems solved

1. Uninitialized variable problem got solved with auto.
        
```cpp
    int x;       // COMPILES
    auto y;      // ERROR
    auto z = 0    // COMPAILES
```
2. Over comes the long declaration type of iterators.

```cpp
    typename std::iterator_traits<It>::value_type variable = *begin;
    auto variable = *begin; // OVER HEAD IS GONE.
```

3. Prefering auto over function is better for performance. **std::function** is used for callable objects (lambdas, functionPointer, functors). This stores memory to remember this which causes performance problem.

4. Using auto implecit type conversion dosent happen.

```cpp
    auto v = std::vector<int>{1,2,3};
    int t = v.size(); // size_t is converted to int
    auto t = v.size(); // size_t is preserved.
```

5.  It is very often the case that even though we explicitly specify the type, we don’t actually care about it.

```cpp
    std::map<int,std::string> m;
    for(std::map<int,std::string>::const_iterator it = m.cbegin(); it != m.cend(); it++) {}

    for(auto it = m.cbegin(); it != m.cend(); it++) {}
```

6. The auto specifier is only a placeholder for the type, not for the const / volatile and references specifiers. If you need a const / volatile and/or reference type, then you need to specify them explicitly. In the following example, foo.get() returns a reference to int; when the variable x is initialized from the return value, the type deduced by the compiler is int, not int&. Therefore, any change made to x will not propagate to foo.x_. In order to do so, we should use auto&:

```cpp
class Foo {
private:
    int _x;
public:
    Foo(int const x = 0 ): _x{x} {}
    int& get() { // RETURNING AN REF
        return _x;
    }
};

int main() {
    Foo foo(34);
    auto val = foo.get(); // val type = [int]
    auto& val = foo.get(); // val type = [int&] 
    declaretype(foo.get()) valDecltype = foo.get(); // This also works as expected [int&]
    return 0;
}
```

7. Auto resolves the porting issue. Like when we write code for 32 bit meachine. vector<int>::size_type returns the exactly required for meachine. (32 bit or 64 bit). But we may write unsigned directly in code which causes portability issue.

```cpp
unsigned sz = v.size(); // 32 -bit meachine its fine. fails for 64 bit meachine.
auto sz = v.size(); // works for both. as it takes exact return type of v.size() only.
```

8. unordered_map template is :
```cpp
  template<typename _Key, typename _Tp,
	   typename _Hash = hash<_Key>,
	   typename _Pred = equal_to<_Key>,
	   typename _Alloc = allocator<std::pair<const _Key, _Tp>>>
```
here we can see that key formed is **const _key** in pair.
So when we explictly deifine that then we should define as it is defined internally of map.
```cpp
for(const std::pair<std::string , int> &p :mp) {}
// Here for each object pair in map, it converts to pair<sting,int> and then it destroys it at the end of scope. as _key type is string not const string
```

## In what sitations auto fails ?

    Situations where proxy design pattern is implemnted.
    When we tries to access the proxied type(inner implemented type), but auto returns the porxy type only.

```cpp
    vector<bool> vb{false,true,false,true,true};
    vector<int> vi{1,2,3,4};
    auto eleB = vb[2]; // vector<bool>::reference --> this is got returned because internally this is proxied.
    auto eleI = vi[2]; // int --> as implemented directly.
    eleB = true; // orginal vb got updated.
``` 