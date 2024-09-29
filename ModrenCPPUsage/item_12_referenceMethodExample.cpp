#include<iostream>
#include<vector>

using namespace std;

class Point {
public:
    Point() = default;
    Point(Point &p) {
        cout<<"Copy constructor got called\n";
        this->x = p.x;
        this->y = p.y;
    }
    
    Point(Point&&) {
        cout<<"Move constructor got called\n";
        x = move(x);
        y = move(y);
    }
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;
    int x{-1} , y{-1};
};

class Example {
public:
    Example() = default;
    Example(Example&& ex) { cout<<"MOVE\n"; this->values = move(ex.values); }
    Example(Example& ex ) { cout<<"COPY\n"; this->values = ex.values; }
    
    
    Point& data() & { return values; }
    Point data() && { return move(values); }
    
    void print() {
       cout<<values.x<<" "<<values.y<<" ";
        cout<<"\n";
    }
private:
    Point values;  
};



int main() {
    Example ex;
    
    auto vals1 = ex.data();  // Point COPY CONSTRUCTOR  OF POINT GOT CALLED.
    vals1.x = 20;
    vals1.y = 15;
    ex.print();
    auto& vals1_1 = ex.data(); // Point COPY CONSTRUCTOR NOT GOT CALLED.
    vals1_1.x = 20;
    vals1_1.y = 15;
    ex.print();
   
    auto vals2 = Example().data(); // Point move constructor got called.
    vals2.x = 20;
    vals2.y = 15;
    return 0;
}