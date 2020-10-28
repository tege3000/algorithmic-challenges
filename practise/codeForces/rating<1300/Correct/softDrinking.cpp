#include <iostream>
using namespace std;

int countNumToasts(int n, int k, int l, int c, int d, int p, int nl, int np) {
    int drinkLimit = k * l;
    int limesLimit = c * d;
    
    int limes = n;
    int drink = n*nl;
    int salt = n*np;
    
    int count = 0;
    while(drink <= drinkLimit && limes <= limesLimit && salt <= p) {
        drink += n*nl;
        salt += n*np;
        limes += n;
        count++;
    }
    
    return count;
}

int main() {
    int n, k, l, c, d, p, nl, np;
    
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    
    cout << countNumToasts( n, k, l, c, d, p, nl, np) << "\n";
}
