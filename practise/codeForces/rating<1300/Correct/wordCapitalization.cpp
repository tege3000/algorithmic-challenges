#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    string s;
    
    cin >> s;
    
    istringstream iss(s);
    vector<string> words;
    
    for(string w; iss >> w;) {
        words.push_back(w);
    }
    
    for(int i = 0; i < words.size(); i++) {
        words[i][0]  = (char)toupper(words[i][0]);
        cout << words[i] << " ";
    }

}
