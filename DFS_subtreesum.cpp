#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
int subtree[N],even_ct[N];

bool dfs(int vertex,int parent){

    if(vertex%2==0) even_ct[vertex]++;
    subtree[vertex]+=vertex;
	for(int child: g[vertex]){
         if(child==parent) continue;

         dfs(child,vertex);
         subtree[vertex]+=subtree[child];
         even_ct[vertex]+=even_ct[child];
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
	for(int i=1;i<=n;i++){
		cout<<depth[i]<<"  "<<height[i]<<endl;
	}
	

}