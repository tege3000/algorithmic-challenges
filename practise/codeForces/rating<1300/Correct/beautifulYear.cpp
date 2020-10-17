#include <iostream>
#include <set>
#include <limits.h>
using namespace std;

int isDistinct(int year) {
    string y = to_string(year);
    set <char> distinct;
    
    for(auto i : y) {
        distinct.insert(i);
    }
    
    if(distinct.size() == y.size()) {
        return 1;
    }
    
    return -1;
}

int main()
{
    int year;
    cin >> year;
    
    for(int i = year+1; i <= INT_MAX; i++) {
        if(isDistinct(i) != -1) {
            cout << i << "\n";
            break;
        }
    }
    
    return 0;
}




