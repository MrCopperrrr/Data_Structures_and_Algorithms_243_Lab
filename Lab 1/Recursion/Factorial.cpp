/*
g++ -o fac Factorial.cpp
./fac
*/

#include <iostream>

using namespace std;

int factorial(int n){
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main(){
    int n;
    cout << factorial(6);
    return 0;
}