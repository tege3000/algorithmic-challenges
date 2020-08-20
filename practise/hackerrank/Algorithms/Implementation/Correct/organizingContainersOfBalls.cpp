#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    int n = container.size();
    
    vector<long> boxes;
    vector<long> types;
    
    long sumBoxes = 0, sumTypes = 0;

    for(int i = 0; i < n; i++) {
        sumBoxes = 0, sumTypes = 0;
        for(int j = 0; j < n; j++) {
            sumBoxes += container[i][j];
            sumTypes += container[j][i];
        }
        boxes.push_back(sumBoxes);
        types.push_back(sumTypes);
        
    
    }
    

    
    sort(boxes.begin(), boxes.end());
    sort(types.begin(), types.end());
    
    if(boxes == types) {
        return "Possible";
    }
   
    return "Impossible";

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
