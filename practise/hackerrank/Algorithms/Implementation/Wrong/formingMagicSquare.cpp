#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
    // handle duplicate items in vector
    //first of all if matrix is not distinct correct
    vector<int> flattenS;
    
    vector <int> numsNotPresent;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < s.size(); j++) {
            flattenS.push_back(s[i][j]);
        }
    }
    
    cout << "flattenened array: ";
    for(int i = 0; i < flattenS.size(); i++) {
        cout << flattenS[i] << " ";
    }
    cout << "\n";
    
    for(int i = 1; i <= 9; i++) {
        if(!(find(flattenS.begin(), flattenS.end(), i) != flattenS.end())) {
            numsNotPresent.push_back(i);
        }
    }
    
    cout << "Nums not present array: ";
    for(int i = 0; i < numsNotPresent.size(); i++) {
        cout << numsNotPresent[i] << " ";
    }
    cout << "\n";
    
    int index = 0;
    // if we have some missing numbers, then we change those missing numbers
    if(numsNotPresent.size() > 0) {
        for(int i = 0; i < flattenS.size()-1; i++) {
            if(find(flattenS.begin()+(i+1), flattenS.end(), flattenS[i]) != flattenS.end()) {
                flattenS[i] = numsNotPresent[index];
                index++;
            }
        }
    }
    
    // now make s distinct
    index = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = 0; j < s.size(); j++) {
            s[i][j] = flattenS[index];
            index++;
        }
    }
    
    cout << "After setup matrix is now: " << endl;
    
    for(auto i : s) {
        for(auto j: i) {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    
    // Now proceed to solution
    // TODO: COME UP WITH AN ALGORITHM
    
    int costSum = 0;
    
    
    
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

