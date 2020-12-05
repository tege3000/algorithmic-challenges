#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    
    int case1 = 0;
    int case2 = 0;
    int case3 = 0;
    int case4 = 0;
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    
    int limit = 6;
    
    for(int i = 0; i < n; i++) {
        
        if(find(numbers.begin(), numbers.end(), password[i]) != numbers.end()) {
            case1 = 1;

        }
        if(find(lower_case.begin(), lower_case.end(), password[i]) != lower_case.end()) {
            case2 = 1;
        }
        if(find(upper_case.begin(), upper_case.end(), password[i]) != upper_case.end()) {
            case3 = 1;

        }
        if(find(special_characters.begin(), special_characters.end(), password[i]) != special_characters.end()) {
            case4 = 1;

        }
        
    }
    int res = 0;
    int maxTestCaseCount = 4;
    int testCasesPassed = case1+case2+case3+case4;
    
    
    
  
    if(n >= 6 && testCasesPassed == 4) {
        res = 0;
    }
    else if(n >= 6 && testCasesPassed < 4) {
        res = maxTestCaseCount - testCasesPassed;
    }
    else if(n < 6 && testCasesPassed == 4) {
        res = limit - n;
    }
    //this should be correct
    else if(n < 6 && testCasesPassed < 4) {
        if(limit - n >= 3) {
            res = limit - n;
        }
        else {
            res = maxTestCaseCount - testCasesPassed;
            n = n+res;
            if(n > 6) {
                n = 6;
            }
            n = limit -n;
            res = n+res;
        }
        
    }
    

    
    
    return res;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
