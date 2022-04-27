#include<iostream>
#include<climits>
using namespace std;

void merge(int A[],int l,int r,int mid,int &c,int &c1){
	int l_sz=mid-l+1;
	int L[l_sz+1];
	int r_sz=r-mid;
	int R[r_sz+1];

	for(int i=0;i<l_sz;i++){
		L[i]=A[i+l];
		c1++;
	}
	for(int i=0;i<r_sz;i++){
		R[i]=A[i+mid+1];
		c1++;
	}
	L[l_sz]=R[r_sz]=INT_MAX;
	int i=0;
	int j=0;

	for(int k=l;k<=r;k++){
		c++;
		if(L[i]<=R[j]){
			A[k]=L[i];
			c1++;
			i++;
		}
		else{
			A[k]=R[j];
			j++;
			c1++;
		}
	}
}

void mergeSort(int A[],int l,int r,int &c,int &c1){
	if(l==r)return;
	int mid=(l+r)/2;
	mergeSort(A,l,mid,c,c1);
	mergeSort(A,mid+1,r,c,c1);
	merge(A,l,r,mid,c,c1);
}
int main(){

	int A[1000];
	freopen("testCases.txt","r",stdin);
   freopen("MergeSortResult.txt","w",stdout);
   int t=1000;
   int n=1;
   while(t--){
   	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	int c=0,c1=0;
     mergeSort(A,0,n-1,c,c1);
   cout<<n<<")swap count : "<<c1<<", And comparison : "<<c<<"\n";
   n++;

   }
	
}