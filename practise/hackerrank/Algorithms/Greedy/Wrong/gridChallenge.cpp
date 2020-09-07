#include <bits/stdc++.h>

using namespace std;

// Complete the gridChallenge function below.
string gridChallenge(vector<string> grid) {
    int n = grid.size();
    for(int i = 0; i < n; i++) {
        sort(grid[i].begin(), grid[i].end());
    }

    int isSorted = 0;
    for(int i = 0; i < grid[0].size(); i++) {
        for(int j = 0; j < n-1; j++) {
            if(grid[j][i] < grid[j+1][i]) {
                isSorted = 1;
                continue;
            }
            else {
                isSorted = 0;
                break;
            }
        }
    }

    if(isSorted == 0) {
        return "NO";
    }
    return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<string> grid(n);

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(cin, grid_item);

            grid[i] = grid_item;
        }

        string result = gridChallenge(grid);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
