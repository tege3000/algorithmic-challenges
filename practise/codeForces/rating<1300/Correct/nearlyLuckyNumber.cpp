#include <iostream>
#include <algorithm>

using namespace std;

string determineNearlyLuckyNum(long long int num) {
    string numS = to_string(num);
    sort(numS.begin(), numS.end());
    int count = 0;
    int didntEnter = 0;
    for(int i = 0; i < numS.size(); i++) {
        if(numS[i] == '4' || numS[i] == '7') {
            count++;
        }
    }
    
    if(count == 4 || count == 7) {
        return "YES";
    }
    
    return "NO";
}

int main() {
    long long int num;
    cin >> num;
    
    cout << determineNearlyLuckyNum(num) << "\n";
}
