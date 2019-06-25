#include <bits/stdc++.h>

using namespace std;

vector<double> runningMedian(vector<int> a) {
     vector <double>result;
     vector <int>sortingarr;
     int k=0;
     
//     result.push_back(static_cast<double>(a[0]));

     for(size_t i=0;i<a.size();i++){
     	while(k<=i){
     		sortingarr.push_back(a[k]);
     		k++;
		 }
		 sort(sortingarr.begin(),sortingarr.begin()+k);
		 if((i+1)%2==0){  //if even
		 	
			 int temping = i/2;
			 double tempest = ( (double)sortingarr[temping]+(double)sortingarr[temping+1] )/2;
			 result.push_back(tempest);
		 }
		 else{   //if odd
		 	int temp = i/2;
		 	double keep((double)sortingarr[temp]);
		 	result.push_back(keep);
		 }	
	 }
	 
     return result;

}


int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));
	clock_t begin, end; 
	double time_spent;
    int a_count;
    cin >> a_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> a(a_count);

    for (int a_itr = 0; a_itr < a_count; a_itr++) {
        int a_item;
        cin >> a_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        a[a_itr] = a_item;
    }
//    double val = ((double)a[1]+(double)a[2])/2;
//    cout<<val;
	cout<<"\n\n";
	
	begin = clock();
    vector<double> result = runningMedian(a);
	end = clock();
	
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<< time_spent << "\n\n";
	
    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout << result[result_itr];

        if (result_itr != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

//    fout.close();

    return 0;
}

