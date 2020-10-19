#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == s[i+1]) {
            s.erase(s.begin()+(i+1));
            i--;
            count++;
        }
    }
    
    cout << count;
}
