#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    string lower = "abcdefghijklmnopqrstuvwxyz";
    string nS; // new string that should store s but in all lower case
    int fCount = 0;
    int notFoundCount = 0;

    std::size_t found;
    for(int i = 0; i <s.size(); i++) {
        nS.push_back(tolower(s[i]));
    }
    
    
    for(int i = 0; i < lower.size(); i++) {
        
        found = nS.find(lower[i]);
        
        
        if(found == std::string::npos) {
            notFoundCount++;
        }
    }
    
    
    if(notFoundCount == 0) {
        return "pangram";
    }
    else {
        return "not pangram";
    }
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
