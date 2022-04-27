#include<iostream>
#include <list>

using namespace std;

class Graph
{
	int V; 
	list<int> *adj;
	bool *visited; 
public:
	Graph(int V); 

	
	void addEdge(int v, int w);

	
	void BFS(int s);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	visited=new bool[V];
	for(int i=0;i<V;i++){
		visited[i]=false;
	}
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int s)
{
	visited[s] = true;
	cout << s << " ";
	list<int>::iterator i;
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
			BFS(*i);
			}
		}
	}


int main()
{
	
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);

	g.addEdge(2, 4);
	g.addEdge(2, 5);
	g.addEdge(2, 3);
	g.addEdge(2, 4);

	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal "
		<< "(starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}
