#include <iostream>


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
    
    
    
    
    
    return res;
    
}

int main()
{
    
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    string password;
    getline(cin, password);
    
    int answer = minimumNumber(n, password);
    
    cout << answer << "\n";
    
    
    return 0;
}
