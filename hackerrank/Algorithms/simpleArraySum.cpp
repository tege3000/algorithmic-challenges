#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int array_size;
    cin >> array_size;
    int index_value;
    int sum = 0;
    
    for( int i = 0; i < array_size; i++) {
        cin >> index_value;
        sum = sum + index_value;
    }
    
    cout << sum;
    return 0;
}
