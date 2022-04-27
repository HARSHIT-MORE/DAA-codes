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
int KthSmallest(int A[],int n,int k){
	int l=0,r=n-1;
	while(l<=r){
		int p=partition(A,l,r);
		if(p==k-1){
			return p;
		}
		else if(p>k-1){
			r=p-1;
		}
		else{
			l=p+1;
		}
	}
	return -1;
}

int main(){
int A[]={65,43,23,49,12};
int index=KthSmallest(A,6,4);
cout<<A[index]<<endl;
}