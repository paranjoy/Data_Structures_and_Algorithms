/*
Inversion Count

Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an
inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.

Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).

Output format :
Count of inversions

Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9

Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/
//code snippet 

long long merge_count(int *arr,int l,int m,int r){
    int i, j, k; 
    int count = 0;
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2];  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
    i = 0; 
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] > R[j]) 
        { 
            arr[k] = R[j];
            count += n1-i;
            j++; 
        } 
        else
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    return count;
}

long long merge_sort(int* arr,int l, int r) 
{ 
    static long long c = 0;
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        merge_sort(arr, l, m); 
        merge_sort(arr, m+1, r); 
        c += merge_count(arr, l, m, r); 
    } 
    return c;
} 


long long solve(int A[], int n)
{
    return merge_sort(A,0,n-1) ;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
}
