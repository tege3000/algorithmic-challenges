#include <iostream>
#include <string>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    //cout << "beginning is: " << b << endl;
    
    int allAlphas = 0;
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != '_') {
            allAlphas = 1;
        }
        else {
            allAlphas = 0;
            break;
        }
    }
    
    if(allAlphas == 1) {
        return "NO";
    }
    
    int nonEmptyIndex = 0;
    while(b[b.size()-1] != '_') {
        for(int i = 0; i < b.size()-1; i++) {
            if(b[i+1] == '_') {
                int found = b.find(b[i], i+1);
                
                if(found != -1) {
                    b[i+1] = b[i];
                    b[found] = '_';
                    break;
                }
                
                for(int j = i+2; j < b.size(); j++) {
                    if(b[j] != '_') {
                        nonEmptyIndex = j;
                        break;
                    }
                }
                found = b.find(b[nonEmptyIndex]);
                
                if(found != -1) {
                    b[nonEmptyIndex-1] = b[found];
                    b[found] = '_';
                    break;
                }
                
            }
            
            
        }
        //cout << b << endl;
    }
    
    
    //cout << "result is: " << b << endl;
    int count;
    int counter = 1;
    for(int i = 0; i < b.size(); i= counter+1) {
        if(b[i] == '_') {
            counter++;
            count = 2;
        }
        else {
            count = 1;
            for(int j = i+1; j < b.size(); j++) {
                //cout << b[i] << " " << b[j] << endl;
                if(b[i] == '_') {
                    counter++;
                    count = 2;
                    break;
                }
                
                if(b[i] == b[j]) {
                    counter = j;
                    count++;
                }
                else {
                    continue;
                }
                
            }
        }
        
        if(count <= 1) {
            return "NO";
        }

    }

    return "YES";
}


int main()
{
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        string b;
        getline(cin, b);
        
        string result = happyLadybugs(b);
        
        cout << result << "\n";
    }
    
    return 0;
}
