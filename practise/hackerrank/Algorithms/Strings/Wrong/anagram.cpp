#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    
    int n = s.size();
    int half = n/2;
    if(!(n%2 == 0)) {
        return -1;
    }
    
    string s1, s2;
    for(int i = 0; i < half; i++) {
        s1.push_back(s[i]);
    }
    
    for(int i = half; i < n; i++) {
        s2.push_back(s[i]);
    }
    
    
    cout << s1 << endl;

    cout << s2 << endl;
    
    set <char> set1;
    

    
    int count = 0;
    for(int i = 0; i < half; i++) {
        set1.insert(s1[i]);
    }
    
    vector <char> v1;
    
    for(auto i : set1) {
        v1.push_back(i);
    }
    
    for (int i = 0; i < v1.size(); i++) {
        if(find(s2.begin(), s2.end(), v1[i]) != s2.end()) {
            count++;
        }
    }
    
    
    return s2.size() - count;

}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        
        int result = anagram(s);
        
        cout << result << "\n";
    }
    
    
    return 0;
}
