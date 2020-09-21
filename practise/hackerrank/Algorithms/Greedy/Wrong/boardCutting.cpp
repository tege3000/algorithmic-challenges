#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the boardCutting function below.
bool comp(vector<int> left, vector<int> right) {
    return left[0] > right[0];
}

int boardCutting(vector<int> cost_y, vector<int> cost_x) {
    vector<vector<int>> cost_y_new;
    vector<vector<int>> cost_x_new;
    
    for(int i = 0; i < cost_y.size(); i++) {
        vector<int> inner;
        inner.push_back(cost_y[i]);
        inner.push_back(i);
        inner.push_back(0); // zero flag to check if its y
        
        cost_y_new.push_back(inner);
    }
    
    for(int i = 0; i < cost_x.size(); i++) {
        vector<int> inner;
        inner.push_back(cost_x[i]);
        inner.push_back(i);
        inner.push_back(1); // 1 flag to check if its x

        
        cost_x_new.push_back(inner);
    }
    
    vector<vector<int>> combined;
    
    for(int i = 0; i < cost_y_new.size(); i++) {
        combined.push_back(cost_y_new[i]);
    }
    
    for(int i = 0; i < cost_x_new.size(); i++) {
        combined.push_back(cost_x_new[i]);
    }
    
    sort(combined.begin(), combined.end(), comp);
    
//    for(auto i : combined) {
//        for(auto j : i) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    
    
    vector<vector<int>> outer;
    int m = cost_y.size()+1;
    int n = cost_x.size()+1;
    
    for(int i = 0; i < m; i++) {
        vector<int> inner;
        for(int j = 0; j < n; j++) {
            inner.push_back(0);
        }
        outer.push_back(inner);
    }
    
//    for(auto i : outer) {
//        for(auto j : i) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    
    
    
    int val = 0 , index = 0, flag = 0;
    int sum = 0;
    int maxEl = 0;
    int countMax = 1;
    for(int i = 0; i < combined.size(); i++) {
        val = combined[i][0];
        index = combined[i][1];
        flag = combined[i][2];
        countMax = 0;

        
        if(flag == 0) {
            for(int j = 0; j < n; j++) {
                outer[index][j]++;
                
                if(outer[index][j] > 1) {
                    countMax++;
                }
              
            }
            
            sum += (val*(1+countMax));
        }
        else {
            for(int j = 0; j < m; j++) {
                outer[j][index]++;
                
                if(outer[j][index] > 1) {
                    countMax++;
                }
            }
            
            sum += (val*(1+countMax));
        }
        
//        for(auto i : outer) {
//            for(auto j : i) {
//                cout << j << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        
    }
    
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string mn_temp;
        getline(cin, mn_temp);

        vector<string> mn = split_string(mn_temp);

        int m = stoi(mn[0]);

        int n = stoi(mn[1]);

        string cost_y_temp_temp;
        getline(cin, cost_y_temp_temp);

        vector<string> cost_y_temp = split_string(cost_y_temp_temp);

        vector<int> cost_y(m-1);

        for (int i = 0; i < m-1; i++) {
            int cost_y_item = stoi(cost_y_temp[i]);

            cost_y[i] = cost_y_item;
        }

        string cost_x_temp_temp;
        getline(cin, cost_x_temp_temp);

        vector<string> cost_x_temp = split_string(cost_x_temp_temp);

        vector<int> cost_x(n-1);

        for (int i = 0; i < n-1; i++) {
            int cost_x_item = stoi(cost_x_temp[i]);

            cost_x[i] = cost_x_item;
        }

        int result = boardCutting(cost_y, cost_x);

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
