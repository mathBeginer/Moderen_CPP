#include<iostream>
#include<iterator>

template<typename It>
void dwim(It begin , It end) {
    while(begin != end) {
        typename std::iterator_traits<It>::value_type currValue = *begin;
    }
}

int main() {
    
    return 0;
}