#include <bits/stdc++.h>

using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) {
    int count = 0;
    string nS = s;
    
    reverse(s.begin(), s.end());
    
    if(nS == s) {
        return 0;
    }
    
    int n = nS.size();
    int half = n/2;
    int end = n-1;
    int diff;
    
    for(int i = 0; i < half; i++) {
        if(nS[i] != nS[end]) {
            diff = abs(nS[i] - nS[end]);
            count += diff;
        }
        
        end--;
    }
    
    return count;
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

        int result = theLoveLetterMystery(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
