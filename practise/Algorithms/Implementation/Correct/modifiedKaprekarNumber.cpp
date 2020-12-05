#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    long s;
    string text;
    int counter = 0;
    
    for(int i = p; i <= q; i++) {
        int sum = 0;
        s = pow(i,2);
        
        
        text = to_string(s);
        
        int half = text.size() /2;
     
        
        if(half == 0) {
            if(s == i){
                cout << i << " ";
                counter++;
            }
            
           
            //cout << endl;
            //cout << i << " " << s << " " << s << endl;
        }
        else {
            string val;
            //get first half first
            for(int j = 0; j < half; j++) {
                val.push_back(text[j]);
            }
            
            if(!val.empty() || val != " ") {
                sum += stoi(val);
            }
            
            //reset val
            val = " ";
            
            // get the remaining half
            for(int k = half; k < text.size(); k++) {
                val.push_back(text[k]);
            }
            
            if(!val.empty() || val != " ") {
                sum += stoi(val);
            }
            
            
            
            //cout << i << " " << s << " " << sum << endl;
            
            if(sum == i){
                cout << i << " ";
                counter++;
            }
            
        }
       
    }
    
    if(counter == 0) {
        cout << "INVALID RANGE";
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
