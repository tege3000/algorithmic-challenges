#include <bits/stdc++.h>

using namespace std;

// Complete the makingAnagrams function below.
int makingAnagrams(string s1, string s2) {
    int pos = 0;
    int count = 0;
    int n = s1.size();
    int m = s2.size();
    for(int i = 0; i < s1.size(); i++) {
        pos = s2.find(s1[i]);
        //if found
        if(pos != -1) {
            count++;
            s2[pos] = '0';
        }
    }
    
    int sum1 = n - count;
    int sum2 = m - count;
    
    return sum1+sum2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
