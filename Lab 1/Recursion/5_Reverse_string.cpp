/*
g++ -o reverse 5_Reverse_string.cpp
./reverse
*/

#include <iostream>
#include <string>
using namespace std;

string reverse (string s){
    return (s.length() == 0) ? "" : reverse(s.substr(1)) + s[0];
}

int main() {
    string s;
    cout << reverse("Hello") << endl;
    cout << reverse("I love HCMUT") << endl;
    cout << reverse("") << endl;


    return 0;
}