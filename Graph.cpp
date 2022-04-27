#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
	// int v,e;
	// cout<<"Enter the vertices and edges: "<<endl;
	// cin>>v>>e;
	// int arr[v][v]={0};
	// for(int i=0;i<e;i++){
	// 	int u,v;
	// 	cin>>u>>v;
	// 	arr[u][v]=1;
	// 	arr[v][u]=1;
	// }
	// for(int i=1;i<=v;i++){
	// 	for(int j=1;j<=v;j++){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;

	// }


	//Adjacency List
	int v,e;
	cout<<"Enter the vertices and edges: "<<endl;
	cin>>v>>e;
	vector<int> arr[v+1];
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}
}