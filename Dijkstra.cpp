#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;

vector<pair<int,int>> g[N];

vector<int> dijkstra(int source){
	vector<int> visited(N,0);
	vector<int> dist(N,INF);

	set<pair<int,int>> st;

	st.insert({0,source});
	dist[source]=0;

	while(st.size()>0){
		auto node=*st.begin();
		int v=node.second;
		int v_dist=node.first;
		st.erase(st.begin());
		if(visited[v]==1) continue;  
		visited[v]=1;

		for(auto child:g[v]){
			int child_v=child.first;
			int wt=child.second;
			if(dist[v]+wt<dist[child_v]){
				dist[child_v]=dist[v]+wt;
				st.insert({dist[child_v],child_v});
			}

		}
	}
	return dist;
}


int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,wt;
		cin>>x>>y>>wt;
		g[x].push_back({y,wt});
	}
	vector<int> distance=dijkstra(0);
	for(int i=0;i<n;i++){
		cout<<i+1<<"  "<<distance[i]<<endl;
	}

}