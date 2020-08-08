#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    //case1: test to see if s contains at least 1 a
    if(!(find(s.begin(), s.end(), 'a') != s.end())) {
        return 0;
    }
    
    //case 2: test to see if s is made up of all a's
    int allAs = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') {
            allAs = 1;
        }
        else {
            allAs = 0;
            break;
        }
    }
    
    if(allAs == 1) {
        return n;
    }

    long repTimes = n/(s.size());
    long rem = n% s.size();
    
    cout << rem <<endl;

    
    string nS = s;
    sort(nS.begin(), nS.end());
    
    
    
    long countOg = 0;
    
    for(int i = 0; i < nS.size(); i++) {
        if(nS[i] == 'a') {
            countOg++;
        }
        else {
            break;
        }
    }
    
    long remCount = 0;
    
    for(int i = 0; i < rem; i++) {
        if(s[i] == 'a') {
            remCount++;
        }
    }
    
    return (countOg * repTimes) + remCount;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
