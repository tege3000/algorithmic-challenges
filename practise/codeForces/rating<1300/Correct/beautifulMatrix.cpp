#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5;
    vector<vector<int>> v1;
    for(int i = 0; i < n; i++) {
        vector<int> inner;
        for(int j = 0; j < n; j++) {
            inner.push_back(0);
        }
        v1.push_back(inner);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            v1[i][j] = val;
        }
    }
    
    int x_pos = 0;
    int y_pos = 0;
    int x_middle = 2;
    int y_middle = 2;
    
    for(int i = 0; i < n; i++) {
        if(find(v1[i].begin(), v1[i].end(), 1) != v1[i].end()) {
            x_pos = i;
            y_pos = distance(v1[i].begin(), find(v1[i].begin(), v1[i].end(), 1));
            break;
        }
    }
    
    cout << abs(x_middle-x_pos) + abs(y_middle - y_pos) << endl;
    return 0;
}



