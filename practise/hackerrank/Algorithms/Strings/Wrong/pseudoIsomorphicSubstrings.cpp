#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * Complete the pseudoIsomorphicSubstrings function below.
 */
vector<int> pseudoIsomorphicSubstrings(string s) {
    /*
     * Write your code here.
     */
    vector<int> ans = {0};
    int n = s.size();
    string c;
    for(int i = 0; i < n; i++) {
        c = s.substr(0, i+1);
        set<string> subString;
        for(int j = 0; j < c.size(); j++) {
            string d = "";
            for(int k = j; k < c.size(); k++) {
                d += c[k];
                subString.insert(d);
            }
        }
        
        for(auto i : subString) {
            cout << i << " ";
        }
        cout << "\n\n";
        

    }
    
    return ans;
    
}

int main()
{
    
    string s;
    getline(cin, s);
    
    vector<int> result = pseudoIsomorphicSubstrings(s);
    
    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];
        
        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }
    
    cout << "\n";
    
    
    return 0;
}
