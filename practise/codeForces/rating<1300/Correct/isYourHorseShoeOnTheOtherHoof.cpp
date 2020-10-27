#include <iostream>
#include <set>
using namespace std;


int main() {
    int n = 4;
    set <int> s1;
    int val;
    
    for(int i = 0; i < n; i++) {
        cin >> val;
        s1.insert(val);
    }
    
    cout << n - s1.size() << "\n";
    
}
