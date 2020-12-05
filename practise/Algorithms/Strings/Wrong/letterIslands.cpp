#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
 * Complete the letterIslands function below.
 */
int letterIslands(string s, int k) {
    /*
     * Write your code here.
     */
    int n = s.size();
    set <string> substrings;
    for(int a = 0; a < n; a++) {
        for(int i = a; i < n; i++) {
            string res ="";
            for(int j = a; j <= i; j++) {
                res += s[j];
            }            
            
            substrings.insert(res);
            
            
        }
    }
    
    int count = 0;
    for(auto res : substrings) {
        string tmp = s;
        int pos = tmp.find(res);
        while(pos != -1) {
            int next_pos = tmp.find(res, pos+1);
            while((next_pos - pos) <= res.size()) {
                pos = tmp.find(res, pos+1);
                next_pos = tmp.find(res, pos+1);
            }
            
            for(int j = pos; j < pos+res.size(); j++) {
                tmp[j] = 'X';
            }
     
            pos = tmp.find(res, pos+1);
            
        }


        int islandCount = 0;
        for(int i = 0; i < n; i++) {
            if(tmp[i] == 'X' && tmp[i-1] != 'X') {
                islandCount++;
            }
        }

        if(islandCount == k) {
            count++;
        }
    }
    
    
    return count;
}

int main()
{
    
    string s;
    getline(cin, s);
    
    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int result = letterIslands(s, k);
    
    cout << result << "\n";
    
    
    return 0;
}
