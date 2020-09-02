#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the almostSorted function below.
void almostSorted(vector<int> arr) {
    int l, r;
    int isSorted = 0;
    
    if(is_sorted(arr.begin(), arr.end())) {
        cout << "yes" << endl;
        isSorted = 1;
    }
    else {

            
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > arr[i+1]) {
                l = i;
                break;
            }
        }
        
        for(int i = l+1; i < arr.size(); i++) {
            if(arr[i] > arr[i-1]) {
                r = i-1;
                break;
            }
            else {
                r = i;
            }
        }
        
        iter_swap(arr.begin()+l, arr.begin()+r);
        
        if(is_sorted(arr.begin(), arr.end())) {
            cout << "yes" << endl;
            cout << "swap " << l+1 << " " << r+1 << endl;
            isSorted = 1;
        }
        else {
            // swap back to normal form
            iter_swap(arr.begin()+l, arr.begin()+r);
     
            //then reverse
            reverse(arr.begin()+l, arr.begin()+r+1);
            if(is_sorted(arr.begin(), arr.end())) {
                cout << "yes" << endl;
                cout << "reverse " << l+1 << " " << r+1 << endl;
                isSorted = 1;
            }
            
        }
        
        
        if(isSorted == 0) {
            cout << "no" << endl;
        }
    }
    
    
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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
