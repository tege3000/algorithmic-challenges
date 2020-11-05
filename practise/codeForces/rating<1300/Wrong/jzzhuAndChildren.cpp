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
        cout << s << " ";
    }
    
    int numSize = (*max_element(v1.begin(), v1.end())).size();
    
    numSize = to_string(n).size();
    
    cout << "\n";
    string num, index;

    while(v1.size() != 0) {
        num = "";
        index = "";
        for(int i= 0; i < numSize; i++) {
            num.push_back(v1[0][i]);
        }
        
        for(int i = numSize; i < v1[0].size(); i++) {
            index.push_back(v1[0][i]);
        }
        
        if(stoi(num) <= m) {
            v1.erase(v1.begin());

        }
        else {
            v1[0] = to_string(((stoi(num)) - m)) + index;
            rotate(v1.begin(), v1.begin()+1, v1.end());
        }

        for(int i = 0; i < v1.size(); i++) {
            cout << v1[i] << " ";
        }
        cout << "\n";
        
    }
    
    cout << index << endl;
    
}

