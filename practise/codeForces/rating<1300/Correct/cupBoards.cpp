#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int l, r;
    int sumL = 0, sumR = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        
        sumL += l;
        sumR += r;
    }
    
    cout << min(sumL, n-sumL) + min(sumR, n-sumR) << "\n";
}
