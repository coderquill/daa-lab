#include<iostream>
using namespace std;
int getMin(int arr[],int first,int last)
{
	int temp minmax,left,right;
	if(first==last)
	{
		min=arr[first];
		return min;
	}
	if(last=first+1)
	{
		if(arr[first]>arr[last])
		{
        	min = arr[last];
		}
		else
		{
			min = arr[first]; 
		}
		return min;
	}
	int mid;
	mid=(first+last)/2;
	left=getMin(arr,first,mid);
	right=getMin(arr,mid+1,last);
	if (left < right) 
    	min = left; 
  	else
    	min = right;      
  	return min; 
}
void prims(int **mat1,int n)
{
	int dist[n],i,mst[n],max=999,mat2[n][n];
	for(i=0;i<n;i++)
	{
		dist[i]=max;
		mst[i]=0;
	}
	dist[0]=0;
	mst[i]=1;
	for(i=0;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(mat1[i][j]!=0 && mat1[i][j]<max)
			{
				dist[j]=dist[j]+mat1[i][j];
			}
		}

	}
}
int main()
{
	int **matrix;
	int i,j,n,ed,w,v1,v2;
	cout<<"\nEnter the number of vertices: ";
	cin>>n;
	matrix=new int*[n];
	for(i=0;i<n;i++)
		matrix[i]=new int[n];
	cout<<"\nEnter total number of edges ";
	cin>>ed;
	for(i=0;i<ed;i++)
	{
		cout<<"\nFor edge "<<i+1;
		cout<<"\nEnter vertex 1 :";
		cin>>v1;
		cout<<"\nEnter vertex 2 :";
		cin>>v2;
		cout<<"\nEnter the weight: ";
		cin>>w;
		matrix[v1][v2]=matrix[v2][v1]=w;
	}
	cout<<"\nAdjacency Matrix:";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<matrix[i][j]<<" ";
		}	
		cout<<"\n";
	}
	prims(matrix,n);
	return  0;
}
