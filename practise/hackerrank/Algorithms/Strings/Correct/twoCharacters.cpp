#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    set <char> distinct;
    
    for(int i = 0; i < s.size(); i++) {
        distinct.insert(s[i]);
    }
    
    vector<vector<char>> arrangements;
    vector<char> newV;

    for(auto i : distinct) {
        newV.push_back(i);
    }
    
    for(int i = 0; i < newV.size(); i++) {
        for(int j = i+1 ; j < newV.size(); j++) {
            vector <char> inner;
            inner.push_back(newV[i]);
            inner.push_back(newV[j]);
            
            arrangements.push_back(inner);

        }
    }
    
    string tmp;
    int isAlt = 0;
    int maxLength = 0;
    for(int i = 0; i < arrangements.size(); i++) {
//        cout << arrangements[i][0] << " " << arrangements[i][1] << "\n";
        
        isAlt = 0;
        tmp = s;
        
        for(int j = 0; j < tmp.size(); j++) {
            if(tmp[j] == arrangements[i][0] || tmp[j] == arrangements[i][1]) {
                continue;
            }
            else {
                tmp.erase(tmp.begin()+j);
                j--;
            }
            
        }
//        cout << tmp << endl;
        
        int len = tmp.size();
        // check if alternating.
        for(int j = 0; j < len-1; j++) {
            if(tmp[j] != tmp[j+1]) {
                isAlt = 1;
            }
            else {
                isAlt = 0;
                break;
            }
        }
        
        if(isAlt == 1) {
            maxLength = max(len, maxLength);
        }
    }
    
    
    return maxLength;
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
