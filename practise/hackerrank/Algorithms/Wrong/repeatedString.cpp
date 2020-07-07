#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    string newS;
    int stop = 0;
    long count = 0;
    
    
    for(std::string::size_type i = 0; i < n; i++) {
        for(int j = 0; j < s.size(); j++) {
            stop++;
            if(stop <= n) {
                newS.push_back(s[j]);
            }
            
        }
//        cout << stop << endl;
    }
    
//    cout << newS<< endl;
    
    for(std::string::size_type i = 0; i < newS.size(); i++) {
        if(newS[i] == 'a') {
            count++;
        }
    }
    
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
