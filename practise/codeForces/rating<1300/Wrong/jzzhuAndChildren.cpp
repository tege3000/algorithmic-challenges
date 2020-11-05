#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int m;
    cin >> m;
    
    
    int val;
    vector<string> v1;
    for(int i = 0; i < n; i++) {
        cin >> val;
        string s = to_string(val) + to_string(i+1);
        
        v1.push_back(s);
    }
    
    while(v1.size() != 1) {
        if((v1[0][0] - '0') <= m) {
            v1.erase(v1.begin());

        }
        else {
            v1[0] = to_string(((v1[0][0] - '0') - m)) + v1[0][1];
            rotate(v1.begin(), v1.begin()+1, v1.end());
        }

        for(int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << "\n";
        
    }
    
    cout << v1[0][1] << endl;
    
}

