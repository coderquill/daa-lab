//Solution to travelling salesman problem by branch and bound approach


#include <stdio.h>
#include <stdlib.h>

typedef struct term
{
	int cost;
	int path[10];
	int matrix[10][10];
}term;

term node, list[25];
int visited[10],red_mat[10][10], temp[10][10], city, list_index=0,start_index;

int reduce_mat(int tsp_cost[10][10])
{
	int i,j,min,cost=0;
	//reducing the row
	for(i=0;i<city;i++)
	{
		min = 99999;
		for(j=0;j<city;j++)
		{
			if(min > tsp_cost[i][j])
				min = tsp_cost[i][j];
		}
		if(min != 0 && min != 99999)
		{
			for(j=0;j<city;j++)
			{
				if(tsp_cost[i][j] != 99999)
					tsp_cost[i][j] -= min;
			}
			cost += min;
		}
	}
	//reducing the column
	for(i=0;i<city;i++)
	{
		min = 99999;
		for(j=0;j<city;j++)
		{
			if(min > tsp_cost[j][i])
				min = tsp_cost[j][i];
		}
		if(min != 0 && min != 99999)
		{
			for(j=0;j<city;j++)
			{
				if(tsp_cost[j][i] != 99999)
					tsp_cost[j][i] -= min;
			}
			cost += min;
		}
	}
	for(i=0;i<city;i++)
	{
		for(j=0;j<city;j++)
			temp[i][j] = tsp_cost[i][j];
	}
	return cost;
}

void set_infinity(int r,int j)
{
	int i,red_i,red_j;
	for(i=0;i<city;i++)
	{
		red_mat[r][i] = 99999;
		red_mat[i][j] = 99999;
	}
	red_mat[j][0] = 99999;
}

term min_node()
{
	int i,j,min = 99999, pos;
	for (i = start_index; i < list_index; i++)
	{
		if (min > list[i].cost)
		{
			min = list[i].cost;
			pos = i;
		}
	}
	return list[pos];
}

term expand(term node)
{
	int i,j,k,r,cost,cost1,count,loop_i,loop_j;
	int temp_mat[10][10];
	term temp_node, min;
	while(1)
	{
		start_index = list_index;
		count = node.path[0];
		k = count+1;
		cost = node.cost;
        printf("\n    %d    \n",cost);
		for(i=0;i<10;i++) //node.matrix is being stored into temp_mat
		{
			for(j=0;j<10;j++)
				temp_mat[i][j] = node.matrix[i][j];
		}
		r = node.path[count]; //last city in this path
		for(i=0;i<city;i++)
			visited[i]=0;
		for(i=1;i<=count;i++)
			visited[node.path[i]]=1;
		for(j=0;j<city;j++)
		{
			if(!visited[j])
			{
				for(loop_i=0;loop_i<city;loop_i++) //store temp_mat into red_mat
				{
					for(loop_j=0;loop_j<city;loop_j++)
					{
						red_mat[loop_i][loop_j] = temp_mat[loop_i][loop_j];
					}
				}
				set_infinity(r,j);
				cost1 = reduce_mat(red_mat);
				temp_node = node;
				node.cost = cost+cost1+temp_mat[r][j];
				node.path[0] = k;
				node.path[k] = j;
				for(loop_i=0;loop_i<city;loop_i++) //store red_mat into node.matrix
				{
					for(loop_j=0;loop_j<city;loop_j++)
					{
						node.matrix[loop_i][loop_j] = red_mat[loop_i][loop_j];
					}
				}
				list[list_index] = node;
				list_index++;
				node = temp_node;
			}
		}
		if(k==city)
			break;
		node = min_node();
	}
	return node;
}

int main()
{
	int i,j, tsp_cost[10][10];
	printf("Enter the number of cities\n");
	scanf("%d", &city);
	//initializing the tsp_cost matrix and the red_mat matrix
	for(i=0;i<city;i++)
	{
		for(j=0;j<city;j++)
		{
			printf("Enter the distance between city %d and city %d \n", i+1, j+1);
			scanf("%d", &tsp_cost[i][j]);
			// red_mat[i][j] = tsp_cost[i][j];
		}
	}
	node.cost = reduce_mat(tsp_cost);
    printf("\n %d \n",node.cost);
	printf("Initial reduced matrix\n");
	for(i=0;i<city;i++)
	{
		for(j=0;j<city;j++)
			printf("%d \t ",temp[i][j]);
		printf("\n");
	}
	node.path[0] = 1; //number of nodes traversed
	node.path[1] = 0; //the first node has been traversed. (matrix starts from 0)
	for(i=0;i<city;i++)
	{
		for(j=0;j<city;j++)
			node.matrix[i][j] = temp[i][j];
	}
	node = expand(node);
	printf("cost -- %d\n",node.cost);
	for(i=1;i<=city;i++)
		printf("%d-->",list[list_index-1].path[i]+1);
	printf("1\n");
}
