#include <bits/stdc++.h>

using namespace std;

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    string time = "";
    vector<string> times =  {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};
    
    
    
    if(m == 0) {
        return times[h-1] + " o' clock";
    }
    else {
        if(60 - m > 30) {
            if(m != 15) {
                if(m != 1) {
                    return times[m-1] + " minutes past " + times[h-1];
                }
                else {
                    return times[m-1] + " minute past " + times[h-1];
                }
            }
            else {
                return "quarter past " + times[h-1];
            }
        }
        else if(60 - m < 30) {
            if(60 - m != 15) {
                return times[60-m-1] + " minutes to " + times[h];
            }
            else {
                return "quarter to " + times[h];
            }
        }
        else {
            return "half past " + times[h-1];
        }
    }
    
    return time;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    fout << result << "\n";

    fout.close();

    return 0;
}
