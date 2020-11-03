#include <iostream>
using namespace std;

int main() {
    string a, b;
    
    cin >> a;
    cin >> b;
    
    string x, y;
    
    for(int i = 0; i < a.size(); i++) {
        x.push_back(tolower(a[i]));
    }
    
    for(int i = 0; i < a.size(); i++) {
        y.push_back(tolower(b[i]));
    }
   
    if(x == y) {
        cout << 0 << "\n";
    }
    else if(x < y) {
        cout << -1 << "\n";
    }
    else {
        cout << 1 << "\n";
    }
}
