#include <iostream>
#include <vector>

using namespace std;

/*
 * Complete the buildPalindrome function below.
 */
bool comp(string left, string right) {
    return left < right;
}

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
    // TODO: NEED TO EXPAND ALGORITHM TP WORK FOR EACH VALUES
    // IN A AND ALSO FOR EACH VALUES IN B
    // BASICALLY, MAKE CODE PASS THIS TEST CASE:
    // 1
    // jdfh
    // fds
    for(int i = 0; i < n; i++) {
        string res;
        for(int j = 0; j < m; j++) {
            res = a[i];
            for(int k = j; k < m; k++) {
                res += b[k];
                cout << res << " ";
                if (isPalindrome(res)) {
                    palindromes.push_back(res);
                }
            }
            cout << "\n";
        }
    }
    
//    sort(palindromes.begin(), palindromes.end(), comp);
    
//    for(auto i : palindromes) {
//        cout << i << " ";
//    }
//    cout << "\n";
    
    return "gabkabjkl";
    
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
