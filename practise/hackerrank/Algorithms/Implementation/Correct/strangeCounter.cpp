#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long sTime = 0l, eTime = 0l;
    long eValue = 0l;
    long diff = 0l;
    long stop = 3l;
    
    for(long i = 3l; i <= stop; i = 2*i*1l) {
        //cout << t << endl;
        sTime = i-2;
        eTime = i+sTime-1;
        cout << sTime  << " " << eTime <<endl;
        if(t >= sTime && t <= eTime) {
            diff = t - sTime;
            eValue = i - diff;
            break;
        }
        
        stop *= 2;
        
    }
    
    return eValue;
    
    
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
