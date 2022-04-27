#include<iostream>
using namespace std;

int GetMax(int arr[],int n){
	int max=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	return max;
}
void countingSort(int arr[],int n,int div){
	int output[n];
	int count[10]={0};
	for(int i=0;i<n;i++){
		count[(arr[i]/div)%10]++;
	}
	for(int i=1;i<10;i++){
		count[i]=count[i]+count[i-1];
	}
	for(int i=n-1;i>=0;i--){
		output[count[(arr[i]/div)%10]-1]=arr[i];
		count[(arr[i]/div)%10]--;
	}
	for(int i=0;i<n;i++){
		arr[i]=output[i];
	}
}

void RadixSort(int arr[],int n){
	int m=GetMax(arr,n);
	for(int div=1;m/div>0;div*=10){
		countingSort(arr,n,div);
	}
}

int main(){
	int n;
	cout<<"Enter no of element: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element of array: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	RadixSort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
}