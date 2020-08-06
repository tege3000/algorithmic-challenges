#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the gridlandMetro function below.
int gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    sort(track.begin(), track.end());
    int count = 0;
    int r,c1,c2;
    int prev = 0;
    // for(int i = 0; i < track.size(); i++) {
    //     r = track[i][0];
    //     c1 = track[i][1];
    //     c2 = track[i][2];
    //     cout << r << " "<< c1 << " "<< c2 <<endl;
    // }
   
    
    for(int i = 0; i < track.size(); i++) {
        r = track[i][0];
        c1 = track[i][1];
        c2 = track[i][2];
        
        if(i == 0){
            count += (c2 - c1) +1;
        }
        else {
            if(r == track[i-1][0] && track[i-1][2] > prev) {
                prev = track[i-1][2];
            }
            
            if(r == track[i-1][0] && c1 <= prev && i != 0) {
                if(c2 > prev) {
                    count += (c2 - c1) +1  - (prev - c1 + 1 ) ;
                }
                else {
                    continue;
                }
            }
            else {
                count += (c2 - c1) +1;
            }
        }
        cout << "count after index " << i << " is  " << count << endl;

        
    }
    cout << count <<endl;

    return (n*m) - count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    vector<vector<int>> track(k);
    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> track[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = gridlandMetro(n, m, k, track);

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
