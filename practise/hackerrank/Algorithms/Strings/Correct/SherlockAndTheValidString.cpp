#include <bits/stdc++.h>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    set <char> set1;
    
    for(int i = 0; i < s.size(); i++) {
        set1.insert(s[i]);
    }
    
    int count;
    vector< pair<char, int>> v1;
    for(auto i : set1) {
        //cout << i << endl;
        count = 0;
        pair<char, int> p1;
        for(int j = 0; j < s.size(); j++) {
            if(i == s[j]) {
                count++;
            }
        }
        
        p1.first = i;
        p1.second = count;
        v1.push_back(p1);
    }
    
    int charCount = v1[0].second;
    int numDiff = 0;
    
    for(int i = 1; i < v1.size(); i++) {
        if(abs(v1[i].second - charCount) >= 1 ) {
            numDiff++;
        }
        
        //cout << v1[i].first << " " << v1[i].second << endl;
    }
    
    if(numDiff <= 1) {
        return "YES";
    }
    
    return "NO";
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
