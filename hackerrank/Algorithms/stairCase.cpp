#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int h;
    cin  >> h;
    
    string tree = "#";
    for (int i =0; i < h; i++) {
        cout.width(h);
        cout << right << tree << endl;
        tree = tree + "#";
    }
    return 0;
}
