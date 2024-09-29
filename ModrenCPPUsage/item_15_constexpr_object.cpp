#include<iostream>
#include<type_traits>

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

constexpr Point mid(const Point& p1 ,const Point& p2)  noexcept{  
    if(std::__is_constant_evaluated())
        return {(p1.getX() + p2.getX()) / 2 , (p1.getY() + p2.getY()) / 2 };
    return {-1,-1};
}
int main() {
    constexpr Point p1(20.4,8.2); // Can 
    constexpr Point p2(1.2,3.4);
    constexpr auto m = mid(p1,p2); // Compile time.
    std::cout<<m.getX() << " "<<m.getY()<<"\n";
    
    Point p3(3,4);
    auto m2 = mid(p3,p1); // RUNTIME : as p3 is not const
    std::cout<<m2.getX() << " "<<m2.getY()<<"\n";

    return 0;
}