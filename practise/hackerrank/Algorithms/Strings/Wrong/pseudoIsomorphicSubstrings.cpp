#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
 * Complete the pseudoIsomorphicSubstrings function below.
 */

bool comp(string l, string r) {
    if(l.size() == r.size()) {
        return l < r;
    }
    return l.size() < r.size();
}
vector<int> pseudoIsomorphicSubstrings(string s) {
    /*
     * Write your code here.
     */
    vector<int> ans;
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
        
        // CURRENTLY HAVE ALL THE SUBSTRINGS. NEXT STEP IS
        // TO REMOVE THE PSEUDO ISOMORPHIC SUBSTRINGS FROM THE SET
        vector<string> subNew;
        
        for(auto j : subString) {
            subNew.push_back(j);
        }
        
        
        sort(subNew.begin(), subNew.end(), comp);
        int count = subNew.size();
//        cout << "count is  " << count << "\n";
        for(int j = 0; j < subNew.size(); j++) {
//            cout << subNew[j] << " ";
            
            for(int k = j+1; k < subNew.size(); k++) {
                if(subNew[j].size() == subNew[k].size()) {
                    int passCase2And3 = 0;
                    if(subNew[j].size() == 1) {
                        if(subNew[j][0] != subNew[k][0]) {
                            passCase2And3 = 1;
                        }
                    }
                    else {
                        for(int l = 0; l < subNew[j].size(); l++) {
                            for(int m = l+1; m < subNew[j].size(); m++) {
                                if(((subNew[j][l] == subNew[j][m]) && (subNew[k][l] == subNew[k][m]))||((subNew[j][l] != subNew[j][m]) && (subNew[k][l] != subNew[k][m]))) {
//                                    cout << "----------passed-----------" << "\n";
//                                    cout << subNew[j] << " " << subNew[k] << "\n";
                                    passCase2And3 = 1;
                                }
                                else {
//                                    cout << "----------failed-----------" << "\n";
//                                    cout << subNew[j] << " " << subNew[k] << "\n";
                                    passCase2And3 = 0;
                                    break;
                                }
                            }
                            
                            if(passCase2And3 == 0) {
                                break;
                            }
                        }
                    }
                    
                    // if passes the tests then is a pseudo isomorphic sub string, so we delete it
                    if(passCase2And3 == 1) {
//                        cout << "ALL CHARACTERS PASSED SO PSEUDO ISOMORPHIC " << "\n";
//                        cout << subNew[j] << " " << subNew[k] << "\n";
                        count--;
                    }
                }
                else {
                    break;
                }
            }
            
        }
        ans.push_back(count);
        
//        cout << "\n\n";

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
