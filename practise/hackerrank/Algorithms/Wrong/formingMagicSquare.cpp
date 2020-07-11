#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    int cost = 0;
    int costSum = 0;
    int magicNumber = 15;
    
    // handle the columns
    for(int i = 0; i < s.size(); i++) {
        int rowSum = 0;
        //go through each row, check if sum of values
        //is equal to magicNumber
        for(int j = 0; j < s.size(); j++) {
            rowSum += s[i][j];
        }
        
        cout << "index i: " << i << "has rowSum of " << rowSum << endl;
        // if the rowSum is not equal to the magic number,
        // we want to ensure that that row eventually equals the magic number
        // also we want to make sure that for that row, all the columns that intersect
        // with it have a sum equal to the magic number.
        if(rowSum != magicNumber) {
            //check the columns for that spefic row
            for(int a = 0; a < s.size(); a++) {
                int colSum = 0;
                for(int b = 0; b< s.size(); b++) {
                    colSum += s[b][a];
                
                }
                
                cout << "Under index i " << i << ", index a: " << a << "has colSum of " << colSum << endl;

                if(colSum != magicNumber) {
                    int oldval = s[i][a];
                    s[i][a] = magicNumber - (colSum - oldval);
                    cout << "We changed this " << oldval << " to this " << s[i][a] << endl;
                    cost = abs(s[i][a] - oldval);
                    costSum += cost;
                }
            }
            
            
        }
    }
    
    
    
    cout << "New 3x3 matrix is now: " << endl;
    
    for(auto i : s) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    
    return costSum;
    
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

