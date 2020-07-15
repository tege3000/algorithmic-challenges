#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long ans;
    long initValue = 3;
    long time = 1;
    int start = 1;
 
    
    for(long i = 0; i < start; i++) {
        for(long j = initValue; j >= 1; j--) {
            if(t == time) {
                ans = j;
                return ans;
            }
            time++;
        }
        
        initValue = 2 * initValue;
        start++;
        
    }
    
    
    return 0;
    
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strangeCounter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}
