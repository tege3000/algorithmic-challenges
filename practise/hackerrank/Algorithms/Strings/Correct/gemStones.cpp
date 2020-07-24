#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int sum = 0;
    string s;
    int count;
    
    for(char c = 'a'; c <= 'z'; c++) {
        count = 0;
        for(int i = 0; i < arr.size(); i++) {
            s = arr[i];
            if(find(s.begin(), s.end(), c) != s.end()) {
                count++;
            }
        }
        
        if(count == arr.size()) {
            sum++;
        }
    }
    
    return sum;
    
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
