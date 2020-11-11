#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

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
    
    vector<vector<int>> checkV;
    
    for(int i = 0; i <= (maxY-minY); i++) {
        vector<int> inner;
        for(int j = 0; j <= (maxX-minX); j++) {
            inner.push_back(0);
        }
        checkV.push_back(inner);
    }
    
    cout << "\n";
    for(int i = 0; i < v1.size(); i++) {
        
        // TODO: Find a way to turn negative numbers in v1 to positive
        // numbers that represent correct positions in checkV
        checkV[v1[i][1]][v1[i][0]] = 1;
    }
    int supercCount = 0;
    for(int i = 1; i < checkV.size()-1; i++) {
        for(int j = 1; j < checkV[i].size()-1; j++) {
            // check vertically at a point
            int vCount = 0;
            for(int k = j; k < checkV[i].size(); k++) {
                vCount++;
            }
            // check horizontally
            int hCount = 0;
            for(int k = i; k < checkV.size(); k++) {
                hCount++;
            }
            
            if(vCount >= 3 && hCount >= 3) {
                supercCount++;
            }
//            cout << checkV[i][j] << " ";
        }
//        cout << "\n";
    }

    return supercCount;
}

int main() {
    int n;
    cin >> n;
    
    cout << solve(n) << endl;
}
