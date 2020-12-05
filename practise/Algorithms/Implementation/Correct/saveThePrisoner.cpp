#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {
    int ans;
    if(m<n) {
        if(s <m) {
            if((n+s)%m < 2) {
                if(!((n+s)%m == 0)) {
                    ans = n;
                }
                else {
                    ans = m+s-1;
                }
            }
            else {
                ans = ((m+s)%n)-1;
                if(ans <= 0) {
                    ans = n - abs(ans);
                }
            }

            
        }
        else if(s==m) {
            cout << "test " << (n+s)%m << endl;
            if((n+s)%m < 2) {
                if(abs((s+m)-n) <= 1) {
                    ans = m+s-1;
                }
                if(abs((s+m)-n) == 2) {
                    ans = ((m+s)%n);
                }
                else {
                    ans = ((m+s)%n)-1;
                }
            
        
            }
            else {
                ans = ((m+s)%n)-1;
            }
            
            
        }
        // s > m
        else {
            
            if((n+s)%m < 2) {
                if(!((n+s)%m == 0)) {
                    ans = n;
                }
                else {
                    ans = m+s-1;
                }
            }
            else {
                ans = ((m+s)%n)-1;
            }
           
        }
    }
    else if(m == n) {
        if(abs((s+m)-n) > 1) {
            ans = (n%m) + (s-1);
        }
        else {
            ans = s+m-1;
        }
        
        
    }
    else {
        
        if(n >s) {

            if((m+s)%n < 2) {
                if(!((m+s)%n == 0)) {
                    ans = n;
                }
                else {
                    ans = n-1;
                }
            }
            else {
                ans = ((m+s)%n)-1;
            }
        }
        else {
            //special case
            if(n == 1 && s == 1) {
                ans = n;
            }
            else {
                cout << " m%n " << m%n  << endl;
                if((m % n) == 1) {
                    ans = n;
                }
                else if((m % n) == 0) {
                    ans = n-1;
                }
                else {
                    ans = (m % n) - 1;
                }
            }
            
        }
    }
    
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nms_temp;
        getline(cin, nms_temp);

        vector<string> nms = split_string(nms_temp);

        int n = stoi(nms[0]);

        int m = stoi(nms[1]);

        int s = stoi(nms[2]);

        int result = saveThePrisoner(n, m, s);

        fout << result << "\n";
    }

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
