/*
     Problem Statement : From a given vertex in weighted connected graph,
     find the shortest paths to other vertices using Dijikstra's algorithm.
*/
#define max 5
#define infinity 999
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct Graph{
     int V;
     int E;
     int Adj[max][max];
}Graph;

Graph AddEdge(Graph tmp)
{
     int src,dest;
     char ch;
     do{
          printf("\nEnter source and destination :");
          scanf("%d%d",&src,&dest);
          printf("\nEnter the weight :");
          scanf("%d",&tmp.Adj[src][dest]);
          printf("\nAdd more(y/n) :");
          getchar();
          scanf("%c",&ch);
     }while(ch == 'y' || ch == 'Y');
     return tmp;
}
Graph CreateGraph()
{
     Graph tmp ;

     printf("\nEnter no of vertices :");
     scanf("%d",&tmp.V);
     
     for(int i=0;i<tmp.V;i++)
          for(int j=0;j<tmp.V   ;j++)
              tmp.Adj[i][j]=0;
    
    tmp =  AddEdge(tmp);
    return tmp;
}
int minDistance(int dist[],int visited[],int vertex)
{
     int min = INT_MAX , min_index;
     for(int i=0;i<vertex;i++)
     {    
          if(visited[i]== 0 && dist[i]<min)
         { min = dist[i]; min_index = i;}
     }
     return min_index;
     
}

void printSolution(int dist[],int V)
{
     printf("\nVertex distance from Source\n ");
     for(int i=0;i<V;i++)
     {
          printf("%d\t%d\n",i,dist[i] );
     }
}
void dijikstra(Graph g,int src)
{
     int *distance = (int *)calloc(g.V,sizeof(int));
     int *visited  = (int *)calloc(g.V,sizeof(int));
     int *from  = (int *)calloc(g.V,sizeof(int));
     
     for(int i=0;i<g.V;i++)
     {
          if(g.Adj[src][i] !=0)distance[i]=g.Adj[src][i];
           distance[i] = INT_MAX;
          from[i]=src;
     }
         distance[src]=0;

     int edges = g.V -1;
     int u;
     
     while(edges >= 0 )
     {
          u = minDistance(distance,visited,g.V);
         visited[u] = 1; 
         
         printf("%d",u);
         for(int v=0;v<g.V;v++)
         if(visited[v]!=0 && g.Adj[u][v] && distance[u] !=INT_MAX && distance[u] + g.Adj[u][v] < distance[v] )
         {
          distance[v] = distance[u] + g.Adj[u][v] ;
         }
          edges--;
     }
          printSolution(distance,g.V);
       //choose min_distance
       
       //update distance
       
      //for(int i=0;i<g.V;i++)printf("%2d",distance[i]);
     //return sdist;
}
void display(Graph g)
{
     for(int i=0;i<g.V;i++)
     {
          printf("\n");
          for(int j=0;j<g.V;j++)
              printf("%2d ",g.Adj[i][j]);
      } 
}
int main()
{
     Graph G =CreateGraph();
     display(G);
     dijikstra(G,0);
   
     return 0;
}

