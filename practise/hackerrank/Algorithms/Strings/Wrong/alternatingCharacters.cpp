#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int counter = 0;
    int delCount = 0;
    for(int i = 0; i < s.size(); i = counter) {
        if(s[i] == s[i+1]) {
            cout << "here" << endl;
            s.erase(s.begin()+(i+1));
            delCount++;
            counter = i;
        }
        else {
            counter++;
        }
        
        if(i == 0 && s.size() == 1) {
            break;
        }
    }
    
    return delCount;
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

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
