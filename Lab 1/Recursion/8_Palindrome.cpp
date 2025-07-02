/*
g++ -o pali 8_Palindrome.cpp
./pali
*/

#include <iostream>

using namespace std;

// bool is_palindrome(string s) {
//     if (s.length() <= 1) return true; 
//     if (s[0] != s[s.length() - 1]) return false; 
//     return is_palindrome(s.substr(1, s.length() - 2)); 

//     /*
//     index:  012345
//     string: abcdef
//     length: 123456
//     */
// }


//Leetcode 125
bool is_palindrome(string s){
    return fun(s, 0, s.length() - 1);
}

bool fun(const string & s, int L, int R){
    while (L < R && !isalnum(s[L])) L++; 
    while (L < R && !isalnum(s[R])) R--; 
    if(L >= R) return true;
    if(tolower(s[L]) != tolower(s[R])) return false; 
    return fun(s, L + 1, R - 1); 
}

int main() {
    string s;
    cout << is_palindrome("madam") << endl; // 1 (true)
    cout << is_palindrome("hello") << endl; // 0 (false)
    cout << is_palindrome("racecar") << endl; // 1 (true)
    cout << is_palindrome("a") << endl; // 1 (true)
    cout << is_palindrome("") << endl; // 1 (true)
    cout << is_palindrome("abccba") << endl; // 1 (true)
    cout << is_palindrome("A man, a plan, a canal: Panama") << endl; //1 (true)
    return 0;

}