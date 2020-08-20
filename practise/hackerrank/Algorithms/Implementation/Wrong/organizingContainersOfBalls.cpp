#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    
    int sumRows = 0, sumColums = 0, isPossible = 0,rowPossible = 0, colPossible = 0, occurrenceCountRows = 0, occurrenceCountCols = 0;
    /*
     * Initially we check if the container is a good container
     *
     * Algorithm used:
     * For a container to be good, it has to have atleast one row
     * AND column that sums to an even value
     */
    for(int i = 0; i < n; i++) {
        sumRows = 0;
        sumColums = 0;
        for(int j = 0; j < n; j++) {
            sumRows += container[i][j];
            sumColums += container[j][i];
            
        }
        
        if(sumRows % 2 == 0) {
            rowPossible = 1;
        }
        
        if(sumColums % 2 == 0) {
            colPossible = 1;
        }
    }
    
    // condition for a good container;
    if(rowPossible == 1 && colPossible == 1) {
        isPossible = 1;
    }
    
    if(isPossible == 0) {
        return "Impossible";
    }
    
    /*
     * If possible => good container
     */
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
        
        
        /*
         * After swapping elements and
         * traversing down the container array,
         * we then check if it is possible to keep looping
         * (if the current container array is good)
         */
        isPossible = 0;
        rowPossible = 0;
        colPossible = 0;
        
        
        for(int i = 0; i < n; i++) {
            sumRows = 0;
            sumColums = 0;
            for(int j = 0; j < n; j++) {
                sumRows += container[i][j];
                sumColums += container[j][i];
                
            }
            
            if(sumRows % 2 == 0) {
                rowPossible = 1;
            }
            
            if(sumColums % 2 == 0) {
                colPossible = 1;
            }
        }
        
        // condition for a good container; it has to have atleast one
        // row or column that sums to an even value
        if(rowPossible == 1 && colPossible == 1) {
            isPossible = 1;
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
    ofstream fout(getenv("OUTPUT_PATH"));

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

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
