#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    string ans;
    int count = 0;
    if(s == t) {
        ans = "Yes";
        cout << "yippie";
    }
    else {
        for(int a = 0; a < s.size(); a++) {
            if(t[a] != s[a] || s.size() < t.size()) {

                for(int i = s.size()-1; i >= a; i--) {
                    s.pop_back();
                    count++;
                }
                
                
                for(int k = a; k < t.size(); k++) {
                    s.push_back(t[k]);
                    count++;
                }
                
                
                cout << count << "\n";

                cout << s << endl;
            }
        }
    }
    
    if(count <= k) {
        ans = "Yes";
    }
    else {
        ans = "No";
    }
    
    return ans;
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
