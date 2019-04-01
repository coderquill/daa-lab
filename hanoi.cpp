

#include <iostream>
#include <stdlib.h>
using namespace std;


//function to solve tower of hanoi
void towerOfHanoi(int n, char rod1, char rod2, char rod3)
{

    if (n == 1)
    {
        cout<<"\n Move disk 1 from rod "<< rod1 <<" to rod " << rod2;
        return;
    }

    towerOfHanoi(n-1, rod1, rod3, rod2);
	cout<<"\n Move disk " <<n << " from rod "<< rod1 <<" to rod " << rod2;

    towerOfHanoi(n-1, rod3, rod2, rod1);
}



int main()
{

    int n; // Number of disks

    cout<<"\nEnter the no of disks";
   	cin>>n;

    towerOfHanoi(n, 'A', 'B', 'C');  // A, B and C are names of rods


    return 0;
}
