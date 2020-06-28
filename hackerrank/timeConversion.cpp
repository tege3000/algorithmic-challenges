#include <iostream>
#include <string>

using namespace std;

string timeConversion(string s) {
    string delimiter = ":";
    size_t i = 0;
    size_t next = 0;
    
    // initialize next to position of first occurrence of delimeter
    next = s.find(delimiter, i);
    
    string time;
    string hour, min, sec;
    int count = 0;
    
    //Note: string::npos in this case is used to signify when we reach
    //the end of a string and there are no more delimeters
    while(next != string::npos) {
        time = s.substr(i, next-i);
        
        if(count == 0) {
            hour = time;
            
        }
        if(count == 1) {
            min = time;
        }
        
        i = next + delimiter.length(); // shift i to the next value that is not the delimiter
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
    string s = "12:05:45AM";
    string timeIn24hours = timeConversion(s);
    cout << timeIn24hours << endl;
   
}
