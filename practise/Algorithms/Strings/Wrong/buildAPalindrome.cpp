#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the buildPalindrome function below.
 */
bool isPalindrome(string s) {
    string original = s;
    reverse(s.begin(), s.end());
    if(s == original) {
        return true;
    }
    
    return false;
}
string buildPalindrome(string a, string b) {
    /*
     * Write your code here.
     */
    int n = a.size();
    int m = b.size();
    vector <string> palindromes;
    
    for(int index  = 0; index < n; index++) {
        string next = "";
        for(int i = index; i < n; i++) {
            string res;
            for(int j = 0; j < m; j++) {
                res = next + a[i];
                for(int k = j; k < m; k++) {
                    res += b[k];
//                    cout << res << " ";
                    if (isPalindrome(res)) {
                        palindromes.push_back(res);
                    }
                }
//                cout << "\n";
            }
            
            next.push_back(a[i]);
        }
    }
    
    if(palindromes.size() == 0) {
        return "-1";
    }
    
    sort(palindromes.begin(), palindromes.end());
    int maxLen = 0;
    string resString;
    for(auto i : palindromes) {
        if(i.size() > maxLen) {
            maxLen = i.size();
            resString = i;
        }
//        cout << i << " ";
    }
    
    return resString;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string a;
        getline(cin, a);
        
        string b;
        getline(cin, b);
        
        string result = buildPalindrome(a, b);
        
        cout << result << "\n";
    }
    
    return 0;
}
