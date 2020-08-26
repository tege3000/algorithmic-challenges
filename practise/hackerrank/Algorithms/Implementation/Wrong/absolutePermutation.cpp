#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the absolutePermutation function below.
vector<int> absolutePermutation(int n, int k) {
    vector <int> perms;
    for(int i = 1; i <= n; i++) {
        perms.push_back(i);
    }
    
    // swap first k elements with next k elements and so on
    if(k != 0) {
        for(int i = 0; i < n; i = k*2) {
            
            
            for(int j = 0; j < k; j++) {
                int tmp = perms[j];
                perms[j] = perms[j+k];
                perms[j+k] = tmp;
            }
            
        }
    }
    
    
    for(int i = 0; i < perms.size(); i++) {
        if(abs(perms[i] - (i+1)) == k && perms[i] != 0) {
            continue;
        }
        else {
            vector <int> wrong = {-1};
            return wrong;
        }

    }
  
    return perms;
    
}

int main()
{
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);
        
        vector<string> nk = split_string(nk_temp);
        
        int n = stoi(nk[0]);
        
        int k = stoi(nk[1]);
        
        vector<int> result = absolutePermutation(n, k);
        
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            
            if (i != result.size() - 1) {
                cout << " ";
            }
        }
        
        cout << "\n";
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
