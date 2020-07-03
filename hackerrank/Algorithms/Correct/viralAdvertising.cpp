#include <bits/stdc++.h>

using namespace std;

// Complete the viralAdvertising function below.
int viralAdvertising(int n) {
    int shared = 5;
    int liked = 0;
    int count = 0;
    int startDay = 1;
    
    while(startDay <= n) {
        liked = shared/2;
        count = count + liked;
        shared = liked *3;
        startDay++;
    }
    
    return count;

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viralAdvertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
