#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Work on later. Exceeding time limit on test case 3

int solve(int n) {
    int x, y;
    
    int maxX = 0, maxY = 0;
    int minX = INT_MAX, minY = INT_MAX;
    vector<vector<int>> v1;
    
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        maxX = max(maxX, x);
        maxY = max(maxY, y);
        
        minX = min(minX, x);
        minY = min(minY, y);
        
        vector<int> inner;
        inner.push_back(x);
        inner.push_back(y);
        
        v1.push_back(inner);
    }
    
    if(minX < 0) {
        for(int i = 0; i < v1.size(); i++) {
            v1[i][0] += abs(minX);
        }
    }
    
    if(minY < 0) {
        for(int i = 0; i < v1.size(); i++) {
            v1[i][1] += abs(minY);
        }
    }
    
    vector<vector<int>> checkV;
    
    for(int i = 0; i <= (maxY-minY); i++) {
        vector<int> inner;
        for(int j = 0; j <= (maxX-minX); j++) {
            inner.push_back(0);
        }
        checkV.push_back(inner);
    }
    
    for(int i = 0; i < v1.size(); i++) {
        checkV[v1[i][1]][v1[i][0]] = 1;
    }
    
    
    int supercCount = 0;
    for(int i = 1; i < checkV.size()-1; i++) {
        for(int j = 1; j < checkV[i].size()-1; j++) {
            // check horizontally at a point
            int hCount = 0;
            for(int k = 0; k < checkV[i].size(); k++) {
                if(checkV[i][k] == 1) {
                    hCount++;
                }
            }
            
            // check vertically
            int vCount = 0;
            for(int k = 0; k < checkV.size(); k++) {
                if(checkV[k][j] == 1) {
                    vCount++;
                }
            }

            if(vCount >= 3 && hCount >= 3) {
                supercCount++;
            }
        }
    }
    
    return supercCount;
}

int main() {
    int n;
    cin >> n;
    
    cout << solve(n) << endl;
}
