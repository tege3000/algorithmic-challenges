#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    int s;
    string text;
    cout << 1 << " ";
    
    for(int i = p; i <= q; i++) {
        int sum = 0;
        s = i*i;
        text = to_string(s);
        
        
        int half = text.size() /2;
        int count = text.size();
        if(text.size() % 2 == 0) {
            
            
            for(std::string::size_type j = text.size(); j > 0; j = count) {
                string val;
                for(int a = 0; a < half; a++) {
                    val.push_back(text[text.size() - count]);
                    count--;
                    
                    
                    
                }

                if(!val.empty() || val != " ") {
                    sum += stoi(val);
                }
                
            }
                        
            if(sum == i){
                cout << i << " ";
            }
        }
        else {
            continue;
        }
       
    }
    
    
}


int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
