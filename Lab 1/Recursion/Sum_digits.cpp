#include <iostream>

using namespace std;

int sum_digits(int n) { 
    if (n == 0) return 0; 
    return n % 10 + sum_digits(n / 10);
    
    // int sum = n % 10;
    // while (n > 0){
    //     n /= 10;
    //     sum += n % 10;
    // }
    // return sum;
}

int main(){
    int n;
    cout << sum_digits(123456789) << endl; //45
    cout << sum_digits(88888888) << endl; //64
    cout << sum_digits(808080080) << endl;
    return 0;
}