#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    int n = s.size();
    
    if(n < 2) {
        cout << "NO" << endl;
        return;
    }
    
    if(s[0] == '0') {
        cout << "NO" << endl;
        return;
    }
    
    
    string num;
    string oldNum;
    string og;
    int check = -1;
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        og.push_back(s[i]);
        oldNum = og;

        for(int j = i+1; j < n; j++) {
            num.push_back(s[j]);
            //cout << oldNum << " " << num << endl;
            
            if(num[0] == '0') {
                check = -1;
                break;
            }
            
            
            if(stoll(oldNum) < stoll(num) && stoll(num) - stoll(oldNum) == 1) {
                oldNum = num;
                check = og.size();
                num = ""; //clear num
                
                string rem = s.substr(j+1, n);
                
                count = rem.size() /oldNum.size();
            }
            
        }
        
        num = "";
        if(check != -1) {
            break;
        }
    }
    
    
    if(check == -1) {
        cout << "NO" << endl;
    }
    else {
        if(count == 0) {
            cout << "YES ";
            if(check == 0) {
                cout << s[0];
            }
            else {
                for(int i = 0; i < check; i++) {
                    cout << s[i];
                }
            }
            cout << "\n";
        }
        else {
            cout << "NO" << endl;
        }
       
        
    }
    
    
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
