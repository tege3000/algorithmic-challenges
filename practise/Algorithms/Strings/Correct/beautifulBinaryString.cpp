#include <bits/stdc++.h>

using namespace std;

// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b) {
    int count = 0;
    for(int i = 0; i < b.size() - 2; i++) {
        //cout << "here" << endl;
        
        if(b[i] == '0' && b[i+1] == '1' && b[i+2] == '0') {
            //cout <<"nawa" <<endl;
            count++;
            b[i+2] = '1';
        }
    }
    
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    int result = beautifulBinaryString(b);

    fout << result << "\n";

    fout.close();

    return 0;
}
