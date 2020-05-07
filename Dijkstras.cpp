#include <bits/stdc++.h>
using namespace std;
int V, E;
vector<vector<int>>edges;

int minKey(vector<int>& distance, vector<bool>& visited)  
{  
    int min = INT_MAX;
    int min_index;  
  
    for (int i = 0; i < V; i++)  
        if (visited[i] == false && distance[i] < min)  
            min = distance[i], min_index = i;  
  
    return min_index;  
}
void path(int i,vector<int>& parent){
    if(parent[i] == -1)
        return;
    cout << parent[i] <<" ";
    path(parent[i], parent);
}
void print_shortest_path(vector<int>& parent, vector<int>& distance){
    
    cout << "considering 0 as the source vertex" << endl;
    
    for (int i = 0; i < V; i++){ 
        cout << i << " -----> " << distance[i] << " (distance)" << endl;
        cout << "PATH  --> " << i <<" ";
        
        path(i, parent);
            
        cout << endl;
    }
}

void Dijkstras(){
    
    vector<int>parent(V, INT_MIN);
    vector<int>distance(V, INT_MAX);
    vector<bool>visited(V, false);
    
    // considering 0 as the starting vertex
    parent[0] = -1;
    distance[0] = 0; 
    
    for (int count = 0; count < V - 1; count++){  
        
        int min_ele = minKey(distance, visited);  
  
        visited[min_ele] = true;  
    
        for (int i = 0; i < V; i++)  
            
            if (edges[min_ele][i] && visited[i] == false ){
            
                int curr_dist = distance[min_ele] + edges[min_ele][i];
        		
                if(curr_dist < distance[i])
                    parent[i] = min_ele, distance[i] = curr_dist;  
            }
    }
    print_shortest_path(parent, distance);
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
    
    
    Dijkstras();

 	return 0;
}
