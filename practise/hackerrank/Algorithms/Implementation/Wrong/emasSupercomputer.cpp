#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string);

// Complete the twoPluses function below.
int twoPluses(vector<string> grid) {
    int upCount, rightCount, downCount, leftCount, rowCount, colCount, count;
    int y_start, y_end, x_start, x_end;
    int isOverlap;
    int maxEl;
    vector<int> areas;
    vector<vector<int>> avoidOverlap;
    for(int i = 1; i < grid.size()-1; i++) {
        for(int j = 1; j < grid[0].size()-1; j++) {
            upCount = 0;
            rightCount = 0;
            downCount = 0;
            leftCount = 0;
            rowCount = 0;
            colCount = 0;
            count = 0;
            y_start = 0;
            y_end = 0;
            x_start = 0;
            x_end = 0;
            isOverlap = 0;
            maxEl = 0;
            if(grid[i][j] == 'G' && grid[i+1][j] == 'G' && grid[i-1][j] == 'G' && grid[i][j-1] == 'G' && grid[i][j+1] == 'G') {
                
           
                //move up
                for(int a = i-1; a >= 0; a--) {
                    if(grid[a][j] == 'G') {
                        upCount++;
                    }
                    else {
                        break;
                    }
                }
                
                //move down
                for(int a = i+1; a < grid.size(); a++) {
                    if(grid[a][j] == 'G') {
                        downCount++;
                    }
                    else {
                        break;
                    }
                }
                
                //move left
                for(int a = j-1; a >= 0; a--) {
                    if(grid[i][a] == 'G') {
                        leftCount++;
                    }
                    else {
                        break;
                    }
                }
                
                //move right
                for(int a = j+1; a < grid[0].size(); a++) {
                    if(grid[i][a] == 'G') {
                        rightCount++;
                    }
                    else {
                        break;
                    }
                }
                
                
                //check if any of the points on the cross exist in avoidOverlap array
//                cout << min(upCount, downCount) << endl;
                x_start = j - min(min(leftCount, rightCount), min(upCount, downCount));
                x_end = j+ min(min(leftCount, rightCount), min(upCount, downCount));
                y_start = i - min(min(leftCount, rightCount), min(upCount, downCount));
                y_end = i + min(min(leftCount, rightCount), min(upCount, downCount));
                
                
                for(int a = 0; a < avoidOverlap.size(); a++) {
                    for(int x = x_start; x <= x_end; x++) {
                        if(i == avoidOverlap[a][0] && x == avoidOverlap[a][1]) {
                            isOverlap = 1;
                            break;
                        }
                    }
                    if(isOverlap  == 1) {
                        break;
                    }

                    for(int y = y_start; y <= y_end; y++) {
                        if(y == avoidOverlap[a][0] && j == avoidOverlap[a][1]) {
                            isOverlap = 1;
                            break;
                        }
                    }
                    if(isOverlap  == 1) {
                        break;
                    }

                }
                
                
                rowCount = 2 * min(leftCount, rightCount);
                colCount = 2 * min(upCount, downCount);
                count = 2 * min(rowCount, colCount);
                cout << "============================" << endl;
                cout << "i " << i << "j " << j << endl;
                
                cout << x_start << " " << x_end << endl;
                cout << y_start << " " << y_end << endl;
                
                cout << count+1 << endl;
                int sizeArea = areas.size();
                
                if(sizeArea >= 1) {
                    maxEl = *max_element(areas.begin(), areas.begin()+sizeArea);
                }
                
                if(isOverlap == 0) {
                    
                    cout << "For avoid Overlap " << endl;
                    for(int a = 0; a < avoidOverlap.size(); a++) {
                        cout << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
                    }
                    
                    areas.push_back(count+1);
                    
                    for(int a = x_start; a <= x_end; a++) {
                        vector <int> inner;
                        inner.push_back(i);
                        inner.push_back(a);
                        avoidOverlap.push_back(inner);
                    }

                    for(int a = y_start; a <= y_end; a++) {
                        vector <int> inner;
                        inner.push_back(a);
                        inner.push_back(j);
                        avoidOverlap.push_back(inner);
                    }
                    

                    
                }
                else {
                    // if theres an overlap, we only add it if its currently the highest area
                    if(count+1 > maxEl) {
                        cout << "For avoid Overlap " << endl;
                        for(int a = 0; a < avoidOverlap.size(); a++) {
                            cout << avoidOverlap[a][0] << " " << avoidOverlap[a][1] << endl;
                        }
                        
                        areas.push_back(count+1);
                        
                        for(int a = x_start; a <= x_end; a++) {
                            vector <int> inner;
                            inner.push_back(i);
                            inner.push_back(a);
                            avoidOverlap.push_back(inner);
                        }
                        
                        for(int a = y_start; a <= y_end; a++) {
                            vector <int> inner;
                            inner.push_back(a);
                            inner.push_back(j);
                            avoidOverlap.push_back(inner);
                        }
                    }
                }
                
                
            }
            
        }
      
    }
    
    sort(areas.begin(), areas.end(), greater<int>());
    if(areas[1] == 0) {
        areas[1] = 1;
    }
    return areas[0] * areas[1];
}

int main()
{
    
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
    
    cout << result << "\n";
    
    
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
