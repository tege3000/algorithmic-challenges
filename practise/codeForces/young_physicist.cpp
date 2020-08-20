#include <iostream>
#include <vector>

using namespace std;


int main()
{
    int n;
    cin >> n;
    int x, y, z;
    int sum_x =  0, sum_y = 0, sum_z = 0;
    
    vector<vector<int>> v;
    
    
    for(int i = 0; i < n; i++) {
        vector<int> innerV;
        scanf("%d %d %d", &x, &y, &z);
        innerV.push_back(x);
        innerV.push_back(y);
        innerV.push_back(z);
        
        
        v.push_back(innerV);
    }
    
    
    for(int i = 0; i < n; i++) {
        sum_x += v[i][0];
        sum_y += v[i][1];
        sum_z += v[i][2];
    }
    
    
    if(sum_x == 0 && sum_y == 0 && sum_z == 0) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}
