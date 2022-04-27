#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
bool visited[N];
int level[N];

void bfs(int source){
	queue<int> q;
	visited[source]=true;
	q.push(source);
	while(!q.empty()){
		int cur_v=q.front();
		q.pop();
		cout<<cur_v<<" ";
		for(int child:g[cur_v]){
			if(!visited[child]){
			q.push(child);
			visited[child]=true;
			level[child]=level[cur_v]+1;
		}
		}
	}
	cout<<endl;
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
	bfs(1);
	for(int i=1;i<=n;i++){
		cout<<i<<" : "<<level[i]<<endl;
	}
	
}