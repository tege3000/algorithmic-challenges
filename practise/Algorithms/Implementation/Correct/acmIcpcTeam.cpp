#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the acmTeam function below.
vector<int> acmTeam(vector<string> topic) {
  
    
    int m = topic.size();
    int n = topic.at(0).size();

//    for(int i = 0; i < m; i++) {
//        //cout << "size: " << topic.at(i).size() << endl;
//        //get max number of topics
//        if(topic.at(i).size() > n) {
//            n = topic.at(i).size();
//        }
//    }
    
    //cout << "max "<< n << endl;
    vector <vector <int>> outer;
    
    for(int i = 0; i < m; i++) {
        for(int j = i+1; j <m; j++) {
            vector <int> inner;
            for(int k = 0; k < n; k++) {
                if(topic.at(i).at(k) == '1' || topic.at(j).at(k) == '1') {
                    inner.push_back(1);
                }
        
            }
            outer.push_back(inner);
        }
    }
    
    int count = 0;
    int best = 0;
    
    //find the max
    for(int i = 0; i < outer.size(); i++) {
        if(outer.at(i).size() > best) {
            best = outer.at(i).size();
        }
    }
    //find the number vectors with max length
    for(int i = 0; i < outer.size(); i++) {
        if(outer.at(i).size() == best) {
            count++;
        }
    }
    
    
    
    vector <int> ans;
    
    ans.push_back(best);
    ans.push_back(count);
    
    return ans;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
