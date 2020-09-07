#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int max = 0;
    int n = contests.size();
    
    
    vector<vector<int>> tmp;
    
    for(int i = 0; i < contests.size(); i++) {
        vector<int> inner;
        for(int j = 0; j < contests[i].size(); j++) {
            inner.push_back(contests[i][j]);
        }
        tmp.push_back(inner);
    }
    int count = 0;
    vector<int> minIndex;
    for(int i = 0; i < n; i++) {
        if(contests[i][1] == 1) {
            count++;
        }
    }
    
    int allowedToWin = count-k;
    
    
    for(int i = 0; i < allowedToWin; i++) {
        int minI = 0;
        int minEl = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(contests[i][1] == 1) {
                if(contests[i][0] < minEl) {
                    minEl = contests[i][0];
                    minI = i;
                }
            }
            
        }
        minIndex.push_back(minI);
        contests[minI][0] = INT_MAX;
    }
    
//    for(int i = 0; i < minIndex.size(); i++) {
//        cout << minIndex[i] << " ";
//    }
//    cout << "\n";
    for(int i = 0; i < tmp.size(); i++) {
        if(find(minIndex.begin(), minIndex.end(), i) == minIndex.end()) {
//            cout << tmp[i][0] << " ";

            max += tmp[i][0];
        }
    }
    cout << "\n";
    
    for(int i = 0; i < minIndex.size(); i++) {
        max -= tmp[minIndex[i]][0];
    }
    
    return max;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

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
