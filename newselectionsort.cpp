#include <iostream>
#include <time.h>

using namespace std;

template<class S>
void selectionsort(S *arr,S size)
{
	S val=-1;
	S index=0;
	float clockpermil=(float)(CLOCKS_PER_SEC)/1000;
	clock_t start=clock();
	for(size_t i=size-1;i>0;i--){
	 	for(size_t j = 0;j<=i;j++){
			if(arr[j]>val){
				val=arr[j];
				index=j;
			}
		}
		swap(arr[index],arr[i]);
		val=-1;
	}
	float elapsedmil = (clock() - start)/clockpermil;
		
	cout<<"time it ran: "<<elapsedmil<<endl;
}

template<class U>
void printarr(U *arr,U size){
	for(size_t i=0;i<size-1;i++){
		cout<<arr[i]<<", ";
	}
	cout<<arr[size-1]<<endl;
}

int main()
{
	
	int arr[]={40,2,1,45,95,34,4,7,3,9,5,8,6};
	
	selectionsort(arr,13);

	printarr(arr,13);
	return 0;
}
