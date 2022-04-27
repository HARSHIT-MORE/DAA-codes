#include<iostream>
using namespace std;
int HoarePartition(int A[],int p,int r,int &c,int &c1){
	int x=A[p];
	int i=p-1;
	int j=r+1;
	while(true){
		do{
			i++;
			c++;
		}while(A[i]<x);

		do{
			j--;
			c++;
		}while(A[j]>x);
        c++;
		if(i>=j) return j;
		swap(A[i],A[j]);
		c1++;
	}
}

void QuickSort(int A[],int p,int r,int &c,int &c1){
	if (p<r){
		int q=HoarePartition(A,p,r,c,c1);
		QuickSort(A,p,q,c,c1);
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