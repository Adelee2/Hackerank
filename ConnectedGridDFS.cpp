#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Complete the maxRegion function below.
int counted=0;
bool DFSconnected(int row,int col, vector<vector<int>>& grid){
    if(col>(grid[row].size())-1 || col<1){
        // counted+=grid[row][col];
        return false;
    }
    if(row>grid.size()-1 || row<1){
        // counted+=grid[row][col];
        return false;
    }
    if(grid[row][col]==1 && (grid[row][col-1]>=1 || grid[row+1][col]>=1 || grid[row][col+1]>=1 
        || grid[row-1][col]>=1 || grid[row+1][col+1]>=1 || grid[row-1][col-1]>=1 || grid[row+1][col-1]>=1 || grid[row-1][col+1]>=1)){
        // counted+= grid[row][col];
        counted+= grid[row][col];
        grid[row][col] =8;
        // cout<<"row: "<<row<<", col: "<<col<<"counted: "<<counted<<endl;
        
        if(grid[row][col+1]==1){            
            DFSconnected(row,col+1,grid);
            
        }
        if(grid[row-1][col]==1){
            DFSconnected(row-1,col,grid);
        }
        if(grid[row][col-1]==1){
            // counted+= grid[row][col-1];
            // grid[row][col]=0;
            DFSconnected(row,col-1,grid);
        }
        if(grid[row+1][col]==1){
            // counted+= grid[row+1][col];
            // grid[row][col]=0;
            DFSconnected(row+1,col,grid);
        }
        if(grid[row+1][col+1]==1){
            // counted+= grid[row+1][col];
            // grid[row][col]=0;
            DFSconnected(row+1,col+1,grid);
        }
        if(grid[row-1][col-1]==1){
            // counted+= grid[row+1][col];
            // grid[row][col]=0;
            DFSconnected(row-1,col-1,grid);
        }
        if(grid[row-1][col+1]==1){
            // counted+= grid[row+1][col];
            // grid[row][col]=0;
            DFSconnected(row-1,col+1,grid);
        }
        if(grid[row+1][col-1]==1){
            // counted+= grid[row+1][col];
            // grid[row][col]=0;
            DFSconnected(row+1,col-1,grid);
        }
        
    }
    else{
        return true;
    }
    return false;
}

void solver(int currow,int curcol,vector<vector<int>>& grid, std::vector<int>& v)
{
    // cout<<"col size "<<grid[currow].size()<<" row length: "<<grid.size()<<endl;
    // cout<<"row: "<<currow<<" col: "<<curcol<<endl;
    if(curcol==grid[currow].size()-1){
        currow=currow+1;
        curcol=0;
    }
    if(currow==grid.size()-1){
        return;
    }
    else{
        // counted=0;
        // cout<<"currow: "<<currow<<" curcol: "<<curcol<<endl;
        if(DFSconnected(currow, curcol, grid)){
            int value= counted;
            v.push_back(value);
            counted=0;
        }
        else{
            v.push_back(1);
        }
        solver(currow,curcol+1,grid,v);
    }

    return;
}

int maxRegion(vector<vector<int>> &grid) {
    std::vector<int> v(0);

    solver(1,1,grid,v);
    // sort(kept.begin(),kept.end());
    // // cout<<"kept size: "<<kept.size();
    // int index= kept.size()/2;
    // min = kept[index];
    int min=-1;
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]>min){
            min=v[i];
        }
    }

    return min;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n+2);
    for (int i = 0; i < n+2; i++) {
        grid[i].resize(m+2);
        for (int j = 0; j < m+2; j++) {
            grid[i].push_back(0);
        }
    }

    for (int i = 1; i < n+1; i++) {
        grid[i].resize(m+2);

        for (int j = 1; j < m+1; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int res = maxRegion(grid);

    cout << res << "\n";

    // fout.close();

    return 0;
}
