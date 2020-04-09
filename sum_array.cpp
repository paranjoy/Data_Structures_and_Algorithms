/*
Sum Array

Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. 
Boundary elements refer to the elements present on all the four boundaries of matrix.

Input:
First line will have a single integer ‘n’ denoting the order of matrix.
Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.

Constraints:
1<=n<=100

Output:
Print a single integer denoting the sum.

Sample input:
3
1 2 3
4 5 6
7 8 9
Sample Output:
45
*/
//code(brute force)
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int s1=0,s2=0,s3=0,s4=0;
   int *a[n]; 
    for (int i=0; i<n; i++) 
         a[i] = (int *)malloc(n * sizeof(int)); 
    
    for(int i =0;i<n;i++){
        
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            
            if(i==0 || i==(n-1))
                s3 += a[i][j];
            if(j ==0 || j==(n-1))
                s4 += a[i][j];
            if(i==j)
                s1 += a[i][j];
            if(i+j == n-1)
                s2 += a[i][j];
        }
    }
    
    int s = s1+s2+s3+s4 - 2*a[0][0] -2*a[0][n-1] - 2*a[n-1][0] - 2*a[n-1][n-1];
    if(n%2 != 0)
        s = s - a[n/2][n/2];
    
    cout<<s;
        
        
    
	return 0;
}
