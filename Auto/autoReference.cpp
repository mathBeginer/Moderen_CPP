#include<iostream>

using namespace std;

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
    auto val = foo.get(); // This is returning ref but we are auto skiped that ref.
    val = 100; // foo's _x didnt get updated.
    cout<<foo.get()<<"\n";
    auto& valRef = foo.get();
    valRef = 200;
    cout<<foo.get()<<"\n";
    decltype(foo.get()) valDecltype = foo.get();
    valDecltype = 9090;
    cout<<foo.get()<<"\n";
    return 0;
}
