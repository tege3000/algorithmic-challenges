#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {

    // NOTE:
    // The question is simply asking for the number
    // of unique characters in a given string.
    set <char> set1;
    for(int i = 0; i < s.size(); i++) {
        set1.insert(s[i]);
    }
    
    return set1.size();
    
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
