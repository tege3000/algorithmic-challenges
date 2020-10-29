#include <iostream>
using namespace std;

void printPerfectPerm(int n) {
    if(n % 2 == 0) {
        for(int i = 2; i <= n; i = i+2) {
            cout << i << " " << i-1 << " ";
        }
        cout << "\n";
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    int n;
    cin >> n;
    
    printPerfectPerm(n);
}
