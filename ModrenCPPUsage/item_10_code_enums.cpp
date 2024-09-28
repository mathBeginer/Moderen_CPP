#include<iostream>

using namespace std;

class Brush {
    int someFunc() {
        if(white < 1.5)
            return 10;
        return 20;      
    }
private:
    enum Colour {black , white , red };
};

int main() {
    
    return 0;
}