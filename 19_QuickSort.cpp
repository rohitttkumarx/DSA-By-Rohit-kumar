
#include<iostream>
using namespace std;

#define Max 100

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;

	for(int j=low;j<high;j++){
		if(arr[j]<=pivot){
			i++;
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}

	int temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;

	return i+1;
}

void quicksort(int arr[],int low,int high){
	if(low<high){
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

int main(){
	int arr[Max],n;
	cout<<"Name:Rohit Kumar"<<endl;
	cout<<"URN:2514169"<<endl;
	cout<<"CRN:2515244"<<endl;

	cout<<"Enter number of elements: ";
	cin>>n;

	if(n<=0 || n>Max){
		cout<<"Invalid size";
		return 0;
	}

	cout<<"Enter elements: ";
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	quicksort(arr,0,n-1);

	cout<<"Sorted list: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}
