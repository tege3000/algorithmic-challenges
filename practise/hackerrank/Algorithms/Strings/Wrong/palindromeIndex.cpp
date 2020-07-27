#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// Complete the palindromeIndex function below.
int palindromeIndex(string s) {
    //sort(s.begin(), s.end());
    
    int count = 0;
    int counter = 0;
    vector <tuple<char,int, int>> counts;
    for(int i = 0; i < s.size(); i = counter) {
        tuple <char, int, int> inner;
        count = 0;
        for(int j = i; j < s.size(); j++) {
            if(s[i] == s[j]) {
                //cout << s[j] << endl;
                count++;
                counter = j+1;
            }
            else {
                counter = j;
                break;
            }
        }
        
        inner = make_tuple(s[i], i, count);
        counts.push_back(inner);
    }
    
//    for(int i = 0;  i < counts.size(); i++) {
//        cout << get<0>(counts[i]) << get<1>(counts[i]) << get<2>(counts[i]) << endl;
//    }
    
    int isEven = 0;
    int oddCount = 0;
    int oddIndex = -1;
    if(s.size() % 2 == 0) {
        //cout <<  "even" <<endl;
        for(int i = 0; i < counts.size(); i++) {
            //cout << get<0>(counts[i]) << get<1>(counts[i]) << get<2>(counts[i]) << endl;
            if(get<2>(counts[i]) % 2 == 0) {
                isEven = 1;
            }
            else {
                if(get<2>(counts[i]) <= 1) {
                    return get<1>(counts[i]);
                }
            }
        }

        if(isEven == 1) {
            return -1;
        }

    }
    else {
        for(int i = 0; i < counts.size(); i++) {
            //cout << get<0>(counts[i]) << get<1>(counts[i]) << get<2>(counts[i]) << endl;

            if(!(get<2>(counts[i]) % 2 == 0)) {
                oddCount++;
                if(get<2>(counts[i]) <= 1) {
                    oddIndex = get<1>(counts[i]);
                }
                
            }
        }

        if(oddCount > 1) {
            return oddIndex;
        }
        else {
            
            if(oddIndex != -1) {
                return oddIndex;
            }
            else {
                return -1;
            }
        }
    }
    
    
    return 0;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        
        int result = palindromeIndex(s);
        
        cout << result << "\n";
    }
    
    return 0;
}
