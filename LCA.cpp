#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
int par[N];

bool dfs(int vertex,int parent=-1){
    par[vertex]=parent;
	for(int child: g[vertex]){
         if(child==parent) continue;
         dfs(child,vertex);
	}
	
}
vector<int> path(int v){
	vector<int> ans;
	while(v!=-1){
		ans.push_back(v);
	}
	reverse(ans.begin(),ans.end());
	return ans;
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
	dfs(1);
	int x,y;
	cin>>x>>y;
	vector<int> path_x=path(x);
	vector<int> path_y=path(y);
    int mn_ln=min(path_x.size(),path_y.size());
    int lca=-1;
    for(int i=1;i<=mn_ln;i++){
    	if(path_x[i]==path_y[i]){
    		lca=path_x[i];
    	}else{
    		break;
    	}
    }
	cout<<lca<<endl;
	
}