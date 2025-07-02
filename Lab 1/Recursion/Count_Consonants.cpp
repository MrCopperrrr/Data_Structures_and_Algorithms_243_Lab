/*
g++ -o cc Count_Consonants.cpp
./cc
*/


#include <iostream>
using namespace std;

int count_consonants(string s){
    if(s.length() == 0) return 0;
    char lowchar = tolower(s[0]);

    bool isvowel = (lowchar == 'a' || lowchar == 'e' || lowchar == 'i' || lowchar == 'o' || lowchar == 'u');
    
    if (isalpha(lowchar) && !isvowel) {
        return 1 + count_consonants(s.substr(1));
    } else {
        return count_consonants(s.substr(1));
    }

}
    
int main() {
    string s;
    cout << count_consonants("Hello") << endl; // 3
    cout << count_consonants("I love HCMUT") << endl; // 6
    cout << count_consonants("") << endl; // 0
    cout << count_consonants("aeiou") << endl; // 0
    cout << count_consonants("bcdfghjklmnpqrstvwxyz") << endl; // 21
    cout << count_consonants("ABCdefGHIjklMNOpqrSTUvwxYZ") << endl; // 21
    return 0;
}