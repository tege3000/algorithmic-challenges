#include <iostream>
using namespace std;

int main()
{
    int n;
    int t;
    cin >> n;
    cin >> t;
    string s;
    cin >> s;
//    cout << n << endl;
//    cout << t << endl;
//    cout << s << endl;
    
    for(int i = 0; i < n; i++) {
        int pos = s.find('B');
        while(pos != -1) {
            if(pos == n-1) {
                break;
            }
            swap(s[pos], s[pos+1]);
            pos = s.find('B', pos+2);
        }
        if(i+1 == t) {
            break;
        }
    }
    
    cout << s << "\n";
    return 0;
}




