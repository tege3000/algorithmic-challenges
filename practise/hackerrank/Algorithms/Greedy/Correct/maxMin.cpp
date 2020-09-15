#include <bits/stdc++.h>

using namespace std;

// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int n = arr.size();
    int unfairness = 0;
    int minUnfairness = INT_MAX;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n-(k-1); i++) {
        unfairness = arr[(k-1)+i] - arr[i];
        cout << arr[(k-1)+i] << " - " << arr[i] << " is " << unfairness << endl;
        minUnfairness = min(unfairness, minUnfairness);
    }
    
    return minUnfairness;
    
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
