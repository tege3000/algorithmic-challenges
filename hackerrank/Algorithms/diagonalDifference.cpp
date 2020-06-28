#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    
    int matrix_size;
    cin >> matrix_size;

    int number;
    int array_size = matrix_size * matrix_size;
    int array[array_size];

    for (int i = 0; i< array_size; i++) {
        cin >> number;
        array[i] = number;
    }
    
    int right_sum = 0;
    int right_offset = matrix_size +1;
    for (int i = 0; i < array_size; i += right_offset) {
        right_sum += array[i];
    }
    
    int left_sum = 0;
    int left_offset = matrix_size - 1;
    for(int i = (array_size - left_offset); i > left_offset; i -= left_offset ) {
        left_sum += array[i-1];
    }
    
    cout << abs(right_sum - left_sum);
        
    return 0;
}
