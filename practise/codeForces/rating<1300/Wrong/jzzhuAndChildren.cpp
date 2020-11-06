#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
 * TODO: Stuck on test case 32
 * 
 * Test: #32, time: 15 ms., memory: 0 KB, exit code: 0, checker exit code: 1, verdict: WRONG_ANSWER
 * Input
 * 1 1
 * 100
 * Output
 * 91
 * Answer
 * 1
 */
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
//        cout << s << " ";
    }
    
    string num, index;
    
    while(v1.size() != 0) {
        num = "";
        index = "";
        for(int i= 0; i < floor(v1[0].size()/2); i++) {
            num.push_back(v1[0][i]);
        }
        
        int allZeros = 0;
        for(int i = floor(v1[0].size()/2); i < v1[0].size(); i++) {
            index.push_back(v1[0][i]);
            if(v1[0][i] != '0') {
                allZeros = 1;
            }
        }
        
        if(allZeros == 0) {
            index.insert(index.begin(), num[num.size()-1]);
            num.pop_back();
        }
        
        if(index[0] == '0') {
            num.push_back('0');
            index.erase(index.begin());
        }
        
//        cout << "num " << num << endl;
//        cout << "index " << index << endl;
        
        if(stoi(num) <= m) {
            v1.erase(v1.begin());
        }
        else {
            v1[0] = to_string(((stoi(num)) - m)) + index;
            rotate(v1.begin(), v1.begin()+1, v1.end());
        }
        
//        for(int i = 0; i < v1.size(); i++) {
//            cout << v1[i] << " ";
//        }
//        cout << "\n";
        
    }
    
    cout << index << endl;
    
}

