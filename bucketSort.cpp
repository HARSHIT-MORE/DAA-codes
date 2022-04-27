#include<bits/stdc++.h>
using namespace std;
void bucketSort(int arr[],int n,int k){
	int max=arr[0];
	for(int i=1;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
    }
    max++;
    vector<int> bucket[k];
    for(int i=0;i<n;i++){
    	int bi=(k*arr[i])/max;
    	bucket[bi].push_back(arr[i]);//bucket--> 0,1,2,3,4,5...k
    }
    for(int i=0;i<k;i++){
    	sort(bucket[i].begin(),bucket[i].end());
    }
    int index=0;
    for(int i=0;i<k;i++){
    	for(int j=0;j<bucket[i].size();j++){
    		arr[index++]=bucket[i][j];
    	}
    }
}
int main()
{
int arr[]={4,6,74,32,3,45};
int n=6;
int k=4;
bucketSort(arr,n,k);
for(int i=0;i<n;i++){
	cout<<arr[i]<<" ";
}
	return 0;

}
