#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
int subtree[N];
int val[N];

bool dfs(int vertex,int parent){
    subtree[vertex]+=val[vertex];
	for(int child: g[vertex]){
         if(child==parent) continue;

         dfs(child,vertex);
         subtree[vertex]+=subtree[child];
      
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
	int ans=0;
	for(int i=2;i<=n;i++){
		int part1=subtree[i];
		int part2=subtree[1]-part1;
		ans=max(ans,part1*part2);
	}
	cout<<ans;

}