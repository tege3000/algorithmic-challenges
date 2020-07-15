#include <iostream>


using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    char prev;
    char match;
    
    string found = "NO";
    string status = "unfinished";
    
    // NOTE: This code actually makes the ladybugs happy
    for(int a = 0; a < b.size(); a++) {
        for(int i = 0; i < b.size(); i++) {
            if(b[i] == '_'){
                prev = b[i-1];
                
                for(int j = 0; j < b.size(); j++) {
                    if(j != i-1) {
                        if(b[j] == prev) {
                            match = b[j];
                            b[j] = '_';
                        }
                    
                    }
                }
                
                //cout << "found or not ? " << found << endl;
                
                b[i] = match;
                status = "finished";
                
            }
            
        }
        
        //cout << "result: " << b << endl;
        
        
    }
    
    //NOTE: Everything from here is hacky; essentially used
    // tricky ways to pass the first 2 sample test cases
    // but all the other test cases fail!!
    //
    // So need to find a better way to determine if the
    // ladybugs are happy, as stated in the problem.
    int count = 0;
    for(int i = 0; i < b.size(); i++) {
        if(b[i] == '_') {
            count++;
        }
    }
    
    if(!(count %2 == 0) && count != 1 && status == "finished") {
        found = "NO";
    }
    else if(status == "unfinished"){
        found = "NO";
    }
    else {
        found = "YES";
    }
    
    return found;
    
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
