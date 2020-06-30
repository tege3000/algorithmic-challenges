#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    double sum;
    cin >> sum;
    double pos_count = 0;
    double neg_count = 0;
    double zero_count = 0;
    
    for (int i=0; i <sum; i++) {
        int number;
        cin >> number;
        if(number > 0) {
            pos_count++;
        }
        
        if(number == 0) {
            zero_count++;
        }
        if(number < 0) {
            neg_count++;   
        }
    }
    cout.precision(6);
    cout << fixed << (pos_count / sum) << endl; 
    cout << fixed << (neg_count / sum) << endl; 
    cout << fixed << (zero_count / sum) << endl; 

    return 0;
}
