#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int valleyCount = 0;
    int sum = 0;

    for(int i = 0; i < n; i++) {


        if(s.at(i) == 'U') {
            sum++;
        }
        if(s.at(i) == 'D') {
            sum--;
        }

        if(sum == 0 && s.at(i) != 'D') {
            valleyCount++;

        }
    }

    return valleyCount;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
