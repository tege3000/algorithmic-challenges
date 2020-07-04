#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int size;
    long long int sum = 0;
     
    cin >> size;
    int array[size];
    long long int data;
    
    for(int i=0; i< size; i++) {
        cin >> data;
        array[i] = data;
        sum = sum + array[i];
    }
    cout << sum;
    return 0;
}
