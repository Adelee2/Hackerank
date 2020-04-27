// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> split_string(string);
int index_of_search =0;
int binarysearcharr(vector<int>vec,int start, int value,int mid){
    
    int middle = (start+mid)/2;
    int mid_value = vec[middle];

    if(middle<= 1 || middle>=(vec.size()-1)){
        // cout<<"returning..."<<endl;
        return index_of_search;
    }
    
    if(value<  mid_value){
            index_of_search=middle;
            // cout<<"left"<<endl;
            binarysearcharr(vec,0,value,middle);
            // return index_of_search;
            
    }
    else if(value >mid_value){
            index_of_search=middle;
            // cout<<"right"<<endl;
            binarysearcharr(vec,middle,value,vec.size());
            // return index_of_search;
        }
    else{
        index_of_search = middle;
        return index_of_search;
    }

    return index_of_search;
}
// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector <int> result(alice.size(),0);
    // set<int, greater<int> > s;

    set<int>s;
    set<pair<int,int>>s2;

    for (int i=0;i<scores.size();i++)
    {
        s.insert(scores[i]);
    }
    int grade= s.size();
    vector<int> vec;

   for(auto j:s){
    vec.push_back(j);
    s2.insert(make_pair(j, grade));
    grade--;
   }

    
   for(auto k: alice){
        cout<<"alice[k]: "<<k;
        int getval = binarysearcharr(vec,0,k,vec.size());
        index_of_search=0;
        cout<<" getval: "<<getval<<endl;
   }
   // auto newek = s2.end();
   // newek--;
   //      for(int m=0;m<alice.size();m++){
       
   //          for(auto sk =s2.begin(); sk!=s2.end();sk++){
   //              if(alice[m]==sk->first){
   //                  result[m]=sk->second;
   //                  break;
   //              }
   //              if(alice[m] < sk->first){
   //                  int val = sk->second;

   //                  result[m] = val+1;
   //                  // cout<<alice[m]<<" "<<sk->first<<" "<<val+1<<endl;
   //                  break;
   //              }
                
   //          }
   //          if(alice[m] > newek->first){
   //              result[m] = newek->second;
   //          }
   //          // cout<<"m: "<<m<<endl;
   //      }
    return result;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    cout<<"enter leaderboard score\n";
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    cout<<"game scores\n";
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    // fout.close();

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
