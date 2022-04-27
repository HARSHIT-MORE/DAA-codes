#include<iostream>
using namespace std;
int partition(int A[],int p,int r){
	int x=A[r];
	int i=p-1;
	for(int j=p;j<r;j++){
		
		if(A[j]<=x){
			i=i+1;
			swap(A[i],A[j]);
			
		}

	}
	swap(A[i+1],A[r]);
	return i+1;

}

int Rand_partition(int arr[],int p,int r){
int random=rand()%(r-p+1)+p;
swap(arr[random],arr[r]);
return partition(arr,p,r);
}

int Rand_select(int A[],int p,int r,int i){
	if(p==r){
		return A[p];
	}
	int q=Rand_partition(A,p,r);
	int k=q-p+1;
	if(i==k){
		return A[q];
	}
	else if(i<k){
		return Rand_select(A,p,q-1,i);
	}
	else{
		return Rand_select(A,q+1,r,i-k);
	}
} 
int main(){
	int arr[]={4,5,62,45,1,6};
	int n=6;
	cout<<Rand_select(arr,0,n-1,3);

}