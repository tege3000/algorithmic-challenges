#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    int counter = 0;
    
    for(int i = 0; i < s.size(); i= counter) {
        for(int j = i; j < i+1; j++) {
            if(s[j] == s[j+1]) {
                s.erase(s.begin()+i, s.begin()+(i+2));
                if(i == 0) {
                    counter = i;
                }
                else {
                    counter = i-1;

                }
            }
            else {
                counter++;
                break;
            }
        }
        
        //cout << s << endl;
    }
    
    
    if(s == "") {
        return "Empty String";
    }
   
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
