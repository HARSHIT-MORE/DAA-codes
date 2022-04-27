#include<iostream>
#include<climits>
using namespace std;

void merge(int A[],int l,int r,int mid){
	int l_sz=mid-l+1;
	int L[l_sz+1];
	int r_sz=r-mid;
	int R[r_sz+1];

	for(int i=0;i<l_sz;i++){
		L[i]=A[i+l];
	}
	for(int i=0;i<r_sz;i++){
		R[i]=A[i+mid+1];
	}
	L[l_sz]=R[r_sz]=INT_MAX;
	int i=0;
	int j=0;

	for(int k=l;k<=r;k++){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
	}
}

void mergeSort(int A[],int l,int r){
	if(l==r)return;
	int mid=(l+r)/2;
	mergeSort(A,l,mid);
	mergeSort(A,mid+1,r);
	merge(A,l,r,mid);
}
int main(){

	int A[]={5,4,3,6,1};
	mergeSort(A,0,5);
	for(int i=0;i<5;i++){
		cout<<A[i]<<" ";
	}

}