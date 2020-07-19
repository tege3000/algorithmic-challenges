#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    
    string ans;
    int n = s.size();
    
    string ogLower = "abcdefghijklmnopqrstuvwxyz";
    string ogHigher = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    
    // shift alphabets by k
     // shift alphabets by k
    if(k > 26) {
        std::rotate(lower_case.begin(), lower_case.begin()+(k-26), lower_case.end());
        std::rotate(upper_case.begin(), upper_case.begin()+(k-26), upper_case.end());
    }
    else {
        std::rotate(lower_case.begin(), lower_case.begin()+k, lower_case.end());
        std::rotate(upper_case.begin(), upper_case.begin()+k, upper_case.end());
    }

    
    
    cout << lower_case << endl;
    cout << upper_case << endl;
    
    int index = 0;

    for(int i = 0; i < n; i++) {
     
        if(find(ogLower.begin(), ogLower.end(), s[i]) != ogLower.end()) {
            index = ogLower.find(s[i]);
            ans.push_back(lower_case[index]);
        }
        else if(find(ogHigher.begin(), ogHigher.end(), s[i]) != ogHigher.end()) {
            index = ogHigher.find(s[i]);
            ans.push_back(upper_case[index]);
        }
        else {
            ans.push_back(s[i]);
        }
    }
    
    return ans;
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
