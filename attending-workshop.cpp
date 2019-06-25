#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshops{
	int start_time;
	int duration;
	int end_time;
};
 struct Available_Workshops{
	int n;
	Workshops Workshop;
};
//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int input)
{
	Available_Workshops *workshop = new Available_Workshops[input];
	workshop->n = input;
	
	for(size_t i =0;i<input;i++){
		workshop[i].Workshop.start_time = start_time[i];
		workshop[i].Workshop.duration = duration[i];
		workshop[i].Workshop.end_time = start_time[i] + duration[i];
	}
int pin;
	for(size_t i =0;i<input-1;i++){
		pin = i;
		for(size_t k =i+1;k<input;k++){
			if(workshop[k].Workshop.start_time < workshop[pin].Workshop.start_time){
				pin=k; 
			}
		}
		swap(workshop[pin].Workshop.start_time ,workshop[i].Workshop.start_time);
		swap(workshop[pin].Workshop.duration ,workshop[i].Workshop.duration);
		swap(workshop[pin].Workshop.end_time ,workshop[i].Workshop.end_time);
		
	}
	pin=0;
	for(size_t i =0;i<input-1;i++){
		pin = i;
		for(size_t k =i+1;k<input;k++){
			if(workshop[k].Workshop.start_time == workshop[pin].Workshop.start_time){
				if(workshop[k].Workshop.end_time < workshop[pin].Workshop.end_time)
					pin=k; 
			}
		}
		swap(workshop[pin].Workshop.start_time ,workshop[i].Workshop.start_time);
		swap(workshop[pin].Workshop.duration ,workshop[i].Workshop.duration);
		swap(workshop[pin].Workshop.end_time ,workshop[i].Workshop.end_time);
		
	}

//	delete []workshop;
	return workshop;
	
}
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
	int counter=0,counting=0;
	int k=0,q=0;
	for(size_t i = 0;i<(ptr->n)-1;i++){
		if(ptr[i].Workshop.start_time != 0){
				k=i;
			if(ptr[k+1].Workshop.start_time < ptr[i].Workshop.end_time ){
				q=k+1;
				while(ptr[q].Workshop.start_time < ptr[i].Workshop.end_time){
					k++;
					q++;
				}
			i=k;
			counting=k;
			counter++;
			}
			else{
				counter++;
			}
		}
	}
	if(ptr[(ptr->n)-1].Workshop.start_time > ptr[counting].Workshop.end_time)
		counter = counter+1;
	
	return counter;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cout<<"n ";
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];
	
	cout<<"start times \n";
    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    cout<<"durations \n";
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr = new Available_Workshops[n];
    ptr = initialize(start_time,duration, n);
    
    for(int i = 0;i< n;i++){
    	cout<<ptr[i].Workshop.start_time<<" ";
	}
	cout<<"\n";
	for(int i = 0;i< n;i++){
    	cout<<ptr[i].Workshop.end_time<<" ";
	}
	cout<<"\n";
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
