#include<iostream>
#include<cmath>
using namespace std;
int c,s;
int size;
void MaxHeapify(int A[],int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	c++;
	if(l<size && A[l]>A[largest]){
		largest=l;
	}
	c++;
	if(r<size && A[r]>A[largest]){
		largest=r;
	}
	c++;
	if(largest!=i){
		s++;
		swap(A[i],A[largest]);
		MaxHeapify(A,i);
	}
}

void BuildMaxHeap(int A[],int n){
    c++;
	for(int i=n/2-1;i>=0;i--){
		MaxHeapify(A,i);
	}
}

void HeapSort(int A[],int n){
	BuildMaxHeap(A,n);
	c++;
	for(int i=n-1;i>0;i--){
		s++;
		swap(A[0],A[i]);
		size--;
		MaxHeapify(A,0);
	}

}

int main(){
	// int n;
	// cout<<"Enter number of element of Array: "<<endl;
	// cin>>n;
	// int A[n];
	// size=n;
	// for(int i=0;i<n;i++){
	// 	cout<<"Enter the element: "<<endl;
	// 	cin>>A[i];
	// }
	// HeapSort(A,n);
	// for(int i=0;i<n;i++){
	// 	cout<<A[i]<<" ";
		
	// }

	// cout<<"\nTotal Comparison are: "<<c<<endl;
	// cout<<"Total Swaps are: "<<s<<endl;

	int A[1000];
	freopen("testCases.txt","r",stdin);
   freopen("HeapSortResult.txt","w",stdout);
   int t=1000;
   int n=1;
   while(t--){
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	c=0;
	s=0;
	HeapSort(A,n);
   cout<<n<<")swap count : "<<s<<", And comparison : "<<c<<"\n";
   n++;
}

}