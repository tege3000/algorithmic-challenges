#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    vector <int> og;
    int n = s.size();
    vector <int> diff1;
    vector <int> diff2;
    int diff;
    int count = 0;


    
    for(int i = 0; i < n; i++) {
        og.push_back((int)s[i]);
    }
    
    for(int i = 0; i < n-1; i++) {
        diff = abs(og[i+1] - og[i]);
        diff1.push_back(diff);
    }
    
    
    vector <int> v = og;
    reverse(v.begin(), v.end());
    for(int i = 0; i < n-1; i++) {
        diff = abs(v[i+1] - v[i]);
        diff2.push_back(diff);
    }
    
    
    int m = diff1.size();
    for(int i = 0; i < m; i++) {
        if(diff1[i] == diff2[i]) {
            count++;
        }
    }
    
    //cout << count << endl;
    if(count == m) {
        return "Funny";
    }
    else {
        return "Not Funny";
    }
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
