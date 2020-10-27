#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string word;
    int len;
    for(int i = 0; i < n; i++) {
        cin >> word;
        len = word.size();
        if(len <= 10) {
            cout << word << "\n";
        }
        else {
            cout << word[0] << word.substr(1, len-2).size() << word[len-1] << "\n";
        }
    }
}
