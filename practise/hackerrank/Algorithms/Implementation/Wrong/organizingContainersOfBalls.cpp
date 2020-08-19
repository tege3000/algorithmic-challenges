#include <iostream>
#include <vector>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    
    int sum = 0, isPossible = 1, occurrenceCountRows = 0, occurrenceCountCols = 0;
   
    while(isPossible == 1) {
        for(int a = 0; a < n-1; a++) {
            for(int b = 0; b < n; b++) {
                if(container[a][b] == 0) {
                    continue;
                }
                
                for(int k = 0; k < n; k++) {
                    if(container[a][b] == 0) {
                        break;
                    }
                    
                    if(container[a+1][k] == 0 || b == k) {
                        continue;
                    }
                    
                
                    //cout << container[a][b] << " " << container[a+1][k] << endl;
                    container[a+1][b] += container[a][b];
                    container[a][k] += container[a+1][k];
                    
                    container[a+1][k] = 0;
                    container[a][b] = 0;
                    
                  
//                    // display the vector of containers
//                    for(int i = 0; i < n; i++) {
//                        for(int j = 0; j < n; j++) {
//                            cout << container[i][j] << " ";
//                        }
//                        cout << "\n";
//                    }
//                    cout << "\n";
                    
                    
                }
            }
        }
        
        // then we check if the balls in the containers can be organized
        occurrenceCountRows = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(container[i][j] != 0) {
                    occurrenceCountRows++;
                }
            }
        }
        
        occurrenceCountCols = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(container[j][i] != 0) {
                    occurrenceCountCols++;
                }
            }
        }
        
        if(occurrenceCountRows == n && occurrenceCountCols == n) {
            return "Possible";
        }
        
        // then we check if it is possible to keep looping
        isPossible = 0;
        
        for(int i = 0; i < n; i++) {
            sum = 0;
            for(int j = 0; j < n; j++) {
                sum += container[i][j];
            }
            
            if(sum % 2 == 0) {
                isPossible = 1;
            }
        }
        //cout << "heheheh" << endl;
        if(isPossible == 0) {
            return "Impossible";
        }
    }
    
    
    
    
    return "Possible";
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);
            
            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        string result = organizingContainers(container);
        
        cout << result << "\n";
    }
    
    return 0;
}
