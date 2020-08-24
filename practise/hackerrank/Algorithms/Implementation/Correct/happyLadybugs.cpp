#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    // check if all letters are the same
    int allSame = 0;
    for(int i = 0; i < b.size()-1; i++) {
        if(b[i] == b[i+1]) {
            allSame = 1;
        }
        else {
            allSame = 0;
            break;
        }
    }
    
    if(allSame == 1) {
        return "YES";
    }
    
    
    // check if all alphabets
    int allAlphas = 0;
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != '_') {
            allAlphas = 1;
        }
        else {
            allAlphas = 0;
            break;
        }
    }
    
    if(allAlphas == 1) {
        // check if happy
        int newCount = 1;
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == b[i+1]) {
                newCount++;
            }
            else {
                if(newCount <= 1) {
                    return "NO";
                }
                newCount = 1;
            }
        }
        
        
        return "YES";
    }
    
    
    sort(b.begin(), b.end());
    int count = 1;
    // find if the resulting string is happy
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != '_') {
            if(b[i] == b[i+1]) {
                count++;
            }
            else {
                if(count <= 1) {
                    return "NO";
                }
                count = 1;
            }
        }
        
    }
        
        
    return "YES";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string b;
        getline(cin, b);
        
        string result = happyLadybugs(b);
        
        fout << result << "\n";
    }
    
    fout.close();
    
    return 0;
}
