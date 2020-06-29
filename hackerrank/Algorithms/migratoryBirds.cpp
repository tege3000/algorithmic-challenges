#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the migratoryBirds function below.
// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
    int n = arr.size();

    int maxEntry = *max_element(arr.begin(), arr.end());
    vector<vector<int>> v1;

    for(int i = 0; i <= maxEntry; i++) {
        vector<int> v2;
        v2.push_back(i);
        v2.push_back(count(arr.begin(), arr.end(), i));
        v1.push_back(v2);
    }

    int valueCount = 0;
    int best = v1.at(0).at(1);
    int valueBest = 0;
    for(int i = 1; i < v1.size(); i++) {
        if(v1.at(i).at(1) > best) {
            best = v1.at(i).at(1);
            valueBest = v1.at(i).at(0);
        }
        else if (v1.at(i).at(1) == best) {
            if(v1.at(i).at(0) > v1.at(i-1).at(0)) {
                best = v1.at(i-1).at(1);
                valueBest = v1.at(i-1).at(0);
            }
            else {
                best = v1.at(i).at(1);
                valueBest = v1.at(i).at(0);
            }
        }
    }
    cout << endl;

    return valueBest;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
