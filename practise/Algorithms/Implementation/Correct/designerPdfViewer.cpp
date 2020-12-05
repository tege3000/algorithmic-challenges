#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    int ans = 0;
    int n = h.size();
    int val = 0;
    vector <int> heights;
    int height = 0;
    char letter;
    for(string::size_type i = 0; i < word.size(); i++) { 
    
        if(word[i] == 'a') {
            val = 0;
        }
        if(word[i] == 'b') {
            val = 1;
        }
        if(word[i] == 'c') {
            val = 2;
        }
        if(word[i] == 'd') {
            val = 3;
        }
        if(word[i] == 'e') {
            val = 4;
        }
        if(word[i] == 'f') {
            val = 5;
        }
        if(word[i] == 'g') {
            val = 6;
        }
        if(word[i] == 'h') {
            val = 7;
        }
        if(word[i] == 'i') {
            val = 8;
        }
        if(word[i] == 'j') {
            val = 9;
        }
        if(word[i] == 'k') {
            val = 10;
        }
        if(word[i] == 'l') {
            val = 11;
        }
        if(word[i] == 'm') {
            val = 12;
        }
        if(word[i] == 'n') {
            val = 13;
        }
        if(word[i] == 'o') {
            val = 14;
        }
        if(word[i] == 'p') {
            val = 15;
        }
        if(word[i] == 'q') {
            val = 16;
        }
        if(word[i] == 'r') {
            val = 17;
        }
        if(word[i] == 's') {
            val = 18;
        }
        if(word[i] == 't') {
            val = 19;
        }
        if(word[i] == 'u') {
            val = 20;
        }
        if(word[i] == 'v') {
            val = 21;
        }
        if(word[i] == 'w') {
            val = 22;
        }
        if(word[i] == 'x') {
            val = 23;
        }
        if(word[i] == 'y') {
            val = 24;
        }
        if(word[i] == 'z') {
            val = 25;
        }
        
        
        for(int j = 0; j < n; j++) {
            if(val == j) {
                heights.push_back(h.at(j));
            }
        }
  
    }
    
    int maxHeight = *max_element(heights.begin(), heights.end());
    //cout << maxHeight << endl;
    
    ans = maxHeight * word.size();
    
    
    
    
    return ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

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
