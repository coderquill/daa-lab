
#include<stdio.h> 
  

int max(int a, int b) { return (a > b)? a : b; } 
  
int knapSack(int capacity_of_bag, int weight[], int value[], int  no_of_items) 
{ 
   int i, w; 
   int K[no_of_items+1][capacity_of_bag+1]; 
  
   for (i = 0; i <=  no_of_items; i++) 
   { 
       for (w = 0; w <= capacity_of_bag; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (weight[i-1] <= w) 
                 K[i][w] = max(value[i-1] + K[i-1][w-weight[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[ no_of_items][capacity_of_bag]; 
} 
  
int main() 
{ 
    int value[10];
    int weight[10];
    int  no_of_items;
    int capacity_of_bag;

    printf("enter capacity of bag:");

    scanf("%d",&capacity_of_bag);

    printf("enter total no of items:");

    scanf("%d",&no_of_items);

    printf("enter values(profit) for each items:");

    for(int i = 0; i<no_of_items; i++)
    	scanf("%d",&value[i]);

    printf("enter weights for each items:");

    for(int i = 0; i<no_of_items; i++)
    	scanf("%d",&weight[i]);

    printf("Final values of items in bag:");
    
    printf("%d", knapSack(capacity_of_bag, weight, value, no_of_items)); 
    return 0; 
} 

