/*
g++ -o power 4_Power_function.cpp
./power
*/


#include <iostream>

using namespace std;

int power(int a, int b){
    if (b == 0)  return 1;
    return a * power(a, b-1);
}

int main(){
    int a, b;
    cout << power(2, 5) << endl;
    cout << power(3, 3) << endl;
    cout << power(5, 0) << endl; 
    cout << power(10, 10) << endl;
    cout << power(2, 10) << endl;

    return 0;
}