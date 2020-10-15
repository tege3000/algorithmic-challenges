#include <iostream>
#include <string>
using namespace std;


// TODO: CHANGE THIS CODE TO WORK WITH ACCEPTING INPUT AS INTEGERS
// CURRENTLY WORKS IF INPUT ACCEPTS 5 LINES OF STRINGS
int main()
{
    string str;
    getline(cin, str);
    
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    int n = str.size();
    
    int x_pos = 0;
    int y_pos;

    if(find(str.begin(), str.end(), '1') != str.end()) {
        y_pos = distance(str.begin(), find(str.begin(), str.end(), '1'));
    }

    for(int i = 1; i < n; i++) {
        getline(cin, str);
        str.erase(remove(str.begin(),str.end(),' '),str.end());
        if(find(str.begin(), str.end(), '1') != str.end()) {
            x_pos = i;
            y_pos = distance(str.begin(), find(str.begin(), str.end(), '1'));
            break;
        }
    }
    
    int x_middle = n/2;
    int y_middle = n/2;
  

    cout << abs(x_middle-x_pos) + abs(y_middle - y_pos) << endl;
    return 0;
}

