#include<bits/stdc++.h>
using namespace std;



void leftRotate(int *arr,int n,int k){
	int mod=k%n;
    for(int i=0;i<n;i++){
    	cout<<arr[(mod+i)%n]<<" ";
    }
    cout<<endl;
}
signed main(){
	int n,k;cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	leftRotate(arr,n,k);
	
}