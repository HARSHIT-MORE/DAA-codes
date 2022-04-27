#include<iostream>
#include<vector>
using namespace std;
vector<int> g[N];
bool visited[N];
const int N=1e5 +10

void dfs(int vertex){
// Take action on vertex after entering the vertex
visited[vertex]=true;
	for(int child: g[vertex]){
		cout<<"parent "<<vertex<<" , child "<<child<<endl;
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
	}

}