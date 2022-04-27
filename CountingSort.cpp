#include<iostream>
using namespace std;

void CountingSort(int A[],int n,int B[],int k){
  int c[k];
  for(int i=0;i<=k;i++){
    c[i]=0;
  }

  for(int j=0;j<n;j++){
  	c[A[j]]=c[A[j]]+1;
  }
  for(int i=1;i<=k;i++){
  	c[i]=c[i]+c[i-1];
  }
  for(int j=n-1;j>=0;j--){
  	B[c[A[j]]-1]=A[j];
  	c[A[j]]=c[A[j]]-1;
  }
}

int main(){
	 int n;
	cout<<"Enter number of element of Array: "<<endl;
	cin>>n;
	int A[n];
	int B[n];
	cout<<"Enter the value of k: "<<endl;
	int k;
	cin>>k;
	for(int i=0;i<n;i++){
		cout<<"Enter the element: "<<endl;
		cin>>A[i];
	}
	CountingSort(A,n,B,k);
	for(int i=0;i<n;i++){
		cout<<B[i]<<" ";
		
	}
}
