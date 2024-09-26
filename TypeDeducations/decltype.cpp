#include<iostream>
#include<typeinfo>

/*
    Sometimes, we might want to define a variable with a type that the compailer deduces from an
    expression but, do not want to use that expression to initialize the variable.

    for that c++ introducted second type speficfier called decltype.

    Compailer analyzes the expression to determine its type but dosent evaluate the expression.

    decltype(num) --> gives num type.
    decltype((num)) --> always gives reference to num
*/

double sum(int a,int b) {
    std::cout<<a <<" " << b<<"\n";
    return 1.0;
}

int main() {
    int x = 5;
    /*
        Here compailer dosent call sum method. it gives the same time as that of sum returns
        when we call sum method.
        IF WE WERE TO CALL SUM. (We dont actually called it.)
    */
    decltype(sum(4,5)) ele = x;

    const int ci = 0 , &cj = ci;
    decltype(ci) x = 0;
    decltype(cj) y = x;
 //   decltype(cj) z; // initialization of this varaiable is missing.


    /*
        Decltype and reference.
    */
    int i = 0 , *p = &i , &r = i;
    decltype(r) el0; // ERROR: as r type is reference int&
    decltype(r + 0) el; // r + 0 evaluates to int.
    decltype(*p) elp; // ERROR : *p gives address of i which is int& which needs to initialized at begining only.
    
    decltype ((i)) ele3; // ERROR: compailer evaluates (i) expression and returns reference of i[int&] instead of type of i.
    decltype(i) ele4; // i type is int
    return 0;
}