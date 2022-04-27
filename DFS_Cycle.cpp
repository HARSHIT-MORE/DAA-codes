#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
bool visited[N];


bool dfs(int vertex,int parent){
visited[vertex]=true;
bool isLoopExist=false;

	for(int child: g[vertex]){
         if(visited[child] && child==parent) continue;
         if(visited[child]) return true;
		
		isLoopExist|= dfs(child,vertex);
	}
	return isLoopExist;
	
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
	bool isLoopExist=false;
	for(int i=1;i<=n;i++){
		if(visited[i])continue;
		if(dfs(i,0)){
			isLoopExist=true;
		break;
		}
	}
	cout<<isLoopExist<<endl;
	if(isLoopExist)
		cout<<"\nContained Cycle\n";
	else{
		cout<<"No"<<endl;
	}

}