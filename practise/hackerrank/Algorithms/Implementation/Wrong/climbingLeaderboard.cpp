#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector <int> ans;
    int n = scores.size();
    int m = alice.size();
    
    set <int> distinctScores;
    for(int i = 0; i < n; i++) {
        distinctScores.insert(scores[i]);
    }
    
    
    int score = 0;
    int prev = *distinctScores.begin();
    
    int next = distinctScores.size() - 1;
    
    
    set<int>::iterator begin = distinctScores.begin();
    int lastIndex = distinctScores.size() - 1;
    advance(begin, lastIndex);

  
    
    
    for(int i = 0; i < m; i++) {
        score = alice[i];
        
        if(score < *distinctScores.begin()) {
            ans.push_back(distinctScores.size() + 1);
        }
        else if(score >= *begin) {
            ans.push_back(1);
        }
        
        else {
            set<int>::iterator start = distinctScores.begin();
           
            for(int j = 1; j <= distinctScores.size()-1; j++) {
                advance(start, 1);
                if(score >= prev && score < *start) {
                    ans.push_back(distinctScores.size() - j +1);
                }
                prev = *start;
            }
        }
        
        prev = *distinctScores.begin();
      
    }
    
    
    
    return ans;
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

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
