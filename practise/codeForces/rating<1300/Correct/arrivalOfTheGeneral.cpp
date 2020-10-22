#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    int val;
    cin >> n;
    vector<int> v;
    
    for(int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }
    
    int maxVal = *max_element(v.begin(), v.end());
    int minVal = *min_element(v.begin(), v.end());
    
    int minPos = 0;
    int maxPos = 0;
    for(int i = 0; i < n; i++) {
        if(v[i] == maxVal) {
            maxPos = i;
            break;
        }
    }
    
    
    for(int i = n-1; i >= 0; i--) {
        if(v[i] == minVal) {
            minPos = i;
            break;
        }
    }
    
    if(maxPos > minPos) {
        minPos++;
    }
    cout << maxPos + (n-1) - minPos << "\n";
}
