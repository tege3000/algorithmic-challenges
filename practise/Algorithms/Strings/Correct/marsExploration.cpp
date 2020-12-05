#include <bits/stdc++.h>

using namespace std;

// Complete the marsExploration function below.
int marsExploration(string s) {
    int count = 0;
    int k = 3;
    vector <string> v;
    
    for(int i = 0; i < s.size(); i=i+k) {
        string inner;
        for(int j = i; j < i+k; j++) {
            inner.push_back(s[j]);
        }
        
        v.push_back(inner);
    }
    
    for(int i = 0; i < v.size(); i++) {
        if(v[i][0] != 'S') {
            count++;
        }
        
        if(v[i][1] != 'O') {
            count++;
        }

        if(v[i][2] != 'S') {
            count++;
        }
        
    }
    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
