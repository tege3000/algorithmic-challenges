#include <iostream>
#include <vector>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int ans = 0;
    int n = s.size();
    vector<vector<int>> outer;
    
    
    for(int i =0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vector <int> inner;
            inner.push_back(i);
            inner.push_back(j);
            inner.push_back(s.at(i).at(j));
            outer.push_back(inner);
        }
    }
    

    
    vector <int> anotherone;
    int value= 0;
    int replacement = 0;
    int index_i = 0, index_j = 0;
    for(int i = 0; i < outer.size(); i++) {
        
        value = outer.at(i).at(2);
        if(find(anotherone.begin(), anotherone.end(),value)!=anotherone.end()) {
            index_i = outer.at(i).at(0);
            index_j = outer.at(i).at(1);
            
            // check sum of diagonals == 15
            // check sum of rows == 15
            // check sum of columns == 15
            
            for(int a = 0; a < n; a++) {
                for(int b = 0; b < n; b++) {
                    
                }
            }
            
            
            // after finiding the replacement value 
            s.at(index_i).at(index_j) = replacement;
            
            
            
        }
        else {
            anotherone.push_back(value);
        }
    }
    
 
    
    return ans;
    
}

int main()
{
    
    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);
        
        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    int result = formingMagicSquare(s);
    
    cout << result << "\n";
    
    
    return 0;
}

