#include<stdio.h>
#include <stdlib.h>



void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
 
struct record
{
	char roll_no[9];
	int aMark;
	int sMark;
}; 

int main()
{

	
	
	int n,a,b;
	int choice=3;
	int arr[100];
	int index[100];
	printf("\nenter total no of students:");
	scanf("%d",&n);
	struct record arr_student[100];
	printf("\nenter data of students :");
	for(int i=0; i<n; i++)
	{
		printf("\nEnter roll_no :");
		scanf("%s",arr_student[i].roll_no);
		printf("\nEnter arts marks(out of 100) :");
		scanf("%d",&arr_student[i].aMark);
		printf("\nEnter science marks(out of 100) :");
		scanf("%d",&arr_student[i].sMark);
	}
	printf("\n");
	printf("\troll_no\t\taMark\tsMark");
	for(int i=0;i<n;i++)
	{
		printf("\n\t%s\t%d\t%d",arr_student[i].roll_no,arr_student[i].aMark,arr_student[i].sMark);
	}
	
	
	
	while(choice!=0)
	{
	printf("\nenter your choice: \n0:break \n1:arts \n2:science :");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			{
				printf("\nenter the boundaries(a,b):");
				scanf("%d%d",&a,&b);
				printf("\troll_no\taMark");
				int j=0;
				for(int i=0;i<n;i++)
				{
					
					if(arr_student[i].aMark>=a && arr_student[i].aMark<=b)
					{	index[j]=i;
						j++;}
					
					}
				
   				int l, m; 
  				for (l = 0; l < n-1; l++)       
  
      
       				for (m = 0; m < n-m-1; m++)  
           			if (arr_student[index[m]].aMark > arr_student[index[m+1]].aMark) 
              				swap(&index[m], &index[m+1]); 
              
				for(int k=0;k<j;k++)
				{	
					
					printf("\n\t%s\t%d",arr_student[index[k]].roll_no,arr_student[index[k]].aMark);
				}
				
		
			
			}
			break;
	
		case 2:
		{
				printf("\nenter the boundaries(a,b):");
				scanf("%d%d",&a,&b);
				printf("\troll_no\tsMark");
				int j=0;
				for(int i=0;i<n;i++)
				{
					
					if(arr_student[i].sMark>=a && arr_student[i].sMark<=b)
					{	
						index[j]=i;
						j++;}
					
				}
				
   				int l, m; 
  				for (l = 0; l < n-1; l++)       
  
      
       				for (m = 0; m < n-m-1; m++)  
           				if (arr_student[index[m]].sMark > arr_student[index[m+1]].sMark) 
              					swap(&index[m], &index[m+1]); 
              
				for(int k=0;k<j;k++)
				{	
					
					printf("\n\t%s\t%d",arr_student[index[k]].roll_no,arr_student[index[k]].sMark);
				}
				
		
			
		}
		break;
	
		case 0:
			break;
		
	
	
	}
	};
	

		return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

