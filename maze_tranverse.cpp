#include "maze_tranverse.h"


Tranversal::Tranversal(array<array<char,12>,12> &arr){
	arrs=arr;
}

char Tranversal::maze_tranverse(int rowin, int colin){
	
	//lets start now
	
	if(colin==11)
		arrs[rowin][colin]='x';
		
//	cout<<"rowin1 is: "<<rowin<<"  colin1 is: "<<colin<<"\n";
   if(arrs[rowin][colin+1]=='.' ){
		arrs[rowin][colin]='>';
		rowin=rowin;
		colin=colin+1;
		maze_tranverse(rowin,colin++);
	}
	else if(arrs[rowin-1][colin]=='.'){
	   arrs[rowin][colin]='^';
	   rowin=rowin-1;
	   colin=colin;
		maze_tranverse(rowin--,colin);
	}
	else if(arrs[rowin+1][colin]=='.' ){
	
		arrs[rowin][colin]='v';
		rowin=rowin+1;
		colin=colin;
		maze_tranverse(rowin++,colin);
		
	}
	else if(arrs[rowin][colin-1]=='.'){
		arrs[rowin][colin]='<';
		rowin=rowin;
		colin=colin-1;
		maze_tranverse(rowin,colin--);
	}
	
}

void Tranversal::display(){
	for(auto &i:arrs){
	  for(auto &j: i){
	  	cout<<j<<setw(3);
	  }
	cout<<"\n\n";
	}
}
int main()
{
	int counter=0,i;
	array<array<char,12>,12> arr={
								  '#','#','#','#','#','#','#','#','#','#','#','#',
                                  '#','.','.','.','#','.','.','.','.','.','.','#',
                                  '.','.','#','.','#','.','#','#','#','#','.','#',
                                  '#','#','#','.','#','.','.','.','.','#','.','#',
                                  '#','.','.','.','.','#','#','#','.','#','.','.',
                                  '#','#','#','#','.','#','.','#','.','#','.','#',
                                  '#','.','.','#','.','#','.','#','.','#','.','#',
                                  '#','#','.','#','.','#','.','#','.','#','.','#',
                                  '#','.','.','.','.','.','.','.','.','#','.','#',
                                  '#','#','#','#','#','#','.','#','#','#','.','#',
                                  '#','.','.','.','.','.','.','#','.','.','.','#',
                                  '#','#','#','#','#','#','#','#','#','#','#','#'
								};
								
		for(i=0;i<12;i++){
			if(arr[i][0] == '.'){
				arr[i][0]= '>';
				counter=i;
			}
		}
		
	Tranversal mytranverse(arr);
			
//	mytranverse.display();
	mytranverse.maze_tranverse(counter,1);
	cout<<"\n\n";
	
	
	cout<<"moving through the maze....\n"<<endl;
	mytranverse.display();
	
	cout<<"\nOperation maze completed!!!"<<endl;
	
	return 0;
}


