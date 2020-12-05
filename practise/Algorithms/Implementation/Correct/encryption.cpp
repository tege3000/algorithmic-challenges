#include <bits/stdc++.h>

using namespace std;

// Complete the encryption function below.
string encryption(string s) {
    int l = s.size();
    int a = floor(sqrt(l));
    int b = ceil(sqrt(l));
    
    cout << a << " " << b << endl;
    
    int size  =0;
    if(a*b < l) {
        if(a<b) {
            a = b;
        }
        else {
            b = a;
        }
    }
    
    string res;
    int start = 0;
    for(int i = 0; i < b; i++) {
        for(int j = i; j < l; j= start) {
            res.push_back(s[j]);
            start = j+b;
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
