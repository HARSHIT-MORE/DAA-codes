#include<bits/stdc++.h>
using namespace std;
const int N=1e6 +10;

vector<int> g[N];
bool visited[N];

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
// Take action on vertex after entering the vertex

current_cc.push_back(vertex);
visited[vertex]=true;
cout<<vertex<<" ";
	for(int child: g[vertex]){
         if(visited[child]) continue;
		
		dfs(child);
	}
	
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
	current_cc.clear();
	if(visited[i])continue;
	dfs(i);
	cc.push_back(current_cc);
ct++;
	}
	cout<<"\nNo of connected component: "<<cc.size()<<" "<<endl;
cout<<"The connected component are: "<<endl;
	for(auto current_cc:cc){
		for(auto vertex:current_cc){
			cout<<vertex<<" ";
		}
		cout<<endl;
	}

}