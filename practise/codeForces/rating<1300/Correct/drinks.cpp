#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    int val;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> val;
        
        sum += val;
    }
    
    cout << sum/(n * 1.0) << "\n";
    
}
