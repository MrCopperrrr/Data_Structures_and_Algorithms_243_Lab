/*
g++ -o rev Reverse_string.cpp
./rev
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
    return 0;
}