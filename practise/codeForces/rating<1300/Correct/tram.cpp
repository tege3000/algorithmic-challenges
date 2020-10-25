#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a, b;
    int size = 0;
    int prev = 0;
    int maxSize = 0;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        size = (prev - a) + b;
        prev = size;
        
        maxSize = max(size, maxSize);
    }
    
    cout << maxSize << "\n";
}
