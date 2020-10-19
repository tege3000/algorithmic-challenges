#include <iostream>

using namespace std;
int main() {
    string s;
    
    cin >> s;
    
    int upperCount = 0;
    int lowerCount = 0;
    for(int i = 0; i < s.size(); i++) {
        if(isupper(s[i])) {
            upperCount++;
        }
        else {
            lowerCount++;
        }
    }
    
    if(upperCount > lowerCount) {
        for(int i = 0; i < s.size(); i++) {
            cout << (char)toupper(s[i]);
        }
    }
    else {
        for(int i = 0; i < s.size(); i++) {
            cout << (char)tolower(s[i]);
        }
        
    }
}
