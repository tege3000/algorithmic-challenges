#include <bits/stdc++.h>
#include <math.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {

    int tmp =0;
    
    //sort the array first
    for(int i = 0; i <n; i++) {
        for(int j = i+1; j<n; j++) {
            if(ar.at(i) >ar.at(j)) {
                tmp = ar.at(i);
                ar.at(i) = ar.at(j);
                ar.at(j) = tmp;
            }
        }
    }

    int count =0;
    int pairCountSum = 0;
    int i = 0;

    //loop through array and count how many values are the same
    while (i < n) {
        for(int j= i; j< n; j++) {
            if(ar.at(i) == ar.at(j)) {
                count++;
            }
        }
        pairCountSum += floor(count/2);
        i=i+count; // skip to (i+count)th index to check for other different values

        count=0; // reset the value count
    }
 

    return pairCountSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

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
