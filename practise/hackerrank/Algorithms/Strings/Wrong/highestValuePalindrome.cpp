#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    int count = 0;
    char max = '9';
    //char min = *min_element(s.begin(), s.end());
    int half = (n-1)/2;
    char middleEl = s[half];
    
    if(n <= 1) {
        s = max;
        count++;
        
        if(count <= k) {
            return s;
        }
        else {
            return "-1";
        }
    }
    
    if(k>=n) {
        count += k;
        s="";
        for(int i = 0; i < n; i++) {
            s.push_back('9');
        }
        if(count <= k) {
            return s;
        }
        else {
            return "-1";
        }
        
    }
    
    string s1, s2;
    if(n%2 == 0) {
        s1 = s.substr(0,half+1);
        s2 = s.substr(half+1);
    }
    else {
        s1 = s.substr(0,half);
        s2 = s.substr(half+1);
    }
    
    reverse(s2.begin(), s2.end());
    
    cout << s1 << endl;
    cout << s2 << endl;
    
    if(k >= (s1+s2).size()) {
        for(int i = 0; i < s1.size(); i++) {
            if(s1[i] != '9') {
                s1[i] = '9';
                count++;
            }
            if(s2[i] != '9') {
                s2[i] = '9';
                count++;
            }
        }
        
        if(count == 0 && k > 0) {
            middleEl = '9';
        }
        
        if(n%2 == 0) {
            return s1 + s2;
        }
        else {
            return s1 + middleEl + s2;
        }
        
    }
    
    for(int i = 0; i < s1.size(); i++) {
        if((s1[i] == s2[i]))  {
            if(s1[i] != max && s2[i] != max) {
                if(i != s1.size() -1) {
                    if(s1[i] > s1[i+1] && s2[i] > s2[i+1] && s1[i+1] == s2[i+1]) {
                        s1[i] = max;
                        count++;
                        s2[i] = max;
                        count++;
                    }
                    
                }
            }
            continue;
        }
        else {
            if(s1[i] != max) {
                s1[i] = max;
                count++;
            }
            
            if(s2[i] != max) {
                s2[i] = max;
                count++;
            }
        }
    }
    
    cout << count << endl;
    if(count <= k) {
        reverse(s2.begin(), s2.end());
        if(count == 0 && k > 0) {
            middleEl = '9';
        }
        
        if(n%2 == 0) {
            return s1 + s2;
        }
        else {
            return s1 + middleEl + s2;
        }
        
    }
    
    
    
    return "-1";
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
