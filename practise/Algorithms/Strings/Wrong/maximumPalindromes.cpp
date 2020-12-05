#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'initialize' function below.
 *
 * The function accepts STRING s as parameter.
 */

void initialize(string s) {
    // This function is called once before all queries.

}

int fac(int val) {
    if(val <= 1) {
        return 1;
    }
    
    return val * fac(val-1);
}

/*
 * Complete the 'answerQuery' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER l
 *  2. INTEGER r
 */

int answerQuery(int l, int r, string s) {
    // Return the answer for this query modulo 1000000007.
    int ans = 0;
    string str = s.substr(l-1, (r-1)-(l-1) +1);
//    cout << str << endl;
    
    unordered_map <char, int> mp;
    
    for(int i = 0; i < str.size(); i++) {
        mp[str[i]]++;
    }
    
    int foundLenOf1 = 0;
    int count = 0;

    for(auto i : mp) {
        if(i.second == 1) {
            ans++;
            foundLenOf1 = 1;
        }
        else if(i.second > 1 && i.second %2 == 0) {
            count++;
        }
    }
    
    ans *= fac(count);
    
    if(foundLenOf1 == 0) {
        ans = mp.size();
    }
    else {
        //further processing
        if(!((str.size() - ans) % 2 == 0)) {
            ans++;
        }
    }
    
    return ans % 1000000007;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    initialize(s);

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int l = stoi(first_multiple_input[0]);

        int r = stoi(first_multiple_input[1]);

        int result = answerQuery(l, r, s);

        fout << result << "\n";
    }

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
