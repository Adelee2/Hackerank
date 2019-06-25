#include <bits/stdc++.h>

using namespace std;
vector<string> wordArray(string words){
	vector<string> wordarray;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = words.find(';', start)) != string::npos) {
    	string temp = words.substr(start, end - start);
        wordarray.push_back(temp);

        start = end + 1;
    }

    wordarray.push_back(words.substr(start));
    
    return wordarray;
}

    vector<string> crossword(10);
int counter = 0,countered=0,counting=0,i=0,j=0;

// Complete the crosswordPuzzle function below.

//void recursepuzzle(string words){
////	row=0,col=1;
//	vector<string>newwordarray = wordArray(words);
////	cout<<newwordarray[0].length()<<"\n";
//	int p=0,counting=0,counter=0;
//	for (int i = 0; i < 9; i++) {
//		for (int j = 0; j < 9; j++) {
//			for(int x=0;x<newwordarray.size();x++){
//				counting=0,counter=0;
//					if((crossword[i][j]=='-' || crossword[i][j] == newwordarray[x][0]) && crossword[i+1][j]=='-'){
////						cout<<"vertical"<<"\n";
//						for(int k = i;crossword[k][j] =='-';k++ )		//counts the '-' in the entire column of the puzzle
//							{ counting++;}
//							cout<<"counting: "<<counting<<"\n";
//						if(newwordarray[x].length()== counting){//checks in the dictionary the word that matches the length of 'counting'
////								cout<<"vertical:  "<<newwordarray[x]<<"\n";
//							for(int k = i,y=0;k<i+counting;k++ ){ 
//									crossword[k][j] = newwordarray[x][y++];
////									cout<<newwordarray[x][y]<<" "; 
//								}
////								break;
//						}
////						counting=0;
//					}
//			
//					else if((crossword[i][j]=='-' || crossword[i][j] == newwordarray[x][0]) && crossword[i][j+1]=='-'){	
////						cout<<"horizontal"<<"\n";
//						for(int k = j;crossword[i][k] =='-';k++ )
//							{ counter++; }
//							cout<<"row: "<<i<<"counter: "<<counter<<"\n";	
//						if(newwordarray[x].length() == counter){	//checks in the dictionary the word that matches the length of 'counter'
////								cout<<"horizontal:  "<<newwordarray[x]<<"\n";
//							for(int k = j,y=0;k<j+counter;k++ ){ 
//									crossword[i][k] = newwordarray[x][y++]; 
//									cout<<newwordarray[x][y]<<" ";
//								}
////								break;
//						}
////						j=j+counter;
////						counter=0;
//					}
//			}		
//		}
//	}
//}
void recursepuzzle(int row,int col,string words){
	vector<string>newwordarray = wordArray(words);
//	if(row<10 &&col<10){
		for(int x=0;x<newwordarray.size();x++){
				 if((crossword[row][col]=='-' || crossword[i][j] == newwordarray[x][0]) && crossword[i+1][j]=='-'){
					if(crossword[row][col] == '-'){
						counter++;
						recursepuzzle(row+1,col,words);
						cout<<"vertical: "<<counter<<"\n";
					}
					else{
						row = row-counter;
						
					}
				}
				else if((crossword[row][col]=='-' || crossword[i][j] == newwordarray[x][0]) || crossword[i][j+1]=='-'){
					if(crossword[row][col] == '-')	{
						counting++;
						recursepuzzle(row,col+1,words);
						cout<<"horizontal: "<<counting<<"\n";
					}
					else{
						col = col-counting;
					}	
				}
				
		}						
//	}
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);
	recursepuzzle(0,0,words);

   for (int i = 0; i < 10; i++) {
       cout<<crossword[i]<<"\n";
    }

    fout << "\n";

    fout.close();

    return 0;
}

