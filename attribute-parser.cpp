#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream> 

using namespace std;
vector<string> split(const string &);

struct HRML_att{
	string attribute;
};
struct HRML_query{
	int n;
	string query;
};
struct Result{
	string word;
};

Result* Calculator(HRML_att *hrml_att,HRML_query *hrml_query,int n)
{
	Result *result = new Result[n];
	int counter[n];
	int count=1;
	int i=0;
	//counts number of dots in each query and put it in an array counter
	while(i<n){
		count=1;
		for(size_t k=0;k<hrml_query[i].query.size();k++){
			if(hrml_query[i].query[k] == '.'){
				count++;
			}
		}
		counter[i]=count-1;
		i++;
	}
	//using the number of dots in array counter selects appropiate hrml attr and perform text processing 
	int r=0;
	for(size_t m =0;m<n;m++){
//		hrml_att[counter[m]].attribute;
		ostringstream ss;
		char temping;
		for(size_t k=0;k<hrml_query[m].query.size();k++){
				if(hrml_query[m].query[k] == '~'){
					k++;
					size_t w=k;
					for(size_t q=k;q< hrml_query[m].query.size();q++){
						ss<<hrml_query[m].query[q]; //from after ~ to d last char is converted to a string
						temping= hrml_query[m].query[w];
					}
					break;
				}
			}
			string temp = ss.str();
			if(hrml_att[counter[m]].attribute.find(temp) == string::npos){
				result[r++].word="Not Found!";
			}
			else{
					ostringstream ss1;
				for(size_t q=0;q< hrml_att[counter[m]].attribute.size();q++){
					if( hrml_att[counter[m]].attribute[q] == temp[0] && hrml_att[counter[m]].attribute[q] == temp[1]){
						q = q + temp.length() +4;
						for(size_t p=q;hrml_att[counter[m]].attribute[p]!='"';p++){
							ss1<< hrml_att[counter[m]].attribute[p]; // chars from 1st " to last " is converted to string
						}
//						temping=' ';
						temp="";
						break;
					}
				}
				string temp1 = ss1.str();
				result[r++].word=temp1;// prints the value of what is inside the "..." in hrml_att
			}
	
		
	}
	
	return result;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
	string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(nr_temp);

    int a = stoi(nr[0]);

    int b = stol(nr[1]);
    
//    cout<<"a :"<<a<<"  b: "<<b<<endl;
	cin.ignore();
	HRML_att *hrml_att = new HRML_att[a];
//	hrml_query->n=input2;
	
	for(size_t i =0;i<a;i++){
		getline(cin,hrml_att[i].attribute);
	}
	cin.ignore();
	HRML_query *hrml_query = new HRML_query[b]; 
	for(size_t i =0;i<b;i++){
		getline(cin,hrml_query[i].query);
	}
	
		cout<<"\n";
	Result* Calc = new Result[b];
	
	Calc= Calculator(hrml_att,hrml_query,b);
	for(size_t i = 0;i<b;i++){
		cout<<Calc[i].word<<"\n";
	}
//	Calculator(hrml_att,hrml_query,input2);
	
	delete []Calc;
	delete []hrml_att;
	delete []hrml_query;
    return 0;
}
vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

