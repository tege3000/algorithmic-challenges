#include <iostream>
using namespace std;
 
string solve(int n, int m) {
    
    for(int i = n+1; i <= m; i++) {
        int isPrime = 1;
 
        for(int j = 1; j <= i; j++) {
            if(j != 1 && j != i) {
                if(i % j == 0) {
                    isPrime = 0;
                    break;
                }
            }
            
        }
        
        if(isPrime == 1 && i == m) {
        
            return "YES";
        }
        else if(isPrime == 1) {
            return "NO";
        }
        else {
            continue;
        }
    }
    
    return "NO";
}
 
int main() {
    int n,m;
    cin >> n >> m;
    
    cout << solve(n, m);
}