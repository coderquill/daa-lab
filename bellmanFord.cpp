#include<iostream>
#include <bits/stdc++.h> 
 using namespace std;
 

// a structure to represent a weighted edge in graph 
struct Edge 
{ 
    int src, dest, weight; 
}; 

struct Graph 
{ 
  
    int V, E; 
  
    struct Edge* edge; 
}; 
  

struct Graph* createGraph(int V, int E) 
{ 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
  

void printArr(int dist[], int n) 
{ 
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 

void BellmanFord(struct Graph* graph, int src) 
{ 
    int V = graph->V; 
    int E = graph->E; 
    int dist[V]; 
  
    for (int i = 0; i < V; i++) 
        dist[i]   = INT_MAX; 
        
    dist[src] = 0; 
  
    for (int i = 1; i <= V-1; i++) 
    { 
        for (int j = 0; j < E; j++) 
        { 
            int u = graph->edge[j].src; 
            int v = graph->edge[j].dest; 
            int weight = graph->edge[j].weight; 
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                dist[v] = dist[u] + weight; 
        } 
    } 
  
   
    for (int i = 0; i < E; i++) 
    { 
        int u = graph->edge[i].src; 
        int v = graph->edge[i].dest; 
        int weight = graph->edge[i].weight; 
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            printf("Graph contains negative weight cycle\n"); 
    } 
  
    printArr(dist, V); 
  
    return; 
} 
  

int main() 
{ 
   
    //int V = 5;  
    //int E = 8; 
    int V,E,src;
    cout<<"Enter the number of vertex\n";
    cin>>V;
    cout<<"Enter the number of edges\n";
    cin>>E;
    struct Graph* graph = createGraph(V, E); 
  
  	for(int i = 0; i<E; i++){
  		cout<<"enter the source destination and weight of an edge " << i+1 <<"\n";
  		cin>> graph->edge[i].src >> graph->edge[i].dest >>  graph->edge[i].weight;
  	}
    
  	cout<<"Enter the source vertex:\n";
  	cin>>src;
    BellmanFord(graph, src); 
  
    return 0; 
} 

