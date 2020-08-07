#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int stop = -1;
    int bad, rem;
    for(int i = 0; i < s.size(); i++) {
        if(i <= t.size() - 1) {
            if(s[i] != t[i]) {
                stop = i;
                break;
            }
        }
        else {
            stop = i;
            break;
        }
        
    }
    
    if(s.size() > t.size()) {
        if(stop != -1) {
            bad = s.size() - stop;
            rem = t.size() - stop;
            
            if(bad+rem <= k) {
                return "Yes";
            }
            else {
                return "No";
            }
        }
    }
    else if(t.size() >= s.size()) {
        if(stop != -1) {
            bad = s.size() - stop;
            rem = t.size() - stop;
            
            if(bad+rem <= k) {
                return "Yes";
            }
            else {
                return "No";
            }
        }
        else {
            rem = t.size() - s.size();
            int ops;
            for(int i = 1; i <= s.size(); i++) {
                ops = 2*i;
                if(ops+rem == k) {
                    return "Yes";
                }
                
                if(ops+rem > k) {
                    return "No";
                }
                
            }

            if(ops+rem < k) {
                return "Yes";
            }
        }
    }
    
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
