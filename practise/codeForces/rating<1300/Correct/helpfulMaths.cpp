#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string in;
    cin >> in;
    string newS;
    
    for(int i = 0; i < in.size(); i++) {
        if(in[i] != '+') {
            newS.push_back(in[i]);
        }
    }
    
    sort(newS.begin(), newS.end());
    
    string newerS;
    
    for(int i = 0; i < newS.size(); i++) {
        newerS.push_back(newS[i]);
        if(i != newS.size()-1) {
            newerS.push_back('+');
        }
    }
    
    cout << newerS <<  "\n";
}
