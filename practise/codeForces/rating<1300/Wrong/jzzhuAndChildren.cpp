#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    unordered_map<int, int> mp;
    
    int val;
    vector<int> v1;
    for(int i = 0; i < n; i++) {
        cin >> val;
        
        mp[val] = i+1;
        v1.push_back(val);
    }
    
    int lastPos = 0;
    while(v1.size() != 0) {
        if(v1[0] <= m) {
            lastPos = mp[v1[0]];
            v1.erase(v1.begin());
        }
        else {
            v1[0] -= m;
            rotate(v1.begin(), v1.begin()+1, v1.end());
        }
        
        for(int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << "\n";
        
    }
    
    cout << lastPos << endl;

}

