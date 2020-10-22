#include <iostream>
#include <vector>

using namespace std;
int solve(int k, int l, int m, int n, int d) {
    if(k == 1) {
        return d;
    }
    
    vector<int> v;
    for(int i = 0;  i <=d; i++) {
        v.push_back(0);
    }
    
    for(int i = k; i <= d; i = i+k) {
        v.at(i) = 1;
    }
    
    for(int i = l; i <= d; i = i+l) {
        v.at(i) = 1;
    }
    
    for(int i = m; i <= d; i = i + m) {
        v.at(i) = 1;
    }
    
    for(int i = n; i <= d; i = i + n) {
        v.at(i) = 1;
    }
    
    int count = 0;

    for(int i = 1; i <= d; i++) {
        if(v[i] == 0) {
            count++;
        }
    }
    
    return d - count;
}

int main() {
    int k, l, m, n, d;
    
    cin >> k >> l >> m >> n >> d;
    
    cout << solve(k, l, m, n, d) << "\n";
}
