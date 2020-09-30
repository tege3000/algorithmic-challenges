#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the countSubstrings function below.
 */

vector<int> countSubstrings(string s, vector<vector<int>> queries) {
    /*
     * Write your code here.
     */
    
    vector<int> ans;
    for(int i = 0; i < queries.size(); i++) {
        vector <string> distinct;
        int l = queries[i][0];
        int r = queries[i][1];
        
        string c;
        int size = (r-l)+1;
        for(int j = size; j > 0; j--){
            //            cout << "************************" << endl;
            for(int k = l; k <= r; k++) {
                string res = "";
                
                for(int z = 0; z < size - (j-1); z++) {
                    c = s[k+z];
                    res += c;
                }
                //                cout << res <<  "\n";
                
                distinct.push_back(res);
                
                
            }
        }
        
        //        cout << "complete" << endl;
        
        //TODO: (NEXT STEP) FIND THE DUPLICATE STRINGS IN DISTINCT, AND REMOVE THEM
        // THEN CONTINUE SOLVING QUESTION
        
        for(auto i : distinct) {
            cout << i << " ";
        }
        cout << "\n";
        ans.push_back(distinct.size());
        
    }
    
    return ans;
}

int main()
{
    string nq_temp;
    getline(cin, nq_temp);
    
    vector<string> nq = split_string(nq_temp);
    
    int n = stoi(nq[0]);
    
    int q = stoi(nq[1]);
    
    string s;
    getline(cin, s);
    
    vector<vector<int>> queries(q);
    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr].resize(2);
        
        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    vector<int> result = countSubstrings(s, queries);
    
    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];
        
        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }
    
    cout << "\n";
    
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
