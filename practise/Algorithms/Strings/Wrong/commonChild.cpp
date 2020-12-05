#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
    int n = s1.size();
    
    vector<int> sizes;
    sizes.push_back(0); // doing this for cases where there are no matches

    int pos = distance(s2.begin(), find(s2.begin(), s2.end(), s1[0]));
    
    if(pos == n) {
        pos = INT_MAX;
    }
    

    
    int count = 1;
    for(int i = 1; i < n; i++) {
        int newPos = distance(s2.begin(), find(s2.begin(), s2.end(), s1[i]));
        
        if(newPos < pos && newPos != n) {
            pos = newPos;
            sizes.push_back(count);
            count = 1;
        }
        else if(newPos >= pos && newPos != n) {
            count++;
            pos = newPos;
            if(i == n-1) {
                sizes.push_back(count);
            }
        }
        else {
            continue;
        }
    }
    

    return *max_element(sizes.begin(), sizes.end());
}

int main()
{
    
    string s1;
    getline(cin, s1);
    
    string s2;
    getline(cin, s2);
    
    int result = commonChild(s1, s2);
    
    cout << result << "\n";
    
    return 0;
}
