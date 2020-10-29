#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    string word;
    cin >> word;
    
    if(find(word.begin(), word.end(), 'H') != word.end() ||
       find(word.begin(), word.end(), 'Q') != word.end() ||
       find(word.begin(), word.end(), '9') != word.end()
       ) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
