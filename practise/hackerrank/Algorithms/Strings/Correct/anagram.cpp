#include <bits/stdc++.h>

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
    
    int count = 0;
    int pos = 0;
    for(int i = 0; i < s1.size(); i++) {
        pos = s2.find(s1[i]);
        if(pos == -1) {
            count++;
        }
        else {
            //remove the element found
            s2.erase(s2.begin()+pos);
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
