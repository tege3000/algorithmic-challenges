#include <iostream>
#include <map>
using namespace std;

string check(string fName, string lName, string scrambled) {
    map<char, int> mp1;
    map<char, int> mp2;
    
    for(int i = 0; i < fName.size(); i++) {
        mp1[fName[i]]++;
    }
    
    for(int i = 0; i < lName.size(); i++) {
        mp1[lName[i]]++;
    }
    
    for(int i = 0; i < scrambled.size(); i++) {
        mp2[scrambled[i]]++;
    }
    
    string input = fName + lName;

    if(input.size() < scrambled.size()) {
        for(auto i : mp2) {
            map<char, int> ::iterator it;
            it = mp1.find(i.first);
            
            if(it != mp1.end()) {
                if(it->second != i.second) {
                    return "NO";
                }
            }
            else {
                return "NO";
            }
        }
    }
    else {
        for(auto i : mp1) {
            map<char, int> ::iterator it;
            it = mp2.find(i.first);
            
            if(it != mp2.end()) {
                if(it->second != i.second) {
                    return "NO";
                }
            }
            else {
                return "NO";
            }
        }
    }
    
    return "YES";
}

int main() {
    string fName;
    string lName;

    cin >> fName >> lName;
    
    string scrambled;
    cin >> scrambled;
    
    cout << check(fName, lName, scrambled) << "\n";
}
