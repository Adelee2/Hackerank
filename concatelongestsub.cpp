#include <bits/stdc++.h>

using namespace std;
vector<string>newkeep;

void kept(vector<string> &words){
	string newwords="";
	for(size_t i=0;i<words.size();i++){
		newwords+=words[i];
	}
	newkeep.push_back(newwords);
}

void permutate(vector<string> &words, int n){
	int i;
	if(n==1){
		kept(words);
	}
	else{
		for(i=0;i<n;i++){
			permutate(words,n-1);
			if(n%2==1){
				swap(words[0],words[n-1]);
			}
			else{
				swap(words[i],words[n-1]);
			}
		}
	}

}
int countseq(string word){
	int keeper=0;
	int count=1;
	size_t j=0;
	for(size_t i =0;i<word.length();i++){	
		for( j=i+1;j<word.length();j++){
			if(word[i] == word[j]){
				count++;
			}
			else{
//				count=1;
				break;
			}
		}
		i=j;
		if(count>keeper){
			keeper=count;
			count=1;
		}
		
	}
	
	return keeper;
}
//void printword(){
//	for(size_t i =0;i<newkeep.size();i++){
////		keeper.push_back(countseq(newkeep[i]));
//		cout<<newkeep[i]<<endl;
//	}
//}
int solution(vector<string> &words)
{
	vector<int>keeper;
	int max=0;
	for(size_t i =0;i<newkeep.size();i++){
		keeper.push_back(countseq(newkeep[i]));
//		cout<<countseq(newkeep[i])<<endl;
	}
	
	for(size_t j =0;j<keeper.size();j++){
		if(keeper[j]>max){
			max=keeper[j];
		}
	}
	
	return max;
}
int main()
{
	vector<string>words;
	int num;
	cin>>num;
	cout<<"enter words"<<endl;
	for(size_t j =0;j<num;j++){
		string temp;
		cin>>temp;
		words.push_back(temp);
	}
	permutate(words,num);
//	printword();
	cout<<solution(words);
	
	return 0;
}
