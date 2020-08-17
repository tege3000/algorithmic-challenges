#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Added this as an optimization
    // for this special case
    // but it seems that this case 
    // is not tested on hackerrank
    // if(k == 0 && n%2 == 1) {
    //     if(r_q == c_q && r_q == (1+n)/2) {
    //         return pow(n,2) -1;
    //     }
    // }
    
    vector<vector<int>> chessboard;

    for(int i = 0; i < n; i++) {
        vector<int> inner;
        for(int j = 0; j < n; j++) {
            inner.push_back(0);
        }
        chessboard.push_back(inner);
    }
    
    chessboard[n-r_q][c_q-1]  = 1;
    
    for(int i = 0; i < obstacles.size(); i++) {
        chessboard[n - obstacles[i][0]][obstacles[i][1] - 1] = 2;
    }
    
    int count = 0;
    // for the rows above that queen can move to
    for(int i = n-r_q-1; i >= 0 ; i--) {
        if(chessboard[i][c_q-1] == 2) {
            break;
        }
        else {
            count++;
        }
    }
    
    // for the rows below that queen can move to
    for(int i = n-r_q+1; i < chessboard.size(); i++) {
        if(chessboard[i][c_q-1] == 2) {
            break;
        }
        else {
            count++;
        }
    }
    
    //for the colums to the left that queen can move to
    for(int i = c_q-1-1; i >= 0; i--) {
        if(chessboard[n-r_q][i] == 2) {
            break;
        }
        else {
            count++;
        }
    }
    
    //for the colums to the right that queen can move to
    for(int i = c_q; i < chessboard.size(); i++) {
        if(chessboard[n-r_q][i] == 2) {
            break;
        }
        else {
            count++;
        }
    }
    
    int counter = (c_q-1)-1;
    //for the left diagonals above that queen can move to
    for(int i = n-r_q-1; i >= 0; i--) {
        for(int j = counter; j >= 0; j--) {
            if(chessboard[i][j] == 2) {
                break;
            }
            else {
                count++;
                break;
            }
        }
        
        if(chessboard[i][counter] == 2) {
            break;
        }
        counter--;
    }
    
    counter = (c_q-1)+1;
    //for the right diagonals below that queen can move to
    for(int i = n-r_q+1; i < chessboard.size(); i++) {
        for(int j = counter; j < chessboard.size(); j++) {
            if(chessboard[i][j] == 2) {
                break;
            }
            else {
                count++;
                break;
            }
        }
        if(chessboard[i][counter] == 2) {
            break;
        }
        counter++;
    }
    
    //for the left diagonals below that queen can move to
    counter = (c_q-1)-1;
    for(int i = n-r_q+1; i < chessboard.size(); i++) {
        for(int j = counter; j >= 0; j--) {
            if(chessboard[i][j] == 2) {
                break;
            }
            else {
                count++;
                break;
            }
        }
        if(chessboard[i][counter] == 2) {
            break;
        }
        counter--;
    }
    
    counter = (c_q-1)+1;
    //for the right diagonals above that queen can move to
    for(int i = n-r_q-1; i >=0; i--) {
        for(int j = counter; j < chessboard.size(); j++) {
            if(chessboard[i][j] == 2) {
                break;
            }
            else {
                count++;
                break;
            }
        }
        if(chessboard[i][counter] == 2) {
            break;
        }
        counter++;
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << chessboard[i][j] << " ";
        }
        cout << "\n";
    }
    


    
    return count;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
