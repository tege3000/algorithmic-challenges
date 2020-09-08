#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulPairs function below.
int beautifulPairs(vector<int> A, vector<int> B) {
    
    vector<vector<int>> BS; // initial beautiful set
    
    for(int i = 0; i < A.size(); i++) {
        
        for(int j = 0; j < A.size(); j++) {
            vector<int> inner;
            if(A[i] == B[j]) {
                inner.push_back(i);
                inner.push_back(j);
                BS.push_back(inner);
            }
        }
    }
    int length = BS.size();
    int el = 0;
    for(int i = 0; i < BS.size()-1; i++) {
        if(BS[i][0] == BS[i+1][0]) {
            for(int j = 0; j < A.size(); j++) {
                if(!(find(B.begin(), B.end(), A[j]) != B.end())) {
                    el = A[j];
                    break;
                }
            }
            
            
            B[BS[i][1]] = el;
            break;
        }
//        cout << BS[i][0] << " " << BS[i][1] << endl;
    }
    
//    for(int i = 0; i < A.size(); i++) {
//        cout << A[i] << " ";
//    }
//    cout << "\n";
//    for(int i = 0; i < A.size(); i++) {
//        cout << B[i] << " ";
//    }
//    cout << "\n";
    
    vector<vector<int>> pairwiseDisjointBS;
    
    for(int i = 0; i < A.size(); i++) {
        
        for(int j = 0; j < A.size(); j++) {
            vector<int> inner;
            if(A[i] == B[j]) {
                inner.push_back(i);
                inner.push_back(j);
                pairwiseDisjointBS.push_back(inner);
            }
        }
    }
    
    
    
    
    return pairwiseDisjointBS.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

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

    string B_temp_temp;
    getline(cin, B_temp_temp);

    vector<string> B_temp = split_string(B_temp_temp);

    vector<int> B(n);

    for (int i = 0; i < n; i++) {
        int B_item = stoi(B_temp[i]);

        B[i] = B_item;
    }

    int result = beautifulPairs(A, B);

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
