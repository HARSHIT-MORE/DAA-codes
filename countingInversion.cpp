#include<iostream>
using namespace std;
int main(){
	int a[]={3,5,6,9,1,2,7,8};
	int ic=0;
	for(int i=0;i<8;i++){
		for(int j=i+1;j<8;j++){
			if(a[i]>a[j]){
				cout<<"("<<a[i]<<","<<a[j]<<") , ";
				ic++;
			}
		}
	}
	cout<<"\nCounting Inversion are: "<<ic<<endl;

}