#include<iostream>
using namespace std;
int partition(int A[],int p,int r,int &c,int &c1){
	int x=A[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		c++;
		if(A[j]<=x){
			i=i+1;
			swap(A[i],A[j]);
			c1++;
		}

	}
	c1++;
	swap(A[i+1],A[r]);
	return i+1;

}

void QuickSort(int A[],int p,int r,int &c,int &c1){
	if (p<r){
		int q=partition(A,p,r,c,c1);
		QuickSort(A,p,q-1,c,c1);
		QuickSort(A,q+1,r,c,c1);
	}
}
int main(){
	int n;
	cout<<"Enter no. of element: "<<endl;
	cin>>n;
	int A[n];
	cout<<"Enter the element: "<<endl;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int c=0,c1=0;
	QuickSort(A,0,n-1,c,c1);
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<"\nTotal comparison are: "<<c<<endl;
	cout<<"Total swaps are: "<<c1<<endl;

}