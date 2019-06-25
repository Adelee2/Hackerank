#include <iostream>

using namespace std;

struct Node{
	int value;
	struct Node *next=NULL;
};

void printtree(struct Node *node){
	for(auto i=node; i!=NULL;i=i->next){
		cout<<i->value<<" ";
	}
	cout<<endl;
}

void sorttotree(int **arrs,int n){
	
	 Node *nodemon=new Node;
	 nodemon->value=(*arrs)[0];//first element in array is put inside nodemon

//the remaining elements are distributed to left node and right node 
//depending on which is greater than the current value 
//where nodemon points too
	 for(int i=1;i<n;i++){
		if((*arrs)[i]> nodemon->value){
			
			Node *rightchild=new Node;
		 	rightchild->value=(*arrs)[i];
		 	nodemon->next=rightchild;
//		 	cout<<rightchild->value<<" ";
		}
		else if((*arrs)[i]< nodemon->value){
			
			Node *leftchild=new Node;
		 	leftchild->value=(*arrs)[i];
		 	nodemon->next=leftchild;
//		 	cout<<leftchild->value<<" ";
		}
		
		nodemon=nodemon->next;
	 }
	 
//	 printtree(nodemon);
	 delete[] nodemon;
//	 delete[] rightchild;
//	 delete[] leftchild;
}

int main()
{
	int n;
	
	cout<<"Enter number of items"<<endl;
	cin>>n;
	int arrs[n];
	int *arr=arrs;
	cout<<"Enter values:"<<endl;
	
	for(size_t i=0;i<n;i++){
		cin>>arr[i];
	}
	
	sorttotree(&arr,n);
	return 0;
}
