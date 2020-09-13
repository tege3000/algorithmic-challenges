#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumToys function below.
int getSmallestSubsetLenLessThanK(vector <int> prices, vector <int> subsetsArr, int n, int i, int k) {
    vector<vector<int>> ans;
    int maxLen = 0;
    if(i == n) {
        int size  = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(subsetsArr[i] != 0) {
                sum += subsetsArr[i];
                size++;
            }
        }
        
        if(sum <= k) {
             return size;
        }
    }
    else {
        subsetsArr[i] = 0;
        maxLen = max(getSmallestSubsetLenLessThanK(prices, subsetsArr, n, i+1, k), maxLen);
        
        subsetsArr[i] = prices[i];
        maxLen = max(getSmallestSubsetLenLessThanK(prices, subsetsArr, n, i+1, k), maxLen);
    }
    
    return maxLen;
    
}

int maximumToys(vector<int> prices, int k) {
    int len = 0;
    int n = prices.size();
    vector<int> subsetsArr(n, 0);

    
    len = getSmallestSubsetLenLessThanK(prices, subsetsArr, n, 0, k);

    return len;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

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
