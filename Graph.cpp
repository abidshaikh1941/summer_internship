#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
	/*	Types of graph	*/
// based on Direction Directed & Undirected
// based on cyclicity Cyclic & Acyclic
// based on Labelling Unlabelled, Vertex Labelled , Edge Labelled & vertex-edge labelled
// based on weight Weighted or Unweighted
// based on density Sparse & Dense

/*	Representing method of graph in code*/
// Ajacency Matrix - good for densed graph & Adjacency List - good for sparse graph
/*
class Graph
{
	int v;
	vector<int>* l;
public:
	Graph(int n)
	{
		v = n;
		l = new vector<int>[v];
	}
	void addEdge(int from, int to)
	{
		l[from].push_back(to);
	}

	void printList()
	{
		for (int i{}; i < v; i++)
		{
			cout << i << " - ";
			for (auto d : l[i])
			{
				cout << d << " -> ";
			}
			cout << endl;
		}
	}

};
/*considering graph as directed graph*/
template<typename T>
class Graph
{
	map < T, vector<T> > l;
public:
	void addEdge(T from, T to )
	{
		l[from].push_back(to);
	}
	void print()
	{
		for (auto i : l)
		{
			cout << i.first << " - ";
			for (auto j : i.second)
			{
				cout << j << " -> ";
			}
		
			cout << endl; 
		}
	}

	void BFS(T source)
	{
		queue<T> q;
		map<T, bool> visited;
		q.push(source);
		cout << "BFS for source " << source << " ---------\n";
		while (!q.empty())
		{
			T node = q.front();
			q.pop();
			visited[node] = true;
			cout << node << " ";
			for (auto i : l[node])
			{
				if (visited[i] == false)
				{
					q.push(i);
					visited[i] = true;
				}
			}
		}
		cout << "\n";
	}
	void dfs_recursive(T source, map<T,bool>& visited)
	{
		cout << source << " ";
		visited[source] = true;
		for (auto i : l[source])
		{
			if (!visited[i])
			{
				dfs_recursive(i, visited);
			}
		}
	}
	void DFS(T source)
	{
		map<T, bool> visited;
		for (auto i : l)
		{
			visited[i.first] = false;
		}
		cout << "DFS - search from source " << source << "\n";
		dfs_recursive(source, visited);
	}
};