#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 3;
    
    vector<vector<int>> v1;
    
    for(int i = 0; i < n; i++) {
        vector<int> inner;
        for(int j = 0; j < n; j++) {
            inner.push_back(1);
        }
        v1.push_back(inner);
    }
    
    vector<vector<int>> input;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            cin >> val;
            
            if(val != 0) {
                v1[i][j] = !(val % 2 == 0) ? (v1[i][j] == 1) ? 0 : 1: v1[i][j];
                int upIndex = i-1;
                int downIndex = i+1;
                int leftIndex = j-1;
                int rightIndex = j+1;
                
                if(upIndex >= 0) {
                    v1[upIndex][j] = !(val % 2 == 0) ? (v1[upIndex][j] == 1) ? 0 : 1 : v1[upIndex][j];

                }
                
                if(downIndex <= n-1) {
                    v1[downIndex][j] = !(val % 2 == 0) ? (v1[downIndex][j] == 1) ? 0 : 1: v1[downIndex][j];

                }
                
                if(leftIndex >= 0) {
                    v1[i][leftIndex] = !(val % 2 == 0) ? (v1[i][leftIndex] == 1) ? 0 : 1: v1[i][leftIndex];

                }
                
                if(rightIndex <= n-1) {
                    v1[i][rightIndex] = !(val % 2 == 0) ? (v1[i][rightIndex] == 1) ? 0 : 1: v1[i][rightIndex];

                }
            }
        }
    }
    
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << v1[i][j];
        }
        cout << "\n";
    }
    
}
