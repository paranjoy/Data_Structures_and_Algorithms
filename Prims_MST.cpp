#include <bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>>edges;

int minKey(vector<int>& weight, vector<bool>& visited)  
{  
    int min = INT_MAX;
    int min_index;  
  
    for (int i = 0; i < V; i++)  
        if (visited[i] == false && weight[i] < min)  
            min = weight[i], min_index = i;  
  
    return min_index;  
}

void print_MST(vector<int>& parent, vector<int>& weight){
    
    for(int i = 1; i< V; i++)
        if(parent[i] < i)
            cout << parent[i] <<" "<< i << " "<< weight[i] << endl;
        else
            cout << i <<" "<< parent[i] << " "<< weight[i] << endl;
}

void Prims_MST(){
    
    vector<int>parent(V, INT_MIN);
    vector<int>weight(V, INT_MAX);
    vector<bool>visited(V, false);
    
    parent[0] = -1;
    weight[0] = 0;
    
    for (int count = 0; count < V - 1; count++){  
        
        int min_ele = minKey(weight, visited);  
  
        visited[min_ele] = true;  
    
        for (int i = 0; i < V; i++)  
            
            if (edges[min_ele][i] && visited[i] == false && edges[min_ele][i] < weight[i])  
                parent[i] = min_ele, weight[i] = edges[min_ele][i];  
    
    }
    print_MST(parent, weight);
}

int main()
{
  	cin >> V >> E;
	
    edges.assign(V, vector<int>(V,0));
    
    for(int  i = 0; i < E; i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges[a][b] = w;
        edges[b][a] = w;
    }
    
    
    Prims_MST();

 	return 0;
}
