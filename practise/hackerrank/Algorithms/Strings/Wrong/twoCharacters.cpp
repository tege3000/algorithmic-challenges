#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    set <char> distinct;
    int n = s.size();
    for(int i = 0 ; i < n; i++) {
        distinct.insert(s[i]);
    }
    
//    for(auto i : distinct) {
//        cout << i <<  " ";
//    }
//    cout << "\n";
    
    vector <char> v;
    
    for(auto i : distinct) {
        v.push_back(i);
    }
    
    vector <vector<char>> outer;
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = i+1; j < v.size(); j++) {
            vector <char> inner;
            inner.push_back(v[i]);
            inner.push_back(v[j]);
            
            outer.push_back(inner);
        }
    }
    
//    for(auto i : outer) {
//        for(auto j : i) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    
    string nS;
    int counter;
    int length = 0;
    
    for(int i = 0; i < outer.size(); i++) {
        nS = s;
        //cout << nS << endl;
        counter = 0;
        for(int j = 0; j < outer.size(); j = counter) {
            if(nS[j] == outer[i][0]) {
                nS.erase(nS.begin()+j);
                counter = j;
            }
            else if(nS[j] == outer[i][1]) {
                nS.erase(nS.begin()+j);
                counter = j;
            }
            else {
                counter++;
            }
            
        }
        
        //cout << nS << endl;
        char first = nS[0];
        char second = nS[1];
        int eCheck = 0;
        int oCheck = 0;
        for(int i = 0; i < nS.size(); i = i+2) {
            if(first == nS[i]) {
                eCheck = 1;

            }
            else {
                eCheck = 0;
                break;
            }
        }
        
        for(int i = 1; i < nS.size(); i = i+2) {
            if(second == nS[i]) {
                oCheck = 1;
            }
            else {
                oCheck = 0;
                break;
            }
        }
        
        if(eCheck == 1 && oCheck == 1){
            //cout << nS << " is valid" << endl;
            if(nS.size() > length) {
                length = nS.size();
            }
        }
    }

    
    return length;
    
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
