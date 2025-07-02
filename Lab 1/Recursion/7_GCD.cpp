/*
g++ -o gcd 7_GCD.cpp
./gcd
*/

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    int a, b;
    cout << gcd(48, 18) << endl; // 6
    cout << gcd(56, 98) << endl; // 14
    cout << gcd(101, 10) << endl; // 1
    return 0;
}