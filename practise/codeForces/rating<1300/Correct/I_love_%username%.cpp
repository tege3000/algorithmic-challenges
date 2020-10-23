#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    int val;
    int ans = -2;
    for(int i = 0; i < n; i++) {
        cin >> val;
        if(val > maxVal) {
            maxVal = val;
            ans++;
        }
        
        if(val < minVal) {
            minVal = val;
            ans++;
        }
    }
    
    cout << ans;
}
