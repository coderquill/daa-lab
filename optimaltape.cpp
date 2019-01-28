
#include <bits/stdc++.h> 
using namespace std; 
  

void findOrderMRT(int l[], int n) 
{ 
   int i,j;
    
	for( i = 0; i < n; i++){
		for( j = i+1; j < n; j++){
			if(l[i]>l[j]){
				int temp = l[i];
				l[i] = l[j];
				l[j] = temp;
			}
		}
	}
  
    cout << "\nOptimal order in which programs are to be stored is:\n "; 
           
    for (int i = 0; i < n; i++) 
        cout << l[i] << " "; 
    cout << endl; 
  
  	double MRT=0;
  	for(int i = 0; i < n; i++){
  		int sum=0;
  		for(int j = 0; j <= i; j++){
  			sum = sum + l[j];
  		}
  		MRT = MRT + sum;
  	}
  	
  	MRT = MRT / n;
  	cout <<  "Minimum retrieval time is:\n" << MRT << "\n";
  	
} 

int main(){
	int l[10],i,n;
	
	cout << "\nEnter the total number of programs:\n";
	cin >> n;
	cout << "\nEnter retrieval time for individual programs:\n";
	for(i = 0; i < n; i++){
		cin >> l[i];
	}
	for(i = 0; i < n; i++){
		cout << l[i];
	}
	cout << endl;
	
	
	
	findOrderMRT(l,n);
	
	return 0;
	
			
}































