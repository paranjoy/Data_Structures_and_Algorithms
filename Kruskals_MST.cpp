#include <bits/stdc++.h>
using namespace std;
vector<int>parent;
vector<tuple<int,int,int>>edge;
vector<tuple<int,int,int>>MST;
bool compare(tuple<int,int,int>t1, tuple<int,int,int>t2){
    int a = get<2>(t1);
    int b = get<2>(t2);
    if(b > a)
        return true;
    else
        return false;
}
int find(int i)  
{  
    if (parent[i] == -1)  
        return i;  
    return find(parent[i]);  
}   
void Union(int x, int y)  
{  
    int xset = find(x);  
    int yset = find(y);  
    if(xset != yset) 
    {  
        parent[xset] = yset;  
    }  
} 

void Kruskal_MST(vector<tuple<int,int,int>>&edge, int V){
    int count = 0;
    int  i = 0;
    while(count < V - 1){
        int a = get<0>(edge[i]);
        int b = get<1>(edge[i]);
        int c = get<2>(edge[i]);
        
        if(find(a) != find(b)){
            MST.push_back(edge[i]);
            count++;
            Union(a,b);
        }
        i++;
    }
}

void print_MST(){
    
    for(int  i = 0; i < MST.size(); i++){
        int a = get<0>(MST[i]);
        int b = get<1>(MST[i]);
        int c = get<2>(MST[i]);
        
        cout << a <<" "<< b <<" "<< c << endl; 
    }
}


int main()
{
  	int V, E;
  	cin >> V >> E;
	
    parent.assign(V, -1);
    
    for(int  i = 0; i < E; i++)
    {
        int a, b , c;
        cin>>a>>b>>c;
        edge.push_back(tuple<int,int,int>(min(a,b),max(a,b),c));
    }
	
    sort(edge.begin(), edge.end(), compare);
    
    Kruskal_MST(edge, V);
    
    print_MST();

  return 0;
}
