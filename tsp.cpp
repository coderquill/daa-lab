#include<iostream>

using namespace std;

int tsp(int cn,int g[][100],int visited[],int dist[],int nodes,int src)
{
	int i,flag = 0,j;
	visited[cn] = 1;
	cout<<"\ncn = "<<cn<<"\nvisited : ";
	for(i=1;i<=nodes;i++)
	cout<<visited[i]<<"\t";
	
	cout<<"\n";
	for(i=1;i<=nodes;i++)
	{
		if(visited[i]==0)
		{	flag = 1;
			break;
		}
	}
	
	if(flag == 0)
	{
		
		//dist[cn] = g[cn][src];
		cout<<"\ndist "<<cn<<"="<<dist[cn]<<"\t";
		visited[cn] = 0;
		return g[cn][src];
	}
	
	
	for(i=1;i<=nodes;i++)
	{
	
		if(visited[i] != 1)
		{
		cout<<"\nprevious cn="<<cn<<" i="<<i<<" dist "<<dist[cn]<<"\t";
		dist[cn] = min(dist[cn],g[cn][i]+tsp(i,g,visited,dist,nodes,src));
		cout<<"\ncn = "<<cn<<" i="<<i<<" dist "<<dist[cn]<<"g[cn][i]"<<g[cn][i]<<"\t";
		visited[i] = 0;
		
		}
		
		
		
	
	}
	
	
	return dist[cn];
}



int main()
{

	int array[100][100];
	int nodes,i,j,edges;
	int *visited,*dist;
	int u,v,weight;
	cout<<"ENTER NO OF NODES : ";
	cin>>nodes;
	
	visited = new int[nodes+1];
	dist = new int[nodes+1];
	
	for(i=1;i<=nodes;i++)
	{
		visited[i] = 0;
		dist[i] = 1000;
		for(j=1;j<=nodes;j++)
		{
			array[i][j] = 0;
		}
	
	
	}
	dist[1] = 1000;
	visited[1] = 1;
	cout<<"ENTER NO OF EDGES : ";
	cin>>edges;
	
	for(j=0;j<edges;j++)
	{
		cout<<"ENTER START VERTEX ,END VERTEX AND WEIGHT : ";
		cin>>u>>v>>weight;
		array[u][v] = weight;
	
	}
	
	
	for(i=1;i<=nodes;i++)
	{
		
		for(j=1;j<=nodes;j++)
		{
			cout<<array[i][j]<<"\t";
		}
		cout<<endl;
	
	
	}


	cout<<"\ncost :"<<tsp(1,array,visited,dist,nodes,1)<<"\n";


}
