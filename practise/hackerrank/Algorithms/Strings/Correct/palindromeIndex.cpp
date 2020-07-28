#include <bits/stdc++.h>

using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    int left = 0;
    int right = s.size() - 1;
    
    while(left < right) {
        if(s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            break;
        }
    }
    
    // in this case its a palindrome
    if(left >= right) {
        return -1;
    }
    
    
    int ogLeft = left;
    int ogRight = right;
    left++;
    
    while(left < right) {
        if(s[left] == s[right]) {
            left++;
            right--;
        }
        else {
            return ogRight;
        }
    }
    
    return ogLeft;
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

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
