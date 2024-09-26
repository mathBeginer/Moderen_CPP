#include<iostream>
#include<vector>

using namespace std;

void func(bool eleB) {

}

int main() {
    vector<bool> vb{false,true,false,true,true};
    vector<int> vi{1,2,3,4};
    auto eleB = vb[2];
    auto eleI = vi[2];
    cout<<eleB<<"\n";
    eleB = true; // orginal vb got updated.
    cout<<vb[2]<<"\n";
    func(eleB);


    // RAMDON VECTOR EXPLORING
    vector<int>::size_type;
    return 0;
}