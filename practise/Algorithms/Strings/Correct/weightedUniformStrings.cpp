#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    vector <string> ans;
    int sum = 0;
    int w = 0;
    vector <int> weights;
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    
    std::size_t pos;
    
    for(int i = 0; i < s.size(); i++){
        pos = alphabets.find(s[i]);
        w = pos + 1;
        
        sum += w;
        weights.push_back(sum);
        
        if(s[i] != s[i+1]) {
            sum = 0;
        }
        
    }
    
    for(int i = 0; i < queries.size(); i++) {
        if(find(weights.begin(), weights.end(), queries[i]) != weights.end()) {
            ans.push_back("Yes");
        }
        else{
            ans.push_back("No");
        }
    }
    
    return ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
