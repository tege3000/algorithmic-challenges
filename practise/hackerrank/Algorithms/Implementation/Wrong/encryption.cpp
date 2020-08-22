#include <bits/stdc++.h>

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
    int size  =0;
    if(a*b < l) {
        if(a<b) {
            a = b;
        }
        else {
            b = a;
        }
    }

    for(int i = 0; i < a*b; i++) {
        t.push_back(s[i]);

        start++;
        if(start == b) {
            start = 0;
            rewritten.push_back(t);
            t= "";
        }
    }
    
    
    
    for(int i  = 0; i < rewritten.size(); i++) {
        cout << rewritten[i] << endl;
    }
    
    
    
    string res="";
    for(int i = 0; i < rewritten[0].size(); i++) {
        for(int j = 0; j < rewritten.size(); j++) {
            res.push_back(rewritten[j][i]);

        }
        
        res.push_back(' ');
    }

    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
