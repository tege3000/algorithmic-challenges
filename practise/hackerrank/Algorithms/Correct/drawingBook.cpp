#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */

    int pageUpperBound, pageLowerBound;
    int resultFromStart = 0;
    for(int i = 0; i <n; i++) {
        pageUpperBound = (2*i) +1;
        pageLowerBound = 2*i;
        if(p>=pageLowerBound && p<=pageUpperBound) {
            resultFromStart = i;
            cout << i << endl;
            break;
        }

    }

    int resultFromEnd = 0;
    int j = 0;
    for(int i = n/2; i > 0; i--) {
        pageUpperBound = (2*i) +1;
        pageLowerBound = 2*i;
        if(p>=pageLowerBound && p<=pageUpperBound) {
            resultFromEnd = j;
            break;
        }
        j++;
    }
    return min(resultFromStart,resultFromEnd);
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}
