#include <bits/stdc++.h>

using namespace std;
int size =0;
/*
 * Complete the contacts function below.
 */
 string temp(string word,int size){
	string newstring = word;
	
	newstring = newstring.substr(0,size);
	return newstring;
}
vector<int> contacts(vector<vector<string>> queries) {
     vector<int> results;
     int count=0;
     for(int i=0;i< size;i++){
     	queries[i].resize(2);
        if(queries[i][0] =="find"){
//        	cout<<"yes "<<queries[i][1]<<"\n";
        	for(int j=0;j<i;j++){
        		string keepword = temp(queries[j][1],queries[i][1].length());
        		if(queries[i][1] == keepword ){count++;}
        	}
        	results.push_back(count);
        	count=0;
        }
	 }
	 return results;
}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));

    int queries_rows;
    cin >> queries_rows;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    size = queries_rows;

    vector<vector<string>> queries(queries_rows);
    for (int queries_row_itr = 0; queries_row_itr < queries_rows; queries_row_itr++) {
        queries[queries_row_itr].resize(2);

        for (int queries_column_itr = 0; queries_column_itr < 2; queries_column_itr++) {
            cin >> queries[queries_row_itr][queries_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> result = contacts(queries);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }
	
	cout<<"\n";
//    fout.close();

    return 0;
}

