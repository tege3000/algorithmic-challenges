#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr) {
    int count = 1;
    int sum = 0;
    int n = arr.size();
    set <char> s;
    vector <char> v;
    
    for(int i = 0; i < arr[0].size(); i++) {
        s.insert(arr[0][i]);
    }
    
    for(auto i : s) {
        v.push_back(i);
    }
    
    
    for(int i = 1; i < n; i++) {
        set <char> nS;
        vector <char> nV;
        
        for(int k = 0; k < arr[i].size(); k++) {
            nS.insert(arr[i][k]);
        }
        
        for(auto a : nS) {
            nV.push_back(a);
        }
        
        for(int j = 0; j < arr[i].size(); j++) {
            if(find(v.begin(), v.end(), nV[j]) != v.end()) {
                v.push_back(nV[j]);
            }
        }
        
        
    }
    
    sort(v.begin(), v.end());   

    for(int i = 0; i < v.size(); i++) {
       cout << v[i] << " ";
    }
    cout << "\n";
 
    for(int i = 0; i < v.size(); i++) {
        
        if(v[i] == v[i+1]) {
            count++;
            if(count == n) {
                sum++;
            }
        }
        else {
            
            count = 1;
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
