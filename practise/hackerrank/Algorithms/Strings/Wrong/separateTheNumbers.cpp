#include <iostream>
#include <string>

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
    oldNum = s[0];
    int check = 1;
    for(int i = 1; i < n; i++) {
        num.push_back(s[i]);
        
        if(stoi(num) < stoi(oldNum)) {
            continue;
        }
        else if(stoi(num) > stoi(oldNum)) {
            if(stoi(num) - stoi(oldNum) == 1) {
                //cout << oldNum <<  " " << num << endl;
                oldNum = num;
                check = oldNum.size() -1;
                num = "";
            }
            else {
                check = -1;
                break;
            }
        }
        else {
            oldNum = oldNum + num;
            num = "";
            
            
            
            //check = 0;
        }
        
        
    }

    if(check == -1) {
        cout << "NO" << endl;
    }
    else {
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
