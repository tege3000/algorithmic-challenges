#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    sort(s.begin(), s.end());
    
    int count = 0;
    int counter = 0;
    vector <int> counts;
    for(int i = 0; i < s.size(); i = counter) {
        count = 0;
        for(int j = i; j < s.size(); j++) {
            if(s[i] == s[j]) {
                //cout << s[j] << endl;
                count++;
                counter = j+1;
            }
            else {
                counter = j;
                break;
            }
        }
        counts.push_back(count);
    }
    
    int isEven = 0;
    int oddCount = 0;
    if(s.size() % 2 == 0) {
        for(auto i : counts) {
            //cout << i << " ";
            if(i%2 == 0) {
                isEven = 1;
            }
            else {
                isEven = 0;
                break;
            }
        }
        
        if(isEven == 1) {
            return "YES";
        }
        else {
            return "NO";
        }
    }
    else {
        for(auto i : counts) {
            //cout << i << " ";
            if(i%2 == 0) {
                isEven = 1;
            }
            else {
                isEven = 0;
                oddCount++;
            }
        }
        
        if(oddCount > 1) {
            return "NO";
        }
        else {
            return "YES";
        }
    }
    
    
    return "NO";
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
