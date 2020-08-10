#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    set <int> distinct;
    vector <int> results;
    int y = pow(2, n-1);
    
    vector <vector<int>> v1;
 
    for(int i = 0; i < y; i++) {
        vector <int> inner;
        for(int j = 0; j < n; j++) {
            inner.push_back(0);
        }
        v1.push_back(inner);
        
    }


    
    
    int val1 = a;
    int val2 = b;
    int counter = 0;
    
    for(int i = 1; i < n; i++) {
        int endHalf1 = 0, endHalf2 = 0;
        int startHalf2 = 0;
        int end = pow(2, i-1);
        
        for(int k = 0; k < end; k++) {
            endHalf1 = endHalf2+ pow(2, n-(i+1));
            for(int j = endHalf2; j < endHalf1; j++) {
                v1[j][i] = val1 + v1[j][i-1];
                startHalf2 = j;
            }

            endHalf2 = startHalf2+1 + pow(2, n-(i+1));

            for(int j = startHalf2+1; j < endHalf2; j++) {
                v1[j][i] = val2 + v1[j][i-1];
                
            }
            
        }
    }
    
    for(int i = 0; i < y; i++) {
        distinct.insert(v1[i][n-1]);
        for(int j = 0; j < n; j++) {
            
            cout << v1[i][j] << " ";
        }
        cout << "\n";
    }
    
    for(auto i : distinct) {
        results.push_back(i);
    }
    
    return results;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int a;
        cin >> a;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int b;
        cin >> b;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = stones(n, a, b);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}
