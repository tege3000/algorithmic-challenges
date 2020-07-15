#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    
    string curr;
    string prev;
    string next;
    string up;
    string down;
    
    vector <vector<int>> indices;
    for(int i = 1; i < grid.size() -1; i++) {
        for(int j = 1; j < grid.size() -1; j++) {
            vector <int> inner;
            curr = grid[i][j];
            prev = grid[i][j-1];
            next = grid[i][j+1];
            up = grid[i-1][j];
            down = grid[i+1][j];
            
            if(stoi(curr) > stoi(prev) && stoi(curr) > stoi(next) && stoi(curr) > stoi(up) && stoi(curr) > stoi(down)) {
                inner.push_back(i);
                inner.push_back(j);
                indices.push_back(inner);
            }
            
        }
    }
    
    int first;
    int second;
   
    vector <string> ans;
    for(int a = 0; a < indices.size(); a++) {
        first = indices[a][0]; //i
        second = indices[a][1]; //j
        
        for(int i = 0; i < grid.size(); i++) {
            
            for(int j = 0; j <grid.size(); j++) {
              
                
                if(i == first && j == second) {
                    grid[i][j] = 'X';
                }
            }
        }
    }
    
    
    return grid;
    
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
