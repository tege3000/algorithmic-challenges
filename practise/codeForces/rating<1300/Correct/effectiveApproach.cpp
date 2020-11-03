#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int val;
    unordered_map <int, int> mp;
    
    
    
    for(int i = 0; i < n; i++) {
        cin >> val;
        mp[val] = i+1;
    }
    
    int m;
    cin >> m;
    
    long long countForw = 0;
    long long countBack = 0;
    
    for(int i = 0; i < m; i++) {
        cin >> val;
        
        countForw += mp[val];

        countBack += (n - mp[val] + 1);
    }
    
    cout << countForw << " " << countBack << "\n";
}
