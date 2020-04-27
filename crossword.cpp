// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ';';

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

string validplacement(int current_row, int current_col, std::vector<string> &crossword, string word){
    int counter1=0,counter2=0;
    // cout<<"code got here: row: "<<current_row<<" col: "<<current_col<<endl;
    if(crossword[current_row][current_col]=='+' || crossword[current_row][current_col]=='X'){
        return "false";
    }
    else{
        if(crossword[current_row+1][current_col]=='-'){
            while(crossword[current_row][current_col] !='+' && crossword[current_row][current_col]!='X'){
                counter1++;
                current_row++;
            }
        }
        if(crossword[current_row][current_col+1]=='-'){
            while(crossword[current_row][current_col]!='+' && crossword[current_row][current_col]!='X'){
                counter2++;
                current_col++;
            }
        }

        if(counter1==word.length()){
            return "row";
        }
        if(counter2==word.length()){
            return "col";
        }
    }

    return "false";
}

bool addword(int current_row, int current_col, std::vector<string> &crossword, string word, string direction){
    
        if(direction=="row"){
            for (int j = 0; j < word.length(); ++j)
            {
                crossword[current_row][current_col]=word[j];
                current_row++;
            }
            return true;
        }
        else if (direction=="col"){
            for (int j = 0; j < word.length(); ++j)
            {
                crossword[current_row][current_col]=word[j];
                current_col++;
            }
            return true;
        }

    return false;
}

void removeword(std::vector<string> &words,string word){
    auto itr = find(words.begin(),words.end(),word);
    if(itr != words.end()) words.erase(itr);

    return;
}

bool solvepuzzle(int row, int col, std::vector<string> &crossword, std::vector<string> &words){
    if(col==10){
        row=row+1;
        col=0;
    }
    if(row==10){
        return true;
    }
    else{
        for (int i = 0; i < words.size(); ++i)
        {
            string direction = validplacement(row,col,crossword,words[i]);
            if( direction=="row"){
                // cout<<"adding downwards "<<endl;
                addword(row,col,crossword,words[i], "row");
                removeword(words,words[i]);

            }
            else if(direction=="col"){
                // cout<<"adding rigtward "<<endl;
                addword(row,col,crossword,words[i], "col");
                removeword(words,words[i]);
            }

        }

        // cout<<"row: "<<row<<" col: "<<col<<endl;
        solvepuzzle(row,col+1,crossword,words);
    }
    return false;
}


int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    vector<string> crossword(10);

    [&](){
        for (int i = 0; i < 10; i++){
            string crossword_item;
            getline(cin, crossword_item);

            crossword[i] = crossword_item;
        }
    };

    string words;
    getline(cin, words);

    // vector<string> result = crosswordPuzzle(crossword, words);
    auto answers = [&,words](){

            std::vector<string> finalwords;
            finalwords= split_string(words);
            
            if(crossword[0][0]=='+' || crossword[0][1]=='+' || crossword[1][0]=='+' || crossword[1][1]=='+'){
                cout<<"+ here"<<endl;
                std::vector<string> crosswordpuzz(12,"++++++++++++");
                int m,n=0;
                for(size_t i=1;i<crosswordpuzz.size()-1;i++){
                    for(size_t j=1;j<crosswordpuzz[i].length()-1;j++){
                        if(crossword[m][n]=='-'){
                            crosswordpuzz[i][j]='-';
                        }
                        n++;
                    }
                    m++;
                    n=0;
                }
                solvepuzzle(1,1,crosswordpuzz,finalwords);
                return crosswordpuzz;
            }
            else{
                // cout<<"X here"<<endl;
                std::vector<string> crosswordpuzz(12,"XXXXXXXXXXXX");
                int x,y=0;
                for(size_t i=1;i<crosswordpuzz.size()-1;i++){
                    for(size_t j=1;j<crosswordpuzz[i].length()-1;j++){
                        // cout<<crossword[x][y]<<" ";
                        if(crossword[x][y]=='-'){
                            // cout<<"code ran"<<endl;
                            crosswordpuzz[i][j]='-';
                        }
                        y++;
                    }
                    x++;
                    y=0;
                }
                cout<<"board transferred "<<endl;
                solvepuzzle(1,1,crosswordpuzz,finalwords);
                return crosswordpuzz;
            }

            return finalwords;
    };

    // result();
    vector<string> result =answers();

    [=](){
        for (int i = 1; i < result.size()-1; i++) {
            cout << result[i].substr(1,10);

            if (i != result.size() - 2) {
                cout << "\n";
            }
        }

    };

    cout << "\n";

    // fout.close();

    return 0;
}
