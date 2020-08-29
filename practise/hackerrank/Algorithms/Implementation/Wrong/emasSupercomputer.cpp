#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    vector<int> areas;
    vector<vector<int>> avoidOverlap;
    int count = 0;
    int moveon = 0;
    for(int i = 0; i <= grid.size() - 3; i++) {
        for(int j = 0; j <= grid[0].size()-3; j++) {
            
            if(grid[i][j+1] == 'G' && grid[i+1][j+1] == 'G' && grid[i+2][j+1] == 'G' && grid[i+1][j] == 'G' && grid[i+1][j+1] == 'G' && grid[i+1][j+2] == 'G') {
                if(count <= 0) {
                    areas.push_back(5);
                    
                    vector<int> index1;
                    index1.push_back(i);
                    index1.push_back(j+1);
                    avoidOverlap.push_back(index1);
                    vector<int> index2;
                    index2.push_back(i+2);
                    index2.push_back(j+1);
                    avoidOverlap.push_back(index2);
                    vector<int> index3;
                    index3.push_back(i+1);
                    index3.push_back(j);
                    avoidOverlap.push_back(index3);
                    vector<int> index4;
                    index4.push_back(i+1);
                    index4.push_back(j+2);
                    avoidOverlap.push_back(index4);
                    vector<int> index5;
                    index5.push_back(i+1);
                    index5.push_back(j+1);
                    avoidOverlap.push_back(index5);
                }
                else {
                    
                    for(int a = 0; a < avoidOverlap.size(); a++) {
//                        cout << "current: "<< i  << " " << j+1 << " old: " << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
//                        cout << "current: "<< i+2  << " " << j+1 << " old: " << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
//                        cout << "current: "<< i+1  << " " << j << " old: " << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
//                        cout << "current: "<< i+1  << " " << j+2 << " old: " << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
//                        cout << "current: "<< i+1  << " " << j+1 << " old: " << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
//                        cout << "\n";
                        
                        if((i == avoidOverlap[a][0] && j+1 == avoidOverlap[a][1]) ||
                           (i+2 == avoidOverlap[a][0] && j+1 == avoidOverlap[a][1]) ||
                           (i+1 == avoidOverlap[a][0] && j == avoidOverlap[a][1]) ||
                           (i+1 == avoidOverlap[a][0] && j+2 == avoidOverlap[a][1]) ||
                           (i+1 == avoidOverlap[a][0] && j+1 == avoidOverlap[a][1])) {
                            moveon = 1;
                        }
                    }
                    
                    if(moveon == 1) {
                        moveon = 0;
                        continue;
                    }
                    else {
                        areas.push_back(5);

                    }
                    
                }
                count++;
                
                
            }
            
            
        }
        
    }
    
    if(areas[1] == 0) {
        areas[1] = 1;
    }
    return areas[0] * areas[1];
    
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    int result = twoPluses(grid);

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
