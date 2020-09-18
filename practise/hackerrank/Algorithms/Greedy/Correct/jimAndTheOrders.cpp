#include <iostream>
#include <vector>

using namespace std;

// Complete the jimOrders function below.
vector<int> jimOrders(vector<vector<int>> orders) {
    vector<vector<int>> sums;
    for(int i = 0; i < orders.size(); i++) {
        vector<int> inner;
        inner.push_back(orders[i][0] + orders[i][1]);
        inner.push_back(i+1);
        
        sums.push_back(inner);
    }
    
    sort(sums.begin(), sums.end());
    vector<int> ans;
    
    for(int i = 0; i < sums.size(); i++) {
        ans.push_back(sums[i][1]);
    }
    
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    vector<vector<int>> orders(n);
    for (int i = 0; i < n; i++) {
        orders[i].resize(2);
        
        for (int j = 0; j < 2; j++) {
            cin >> orders[i][j];
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    vector<int> result = jimOrders(orders);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        
        if (i != result.size() - 1) {
            cout << " ";
        }
    }
    
    cout << "\n";
    
    return 0;
}
