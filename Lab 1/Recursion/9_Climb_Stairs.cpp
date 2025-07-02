/*
g++ -o climb 9_Climb_Stairs.cpp
./climb
*/
#include <iostream>

using namespace std;

// Leetcode 70 tabulation
// int climbStairs(int n) {
//         vector<int> v(n + 1, 0);
//         v[0] = 1;
//         v[1] = 1;
//         for(int i = 2; i <= n; i++)
//             v[i] = v[i - 1] + v[i - 2];
//         return v[n];
// }

int climb_stairs(int n){
    if(n == 1 || n == 0) return 1; 
    return climb_stairs(n - 1) + climb_stairs(n - 2);
}

int main(){
    int n;
    cout << climb_stairs(5) << endl; // Output: 8
    cout << climb_stairs(10) << endl; // Output: 89
    return 0;
}