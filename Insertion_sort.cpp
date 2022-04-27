#include <iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)//insertion sort
	{
		int picked=arr[i];
		int h=i-1;
        if(i==4)
        {
            cout<<"At intermediate step\n Sub Array is :";
            for(int i=0;i<3;i++)
            cout<<arr[i]<<" ";
            cout<<"\n";
        }
		while(h>=0&&arr[h]>picked)
		{
			arr[h+1]=arr[h];
			h=h-1;
		}
		arr[h+1]=picked;
	}
}
int main()
{
   int arr[]={2,6,4,3,1,9,5};
   cout<<"base condition true, since first element "<<arr[0]<<" is always sorted\n";
   insertionSort(arr,7);
   cout<<"Array after termination step\n";
   for(int i=0;i<7;i++)
   cout<<arr[i]<<" ";
   cout<<"\nWhich sorted\n";
}