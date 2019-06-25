// you can use includes, for example:
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
 int row,col=0;
 
// void prints(vector< vector<int> > &A){
//	for(int i =0;i<row;i++){
////        A.resize(col);
//        for(int j=0;j<col;j++){
//            cout<<A[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//}

int result(vector< vector<int> > &A){
    int counted=0,counting=0,counting1=0;
    
     for(int i =0;i<row;i++){
        for(int j=0;j<col;j++){
        	
            if(A[i][j]==1){
                counting++;
            }
            else if(A[i][j]==0){
                counting1++;
            }
        }
        if(counting==col){
            counted++;
            
        }
        if(counting1==col){
            counted++;
            
        }
        counting=0;
        counting1=0;
    }
    return counted;
}

 int solutions(vector< vector<int> > &B,int selected_col) {
    // write your code in C++14 (g++ 6.2.0)
    vector< vector<int> > A;
    for(int i =0;i<row;i++){
        A.resize(col);
        for(int j=0;j<col;j++){
            A[i].push_back(B[i][j]);
        }
    }
    for(int i =0;i<row;i++){
        if(A[i][selected_col] ==1){
           A[i][selected_col] =0; 
        }
        else if(A[i][selected_col] == 0){
            A[i][selected_col] =1;
        }
    }
    
    return result(A);
}

int solution(vector< vector<int> > &B) {
    // write your code in C++14 (g++ 6.2.0)
    int min=0;
    int sel_col,num_of_col=0;
    vector<int>values(0);
    // cout<<"\nhow many columns do you want to flip?"<<endl;
    for(int sel_col=0;sel_col<col;sel_col++){
        int resultcheck=solutions(B,sel_col);
        values.push_back(resultcheck);
    }
        // cout<<"\nenter column to invert:"<<endl;
    for(int i=0;i<values.size();i++){
        if(values[i]>min){
            min=values[i];
        }
    }
    // prints(matrix,row,col);
    return min;
}



int main()
{
    vector<vector<int>>matrix;
    int temp;
    cout<<"Enter row and column:\n";
   
    cin>>row>>col;
    
    cout<<"Enter values 1 and 0 into matrix"<<endl;
    for(int i=0;i<row;i++){
        matrix.resize(col);
        for(int j=0;j<col;j++){
            
            cin>>temp;
            matrix[i].push_back(temp);
        }
    }
   cout<< solution(matrix);
//     prints(matrix,row,col);
    
    
    return 0;
}


