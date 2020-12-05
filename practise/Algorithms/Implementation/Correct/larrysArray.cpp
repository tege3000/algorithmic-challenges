#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> A) {
    int n = A.size();
    int next = 0;
    int minPos = 0;
    int k = 3;
    while(!(is_sorted(A.begin(), A.end()))) {
        auto minEl = min_element(A.begin()+next, A.end());
        minPos = distance(A.begin(), minEl);
        
        if(minPos - (k-1) < next) {
            if(*minEl != A[next]) {
                if(*minEl > A[minPos-(k-1)] && minPos == n-1) {
                    return "NO";
                }

                rotate(A.begin()+(minPos-1), A.begin()+(minPos-1)+(k-1), A.begin()+(minPos+(k-1)));
                
            }
            

        }
        else {
            if(*minEl > A[minPos- (k-1)]) {
                return "NO";
            }

            rotate(A.begin()+(minPos-(k-1)), A.begin()+(minPos-(k-1))+(k-1), A.begin()+(minPos+1));      
        }
        
        if(A[next] == *minEl) {
            next++;
        }
        
        if(next == n-1) {            
            return "NO";
        }
        
    }
    
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

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
