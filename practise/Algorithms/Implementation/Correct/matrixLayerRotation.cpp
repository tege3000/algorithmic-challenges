#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {
    // break down into 1d arrays for each layer of matrix
    int n = matrix.size();
    int m = matrix[0].size();
    
    int numLayers = min(m, n) /2;
    vector <vector<int>> outer;
    for(int a = 0; a < numLayers; a++) {
        vector<int> inner;
        
        for(int i = a; i < n-a; i++) {
            inner.push_back(matrix[i][m-(a+1)]);
        }
        
        for(int i = m-(a+2); i >=a; i--) {
            inner.push_back(matrix[n-(a+1)][i]);
        }
        
        for(int i = n-(a+2); i >=a; i--) {
            inner.push_back(matrix[i][a]);
        }
        
        for(int i = a+1; i < m-(a+1); i++) {
            inner.push_back(matrix[a][i]);
        }
        
        
        outer.push_back(inner);
        
    }
    
    //shift arrays for each layer by r
    for(int i = 0; i < outer.size(); i++) {
        //shift each array
        vector<int> shiftedArr;
        for(int j = 0; j < outer[i].size(); j++) {
            shiftedArr.push_back(0);
        }

        for(int j = 0; j < outer[i].size(); j++) {
            shiftedArr[j] = outer[i][(j+r)%(outer[i].size())];
        }
        
        for(int j = 0; j < outer[i].size(); j++) {
            outer[i][j] = shiftedArr[j];
        }
    }
    
    // fill matrix with values for each layer
    for(int a = 0; a < outer.size(); a++) {
        vector<int> inner;
        int index = 0;
        for(int i = a; i < n-a; i++) {
            matrix[i][m-(a+1)] = outer[a][index];
            index++;
        }
        
        for(int i = m-(a+2); i >=a; i--) {
            matrix[n-(a+1)][i] = outer[a][index];
            index++;
        }
        
        for(int i = n-(a+2); i >=a; i--) {
            matrix[i][a] = outer[a][index];
            index++;
        }
        
        for(int i = a+1; i < m-(a+1); i++) {
            matrix[a][i] = outer[a][index];
            index++;
        }
        
    }
    
    
    
    //print matrix
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    
}
int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
