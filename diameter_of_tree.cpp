#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
int depth[N];

bool dfs(int vertex,int parent){

	for(int child: g[vertex]){
         if(child==parent) continue;
         depth[child]=depth[vertex]+1;
         dfs(child,vertex);
	}
	
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);

	}
	dfs(1,0);
	int max_depth=-1;
	int max_node=1;
	for(int i=1;i<=n;i++){
		if(max_depth<depth[i]){
			max_depth=depth[i];
			max_node=i;
		}
		depth[i]=0;
	}
	dfs(max_node,0);
	max_depth=-1;
	for(int i=1;i<=n;i++){
		if(max_depth<depth[i]){
			max_depth=depth[i];
		}
	
	}
	cout<<"max depth is: "<<max_depth<<endl;

}