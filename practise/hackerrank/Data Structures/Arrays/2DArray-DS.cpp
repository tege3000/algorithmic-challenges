#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int n = arr.size() - 2;
    int m = arr[0].size() - 2;
    
    int a, b, c, d, e, f, g;
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a = arr[i][j];
            b = arr[i][j+1];
            c = arr[i][j+2];
            d = arr[i+1][j+1];
            e = arr[i+2][j];
            f = arr[i+2][j+1];
            g = arr[i+2][j+2];
                
            sum = a+b+c+d+e+f+g;
            
            maxSum = max(sum, maxSum);

        }
        cout << "\n";
    }
    
    return maxSum;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
