#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the miniMaxSum function below.
void miniMaxSum(vector<int> arr) {
    int largestNum = 0; // setting it to lowerbound
    long long int smallestSum = 0;
    int largestNumCount = 0;
    int smallestNum = 1000000001; // setting it to upperboud 
    long long int largestSum = 0;
    int smallestNumCount = 0;


    //=================== code for smallest sum =======================
    // find the largest number
    for(int i = 0; i < arr.size(); i++) {
        if(arr.at(i) > largestNum) {
            largestNum = arr.at(i);
        }
    }

    // now if we find the largest num
    // we now check if it has a duplicate in the array
    for(int i = 0; i < arr.size(); i++) {
        if(arr.at(i) == largestNum) {
            largestNumCount++;

            if(largestNumCount > 1) {
                smallestSum += arr.at(i);
            }

        }
    }

    // now we have the largest num... 
    // and we've added duplicates already to the smallest Sum
    for(int i = 0; i < arr.size(); i++) {
       // we now add all the numbers that are smaller than the largest number
        if(arr.at(i) < largestNum) {
            smallestSum +=arr.at(i);
        }
    }

    // =========================================code for the largest sum ========

    // find the smallest number
    for(int i = 0; i < arr.size(); i++) {
        if(arr.at(i) < smallestNum) {
            smallestNum = arr.at(i);
        }
    }

    // now if we find the smallest num
    // we now check if it has a duplicate in the array
    for(int i = 0; i < arr.size(); i++) {
        if(arr.at(i) == smallestNum) {
            smallestNumCount++;

            if(smallestNumCount > 1) {
                largestSum += arr.at(i);
            }

        }
    }

    // now we have the smallest num... 
    // and we've added duplicates already to the largest Sum
    for(int i = 0; i < arr.size(); i++) {
       // we now add all the numbers that are smaller than the largest number
        if(arr.at(i) > smallestNum) {
            largestSum +=arr.at(i);
        }
    }

    cout << smallestSum << " " << largestSum << endl;
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

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
