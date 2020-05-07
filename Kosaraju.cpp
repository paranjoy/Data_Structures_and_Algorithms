#include<bits/stdc++.h>
using namespace std;
int V,E;
vector<vector<int>>edges;
vector<vector<int>>edges_tr;


void DFS_second_pass(int v, vector<bool>& visited){
	visited[v] = true;
	cout << v <<" ";

	for(int  i = 0; i < edges_tr[v].size(); i++)
		if(!visited[edges_tr[v][i]])
			DFS_second_pass(edges_tr[v][i], visited);
}

void DFS_first_pass(int v, stack<int>& st,  vector<bool>& visited){

	visited[v] = true;

	for(int i = 0; i < edges[v].size(); i++)
		if(!visited[edges[v][i]])
			DFS_first_pass(edges[v][i], st, visited);

	st.push(v);
}

void Kosaraju_SCC(){

	vector<bool> visited(V,  false);
	stack<int>st;

	for(int  i = 0; i < V; i++)
		if(!visited[i])
			DFS_first_pass(i, st, visited);

	visited.assign(V, false);

	cout << "Strongly Connected components--->" << endl;
	while(!st.empty()){

		int i = st.top();
		st.pop();

		if(!visited[i])
			DFS_second_pass(i, visited);

		cout  << endl;
	}
}

int main(){

	cin >> V >> E;

	edges.assign(V, vector<int>());
	edges_tr.assign(V, vector<int>());

	for(int i = 0; i < E; i++){
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges_tr[b].push_back(a);
	}

	Kosaraju_SCC();

	return  0;
}
