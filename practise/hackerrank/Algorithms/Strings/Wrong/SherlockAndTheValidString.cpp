#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Complete the isValid function below.
string isValid(string s) {
    set <char> set1;
    
    for(int i = 0; i < s.size(); i++) {
        set1.insert(s[i]);
    }
    
    int count;
    vector< pair<char, int>> v1;
    for(auto i : set1) {
        //cout << i << endl;
        count = 0;
        pair<char, int> p1;
        for(int j = 0; j < s.size(); j++) {
            if(i == s[j]) {
                count++;
            }
        }
        
        p1.first = i;
        p1.second = count;
        v1.push_back(p1);
    }
    
    
    for(int i = 0; i < v1.size(); i++) {
        cout << v1[i].first << " " << v1[i].second << endl;
    }

    return "NO";
    
    
}

int main()
{
    
    string s;
    getline(cin, s);
    
    string result = isValid(s);
    
    cout << result << "\n";
    
    
    return 0;
}
