#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the squares function below.
int squares(int a, int b) {
    // NAIVE APPROACH:
    // NOTE: THIS WILL WORK, BUT IT IS NOT OPTIMIZED FOR CASES
    // THE RANGE BETWEEN a AND b IS VERY LARGE
    
    //    int ans = 0;
    //    for(int i = a; i <=b; i++) {
    //        auto val = sqrt(i);
    //        if(val == static_cast<int>(val)) {
    //            ans++;
    //        }
    //    }
    
    
    //OPTIMAL SOLUTION (passed all test cases on hackerrank):
    //
    // EXPLANATION <NOTE TO SELF> (Thanks to @vi123 on hackerank discussion board):
    //
    // Suppose you want to calculate all the square integers between
    // 3 and 14. calculate the square roots of the end points..that
    // will be around 1.73 and 3.74. Now the integers between 1.73 and
    // 3.74 are 2 and 3 which is what we want. To get this we use the
    // ceil function on 1.73 which becomes 2 and we use the floor function
    // on 3.74 which becomes 3. Their difference is 1. We add 1 to the
    // difference because we rounded off 1.73 to 2 and since 2 is an
    // integer we need to consider it also.
    int count = (int)floor(sqrt(b)) - (int)ceil(sqrt(a)) + 1;
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string ab_temp;
        getline(cin, ab_temp);

        vector<string> ab = split_string(ab_temp);

        int a = stoi(ab[0]);

        int b = stoi(ab[1]);

        int result = squares(a, b);

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
