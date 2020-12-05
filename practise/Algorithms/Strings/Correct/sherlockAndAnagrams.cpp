#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int n = s.size();
    vector <vector<string>> outer;
    
    // get all substrings of s
    for (int len = 1; len <= n; len++){
        //cout << "For len = " << len << ", n-len is " << n-len << endl;
        vector <string> v1;

        for (int i = 0; i <= n - len; i++){
            string sub;
            int j = i + len - 1;
            //cout << "j is " << j << endl;
            for (int k = i; k <= j; k++) {
              
                //cout << s[k];
                sub.push_back(s[k]);
            }
            
            v1.push_back(sub);
            
            //cout << endl;
        }
        
        outer.push_back(v1);
        
    }
    
    
    for(int i = 0; i < outer.size(); i++) {
        sort(outer[i].begin(), outer[i].end());
    }

    for(int i = 0; i < outer.size(); i++) {
        for(int j = 0; j < outer[i].size(); j++) {
            sort(outer[i][j].begin(), outer[i][j].end());
            
            
        }
    }
    
    for(int i = 0; i < outer.size(); i++) {
        for(int j = 0; j < outer[i].size(); j++) {

            cout << outer[i][j] << " " ;

        }
        cout << "\n";
    }

    int count = 0;

  
    for(int i = 0; i < outer.size(); i++) {
        for(int j = 0; j < outer[i].size(); j++) {
            //cout << outer[i][j] << endl;
            for(int a = j+1; a < outer[i].size(); a++) {
                //cout << outer[i][a] << " " ;
                if(outer[i][j] == outer[i][a]) {
                    
                    count++;
                }
            }
            
            //cout << "\ncount was " << count << "\n";
        }
    }

    
    return count;
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

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
