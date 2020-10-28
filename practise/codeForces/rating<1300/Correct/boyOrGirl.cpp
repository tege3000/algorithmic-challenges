#include <iostream>
#include <set>
using namespace std;

string checkGender(string name) {
    set <char> distinct;
    
    for(int i = 0; i < name.size(); i++) {
        distinct.insert(name[i]);
    }
    
    if(distinct.size() % 2 == 0) {
        return "CHAT WITH HER!";
    }
    
    return "IGNORE HIM!";
}

int main() {
    string name;
    cin >> name;
    
    cout << checkGender(name) << "\n";
}
