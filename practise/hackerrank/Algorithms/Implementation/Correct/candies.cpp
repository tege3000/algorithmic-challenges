#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
    
    int weight = 1;
    long sum = 0;
    vector<int> ans;
    ans.push_back(1);
    for(int i = 1; i < n; i++) {
        if(arr.at(i) > arr.at(i-1)) {
            weight++;
        }
        else {
            weight = 1;
            
        }
        
        //sum += weight;
        ans.push_back(weight);
        
        //cout << sum << endl;
    }
    
    
    //int newWeight = 1;
    for(int i = n-2; i >= 0; i--) {
        
        if((arr.at(i) > arr.at(i+1)) && (ans.at(i) <= ans.at(i+1))) {
            ans.at(i) = ans.at(i+1) + 1;
            cout << "entered";
        }
        
    }
    
    
    
    for(auto i : ans) {
        sum += i;
    }
    
    
    return sum;
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
