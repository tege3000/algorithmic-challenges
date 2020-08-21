#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int l = s.size();
    int a = floor(sqrt(l));
    int b = ceil(sqrt(l));
    
    cout << a << " " << b << endl;
    
    vector<string> rewritten;
    string t;
    int start = 0;
    for(int i = 0; i < l; i++) {
        t.push_back(s[i]);
        start++;
        if(start == b || i == l-1) {
            start = 0;
            rewritten.push_back(t);
            t= "";
        }
    }
    
    for(int i  = 0; i < rewritten.size(); i++) {
        cout << rewritten[i] << endl;
    }
    
    string res;
    for(int i = 0; i < rewritten[0].size(); i++) {
        for(int j = 0; j < rewritten.size(); j++) {
            res.push_back(rewritten[j][i]);
        }
        
        if(i != rewritten[0].size() - 1) {
            res.push_back(' ');
        }
    }
    
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    
    string result = encryption(s);
    
    cout << result << "\n";
    
    return 0;
}
