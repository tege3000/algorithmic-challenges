#include <iostream>
#include <string>
#include <vector>

using namespace std;

string dayOfProgrammer(int year) {
    vector<vector <int>> v1;
    int numOfDays = 0;
    
    for(int i = 1; i < 13; i++) {
        vector <int> months;
        if(i == 9 || i == 4 || i == 6 || i == 11) {
            numOfDays = 30;
            
            months.push_back(i);
            months.push_back(numOfDays);
            
            v1.push_back(months);
        }
        else if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
            numOfDays = 31;
            months.push_back(i);
            months.push_back(numOfDays);
            
            v1.push_back(months);
            
        }
        else if(i == 2) {
            // in this case i == 2 which is february
            // so now we check what kind of year it is
            if(year >= 1700 && year <= 1917) {
                
                //now we check if its a leap year
                if(year % 4 == 0) {
                    numOfDays = 29 - 14; //since feb in a jullian year start at feb14th
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                else {
                    numOfDays = 28 -14; //since feb in a jullian year start at feb14th
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                
            }
            if(year == 1918) {
                //now we check if its a leap year
                if(year % 400 == 0) {
                    numOfDays = 29 - 14; //since feb in a jullian year start at feb14th
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                else if(year % 4 == 0 || !(year % 100 == 0)) {
                    numOfDays = 29-14; //since feb in a jullian year start at feb14th
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                else {
                    numOfDays = 28-14; //since feb in a jullian year start at feb14th
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
            }
            if(year > 1918) {
                if(year % 400 == 0) {
                    numOfDays = 29;
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                else if(year % 4 == 0 && !(year % 100 == 0)) {
                    numOfDays = 29;
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                else {
                    numOfDays = 28;
                    months.push_back(i);
                    months.push_back(numOfDays);
                    
                    v1.push_back(months);
                }
                
                
            }
            
        }
    }
    
    int sum = 0;
    int month = 0;
    int days = 0;
    int specificDay = 0;
    
    for(int i = 0; i < v1.size(); i++) {
        sum += v1.at(i).at(1);
        
        if(sum >= 256) {
            month = v1.at(i).at(0);
            days = v1.at(i).at(1);
            break;
        }
    }
    
    if(year >= 1700 && year <= 1917) {
        specificDay = (days - (sum - 256)) - 14;
    }
    else {
        specificDay = days - (sum - 256);
    }
    
    
    string sDay = to_string(specificDay);
    string sMonth = to_string(month);
    string sYear = to_string(year);
    
    string result;
    
    if (sDay.length() <= 1) {
        result = "0" + sDay + "." + sMonth + "." + sYear;
    }
    if (sMonth.length() <= 1) {
        result = sDay + ".0" + sMonth + "." + sYear;
    }
    if (sDay.length() <= 1 && sMonth.length() <=1) {
        result = "0" + sDay + ".0" + sMonth + "." + sYear;
    }
    
    return result;
    
}

int main()
{
    int year = 1800;
    cout << dayOfProgrammer(year);
    
}
