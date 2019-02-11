#include<stdio.h> 

int main () 
{ 
  int number; 
  printf("enter the limit:");
  scanf("%d",&number);
 
  int f[number+2];   // 1 extra to handle case, n = 0 
  int i; 
  
 
  f[0] = 0; 
  f[1] = 1; 
  
  for (i = 2; i <= number; i++) 
  { 
      f[i] = f[i-1] + f[i-2]; 
  } 
  for(int i = 0; i<number; i++){
 	 printf("%d ", f[i]); 
  	
  }
   printf("\n "); 
  
  return 0; 
} 
