#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int val;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> val;
        sum  += val;
    }
    
    int count = 0;
    
    for(int i = 1; i <= 5; i++) {
        if((sum + i) % (n+1) == 1) {
            continue;
        }
        else {
            count++;
        }
    }
    
    cout << count << endl;
}

