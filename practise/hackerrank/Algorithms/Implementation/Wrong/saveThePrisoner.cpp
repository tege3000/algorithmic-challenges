#include <iostream>
#include <vector>


using namespace std;

vector<string> split_string(string);

// Complete the saveThePrisoner function below.
int saveThePrisoner(int n, int m, int s) {
    //================ 2nd ATTEMPT =================
    //
    //This is my second attempt; which passes more test cases,
    // due to reduction of time complexity to O(1)
    // however the code itself is not entirely correct, 
    // as it produces wrong answers to problems 
    int ans;
    if(m<n) {
        if(s <m) {
            if(abs((s+m)-n) > 1) {
                ans = (n % m)+1;
            }
            else {
                ans = s+m-1;
            }

            
        }
        else if(s==m) {
            if(abs((s+m)-n) > 1) {
                ans = (n % m);
            }
            else {
                ans = s+m-1;
            }
            
        }
        else {
            ans = ((s+m) % s) - 1;
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
                    ans = n-s+1;
                }
            }
            else {
                ans = ((m+s)%n)-1;
            }
        }
        else {
            ans = (m % n) -1;
            if(ans == 0) {
                ans = n;
            }
        }
    }
    
    
    return ans;


    // ================= 1ST ATTEMPT ===================

    // //NOTE: This solution works, however 
    // // its time complexity is bad, hence it fails the 
    // // test cases that have time limits
    // int counter = s;
    
    // for(int i = 1; i < m; i++) {

    //     if(counter%n == 0) {
            
    //         counter = 0;
    //     }
        
    //     counter++;
        
    // }
    
    
    // return counter;
}

int main()
{
    
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
        
        cout << result << "\n";
    }
    
    
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
