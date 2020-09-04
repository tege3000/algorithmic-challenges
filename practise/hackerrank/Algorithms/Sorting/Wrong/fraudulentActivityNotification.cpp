#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
    int middle = 0;
    float median = 0;
    int end = d;
    int count = 0;
    
    // sort(expenditure.begin(), expenditure.begin()+end);

    for(int i = 0; i+d < expenditure.size(); i++) {
    //    int elToSwap = end-1;
    //    for(int j = end-2; j >= 0; j--) {
    //        if(expenditure[elToSwap] < expenditure[j]) {
    //            swap(expenditure[elToSwap], expenditure[j]);
    //            elToSwap = j;
    //        }
    //    }

        // sort(expenditure.begin()+i, expenditure.begin()+end);

        
        middle = (end+i)/2;
        if(d % 2 == 0) {
            median = (expenditure[middle-1] + expenditure[middle])/2.0;
        }
        else {
            median = expenditure[middle];
        }
        
        for(int j = 0; j < expenditure.size(); j++) {
            cout << expenditure[j] << " ";
        }
        cout << "\n";
        
        cout << expenditure[i+d] << " " << 2*median << endl;
        if(expenditure[i+d] >= 2 * median) {
            count++;
        }
        end++;
    }
    
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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
