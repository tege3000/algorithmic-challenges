#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    /*
     * Write your code here.
     */

    string delimiter = ":";
    size_t i = 0;
    size_t next = 0;
    
    // initialize next to position of first occurrence of delimeter
    next = s.find(delimiter, i); 

    string time;
    string hour, min, sec;
    int count = 0;
    while(next != string::npos) {
        time = s.substr(i, next-i);
        
        if(count == 0) {
            hour = time;
            
        }
        if(count == 1) {
            min = time;
        }
        
        i = next + delimiter.length();
        next = s.find(delimiter, i);
        count++;

    }
    
    sec = s.substr(i, 2); // rS -> remaining String without the AM or PM
    string timePeriod = s.substr(i+2); // remaining string after the sec
    
    int h = stoi(hour);
    
    if(h >=1 && h <= 12) {
        if(timePeriod == "PM") {
            if(h == 12) {
                h = 12;
            } 
            else {
                h += 12;
            }  
        }
    }

    if(timePeriod == "AM") {
        if(hour == "12") {
            hour = "00";
        }
    }
    
    string result;

    if(timePeriod == "PM") {
        result = to_string(h) + ":" + min + ":" + sec;
    }
    else {
        result = hour + ":" + min + ":" + sec;
    }

    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
