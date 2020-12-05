#include <bits/stdc++.h>

using namespace std;

// Complete the hackerrankInString function below.
string hackerrankInString(string s) {
    string toObtain = "hackerrank";
    string ans;
    string resString;
    
    int count = 0;
    
    //first check if all the letters in hackerrank exist in the string s
    for(int i = 0; i < toObtain.size(); i++) {
        
        if(find(s.begin(), s.end(), toObtain[i]) != s.end()) {
            count++;
        }
    }
    
    if(count != toObtain.size()) {
        ans = "NO";
    }
    else {
        //ans = "YES";

        int stop = 0;
        int j = 0;
        
        for(int i = 0; i < toObtain.size(); i++) {
            
            for(j = stop; j < s.size(); j++) {
                if(toObtain[i] == s[j]) {
                    stop = j+1;
                    cout << toObtain[i] << " found at " << j << endl;
                    resString.push_back(s[j]);
                    break;
                }
            }
        }
        
        
        if(resString == toObtain) {
            ans = "YES";
        }
        else {
            ans = "NO";
        }
        
    }

    return ans;
    
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

        string result = hackerrankInString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
