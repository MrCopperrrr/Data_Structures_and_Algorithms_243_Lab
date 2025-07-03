/*
g++ -o climb 9_Climb_Stairs.cpp
./climb
*/
#include <iostream>

using namespace std;

// Leetcode 70 
int climb_stairs(int n){
    if(n == 1 || n == 0) return 1; 
    return climb_stairs(n - 1) + climb_stairs(n - 2);
}

int main(){
    int n;
    cout << climb_stairs(5) << endl; // 8
    cout << climb_stairs(10) << endl; // 89
    return 0;
}