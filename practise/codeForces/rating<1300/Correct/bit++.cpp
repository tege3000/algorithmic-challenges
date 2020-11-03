#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int n;
    cin >> n;
    string add1 = "X++";
    string add2 = "++X";
    string sub1 = "X--";
    string sub2 = "--X";
    
    string code;
    
    for(int i = 0; i < n; i++) {
        cin >> code;
        
        if(code == add1 || code == add2) {
            count++;
        }
        
        if(code == sub1 || code == sub2) {
            count--;
        }
        
    }

    cout << count << "\n";
}
