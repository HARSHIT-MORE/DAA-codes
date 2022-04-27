#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
bool visited[N];

void dfs(int vertex){
// Take action on vertex after entering the vertex
visited[vertex]=true;
cout<<vertex<<" ";
	for(int child: g[vertex]){
		// cout<<"parent "<<vertex<<" , child "<<child<<endl;
         if(visited[child]) continue;
		// take action on child before entering the child node
		dfs(child);
	// take action on child after exciting child node 
	}
	// take action on vertex before exiting the vertex
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);

	}
	int ct=0;
	for(int i=1;i<=n;i++){
	if(visited[i])continue;
	dfs(i);
ct++;
	}
	cout<<"\nNo of connected component: "<<ct<<" "<<endl;

}