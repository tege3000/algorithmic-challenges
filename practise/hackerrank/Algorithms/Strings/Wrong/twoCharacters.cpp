#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// Complete the alternate function below.
int alternate(string s) {
    string newS = s;
    sort(newS.begin(), newS.end());
    cout << newS << endl;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    auto it = find(alphabets.begin(), alphabets.end(), newS[0]);
    int count = 1;

    //vector<vector<char, int>> outer;
    vector <pair<char,int>> outer;
    for(int i  = 1; i < newS.size(); i++) {
        if(newS[i] == *it) {
            count++;
        }
        else {
            
            if(i == newS.size() - 1) {
                //cout << *it <<  " " << count << endl; // print the second to the last one
                outer.push_back(std::make_pair(*it,count));
                
                it = find(alphabets.begin(), alphabets.end(), newS[i]);
                count = 1;
                
                //cout << *it <<  " " << count << endl; // print the last one
                outer.push_back(std::make_pair(*it,count));
            }
            else {
                //cout << *it <<  " " << count << endl;
                outer.push_back(std::make_pair(*it,count));
                
                it = find(alphabets.begin(), alphabets.end(), newS[i]);
                count = 1;
            }
            
        }
    }
    

    int max = 0;
    char firstEl;
    
    
    for (auto i : outer) {
        if(i.second > max) {
            max = i.second;
            firstEl = i.first;
            
        }
        
        cout << i.first << " " << i.second << endl;
    }
    
    cout << max << endl;
    
    int least = max;
    char leastEl;
    
    for (auto i : outer) {
        if(i.second < least) {
            least = i.second;
            leastEl = i.first;
        }
        
    }
    
    
    cout << least << endl;
    
    cout << firstEl << endl;
    cout << leastEl << endl;
    
    cout << s << endl;
    string resS;
    
    for(int i = 0; i < s.size(); i++) {
        //cout << i+1 << ": " << s[i] << endl;
        if(s[i] == firstEl || s[i] == leastEl) {
            //s.erase(s.begin()+i);
            continue;
        }
        else {
            resS.push_back(s[i]);
        }
    }
    
    cout << resS << endl;
    
    return resS.size();
    
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
