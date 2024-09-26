#include<iostream>

// CONSTANTNESS is not preserved here.
template <typename T>
void func_passByValue(T a) {
    if constexpr (std::is_const_v<T>)
        std::cout<<"constant\n";
    else
        std::cout<<" not constant\n";
    a = 24;
}

// CONSTANTNESS is not preserved here.
template <typename T>
void func_passByValueWhenCCCAsParam(T a) {
    if constexpr (std::is_const_v<T>)
        std::cout<<"constant " <<a<<"\n";
    else
        std::cout<<" not constant : "<<(a)<<"\n";
    // *(a + 1) = '1';
    std::cout<<"         data modified "<<a<<"\n";
}

// CONSTANTNESS is preserved here
template <typename T>
void func_referenceTo(T& a) {
    if constexpr (std::is_const_v<T>)
        std::cout<<"constant\n";
    else
        std::cout<<" not constant\n";
    // a = 24;
}

// CONSTANTNESS is preserved here.
template <typename T>
void func_pointerTo(T* a) {
    if constexpr (std::is_const_v<T>)
        std::cout<<"constant\n";
    else
        std::cout<<" not constant\n";
    // a = 24;
}

// CONSTANTNESS is preserved as we are defining in function itself. then type will always deduce to int.
// const will be removed.
template <typename T>
void func_ConstpointerTo(const T* a) {
    if constexpr (std::is_const_v<T>)
        std::cout<<"constant\n";
    else
        std::cout<<" not constant\n";
    // a = 24;
}

// UNIVERSAL REFERENCE(&&) : 
template <typename T>
void func_universalRerence(T &&a) {
    if constexpr (std::is_const_v<T>)
        std::cout<<"constant\n";
    else
        std::cout<<" not constant\n";
   // a = 24;
}

template <typename T>
size_t func_arrayPassingAsArguments(T param) {
  //  param = "abcd";
    return 5;
}

template <typename T>
size_t func_array_paramsAsReferenceToArray(T& param) {
  //  param = "abcd";
    return 5;
}

template <typename T,std::size_t N>
constexpr std::size_t arraySize(T (&arr)[N]) noexcept{
   // arr[2] = 10;
    return N;
}

int sum(int a, int b ) { return a + b; }
template <typename T>
int func_functionAsParamater(T param) {
    param = "ABCD";
    std::cout<<param(3,4)<<"\n";
    return 5;
}

template <typename T>
int func_functionAsReferenceParamater(T& param) {
    param = "ABCD";
    std::cout<<param(3,4)<<"\n";
    return 5;
}

int main() {
    int a = 10;
    const int b = 20;
    const int &c = b;

    std::cout<<" PASS BY VALUE :\n";
    func_passByValue(a);
    func_passByValue(b);
    func_passByValue(c);
    
    std::cout<<" FUNCTION TAKING REFERENCE :\n";
    func_referenceTo(a);
    func_referenceTo(b);
    func_referenceTo(c);

    std::cout<<" FUNCTION TAKING POINTER :\n";
    func_pointerTo(&a);
    func_pointerTo(&b);
    func_pointerTo(&c);

    std::cout<<" FUNCTION TAKING CONST POINTER :\n";
    func_ConstpointerTo(&a); 
    func_ConstpointerTo(&b);
    func_ConstpointerTo(&c);

    std::cout<<" FUNCTION TAKING UNIVERSAL REFERENCE(&&) :\n"; // (output is not correctly printing.)
    func_universalRerence(a); // T = int&
    func_universalRerence(b); // T = const int&
    func_universalRerence(c); // T = const int&
    func_universalRerence(4); // T = int&& 

    std::cout<<" FUNCTION TAKING PASS BY VALUE ONLY :\n ";
    const char* const ptr = "non modifiable data";
    
    func_passByValueWhenCCCAsParam(ptr);    // T = const char* 
    
    std::cout<<"USING ARRAYS IN TEMPLATES\n";
    int arr[4] = {1 , 2 , 3, 4};
    const int carr[13] = {1 ,2 ,3 ,4 ,5, 6, 7};
    const int *carr_ptr = carr;

    func_arrayPassingAsArguments(arr);               // T = int*
    func_arrayPassingAsArguments(carr);              // T = const int*
    func_arrayPassingAsArguments(carr_ptr);          // T = const int*
    
    func_array_paramsAsReferenceToArray(carr);       // T = const int[13]
    func_array_paramsAsReferenceToArray(carr_ptr);   // T = const int*
    
    std::cout<<arraySize(arr);                       // T = int , N = 4
    std::cout<<arraySize(carr);                      // T = const int, N = 13

    std::cout<<"FUNCTION AS PARAMS\n";
    func_functionAsParamater(sum);                   // T = int(*)(int,int)
    func_functionAsReferenceParamater(sum);          // T = int(int,int)

    return 0;
}
/*
    const char* const ptr = "nonmodifiable data";
    ptr data cannot cannot be modified & ptr cannot point to another location.
    when this is passed to template it is deduced to const char * (non modifiable data)
*/