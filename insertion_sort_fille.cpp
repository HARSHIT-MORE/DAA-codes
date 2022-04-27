#include <iostream>
using namespace std;
void insertionSort(int arr[],int n,int &c,int &c1)
{
    for(int i=1;i<n;i++)
	{
		int picked=arr[i];
		int h=i-1;
    c++;
		while(h>=0&&arr[h]>picked)
		{
            c1++;
            c++;
			arr[h+1]=arr[h];
			h=h-1;
		}
		arr[h+1]=picked;
	}
}
int main()
{
   int arr[10000];
   freopen("testCases.txt","r",stdin);
   freopen("insertionResult.txt","w",stdout);
   int t=1000;
  int n=1;
   while(t--){
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   int c=0,c1=0;
   insertionSort(arr,n,c,c1);
   cout<<n<<")swap count : "<<c1<<", And comparison : "<<c<<"\n";
   
   n++;
   }
  
}