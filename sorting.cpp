#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr,int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;

}
void bubbleSort(int *arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1])
			  swap(&arr[j],&arr[j+1]);
		}
	}
}

void insertionSort(int *arr,int n){
	int i,j,key;
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 and arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;

	}
	
}

void modBubbleSort(int *arr,int n){
	int i, j;
	bool swapped=false;
	for(i=0;i<n-1;i++){
         swapped=true;
         for(j=0;j<n-i-1;j++){
         	if(arr[j]>arr[j+1]){
         		swap(&arr[j],&arr[j+1]);
         		swapped=true;
         	}

         }
         if(!swapped){
         	break;
         }
	}

}

void selectionSort(int *arr,int n){
  for(int i=0;i<n-1;i++){
  	int min=i;
  	for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]) min=j;
  	}
  	if(min!=i) swap(&arr[min],&arr[i]);
  }
}

//QUICK SORT
int paritition(int *arr,int l,int h){
	int pivot=arr[l];
	int i=l;int j=h;
	while(i<j){
		while(arr[i]<=pivot) i++;
		while(arr[j]>pivot) j--;
        if(i<j) swap(&arr[i],&arr[j]);
	}
	swap(&arr[j],&pivot);
	return j;
}

void quickSort(int *arr,int l,int h){
	if(l<h){
		int p=paritition(arr,l,h);
		quickSort(arr,0,p-1);
		quickSort(arr,p+1,h);
	}
}

//MERGE SORT
signed main(){
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	//Call different sorting algoritms
	cout<<"BUBBLE SORT => ";
	bubbleSort(arr,n);printArray(arr,n);
    cout<<"Modified BUBBLE SORT => ";
	modBubbleSort(arr,n);printArray(arr,n);
    cout<<"INSERTION SORT => ";
	insertionSort(arr,n);printArray(arr,n);
	cout<<"SELECTION SORT => ";
	selectionSort(arr,n);printArray(arr,n); 
	cout<<"QUICK SORT => ";
	quickSort(arr,0,n-1);printArray(arr,n);
}