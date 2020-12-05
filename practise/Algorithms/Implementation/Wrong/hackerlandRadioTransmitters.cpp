#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the hackerlandRadioTransmitters function below.
int hackerlandRadioTransmitters(vector<int> x, int k) {
    sort(x.begin(), x.end());
    int transmitterCount = 0;
    int counter = 0;
    
    int lB = 0;
    int uB = 0;
    int focalPoint = 0;
    int maxValueThatExists = 0;
    int uBIndex = 0;
    int focalPointIndex = 0;
    set <int> distinct;
    
    for (int i : x) {
        distinct.insert(i);
    }
    
    vector <int> y;
    
    for(int i  : distinct) {
        y.push_back(i);
    }
    
    int n = y.size();
    
    
    for(int i = 0; i < n; i= counter) {
    
        
        lB = y.at(i);
        focalPoint = lB +k;
        
        
        uB = focalPoint +k;
     
        
        auto focalExists = find(y.begin(), y.end(), focalPoint);
        auto uBExists = find(y.begin(), y.end(), uB);
        
        
        if(focalExists != y.end() && uBExists != y.end()) {
            uBIndex = distance(y.begin(), uBExists);

            transmitterCount++;
            counter = uBIndex +1;

        }
        else {
            //cout << "here " << endl;
            for(int j = lB; j < focalPoint; j++) {
                auto doesValExist = find(y.begin(), y.end(), j);
                if(doesValExist != y.end()) {
                    maxValueThatExists = j;
                }
            }
            
            focalPoint = maxValueThatExists;
            uB = focalPoint+k;
            auto uBExists = find(y.begin(), y.end(), uB);
            
            if(uBExists != y.end()) {
                uBIndex = distance(y.begin(), uBExists);
                transmitterCount++;

                counter = uBIndex +1;
                
            }
            else {
                for(int k = focalPoint; k < uB; k++) {
                    auto doesValExist = find(y.begin(), y.end(), k);
                    if(doesValExist != y.end()) {
                        maxValueThatExists = k;
                        uBIndex = distance(y.begin(), doesValExist);

                    }
                    
                }
                transmitterCount++;
                counter = uBIndex +1;
                
                
            }
            
            
        }
        
        //cout << i << " ";
        
        
        
    }
    
    
    return transmitterCount;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string x_temp_temp;
    getline(cin, x_temp_temp);

    vector<string> x_temp = split_string(x_temp_temp);

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        int x_item = stoi(x_temp[i]);

        x[i] = x_item;
    }

    int result = hackerlandRadioTransmitters(x, k);

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
