/*
Triplet sum

Given a random integer array and a number x. Find and print the triplets of elements in the array which sum to x.
While printing a triplet, print the smallest element first.
That is, if a valid triplet is (6, 5, 10) print "5 6 10". There is no constraint that out of 5 triplets which
have to be printed on 1st line. You can print triplets in any order,
just be careful about the order of elements in a triplet.

Input format :
Line 1 : Integer N (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer x

Output format :
Line 1 : Triplet 1 elements (separated by space)
Line 2 : Triplet 3 elements (separated by space)
Line 3 : and so on

Constraints :
1 <= N <= 1000
1 <= x <= 100

Sample Input:
7
1 2 3 4 5 6 7 
12
Sample Output ;
1 4 7
1 5 6
2 3 7
2 4 6
3 4 5
*/
//code snippet


// arr - input array
// size - size of array
// x - sum of triplets
int partition(int *a,int l,int u){
    int start =l,end=u,temp,pivot=a[l];
    while(start<end){
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end){
            temp =a[start];
            a[start]=a[end];
            a[end]=temp;
        }
    }
    temp = pivot;
    a[l]=a[end];
    a[end]=pivot;
    return end;
}
void quick_sort(int *a,int l,int u){
    if(l<u){
        int loc = partition(a,l,u);
        quick_sort(a,l,loc-1);
        quick_sort(a,loc+1,u);
    }
}
void FindTriplet(int arr[], int size, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */
    quick_sort(arr,0,size-1);
    
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k = j+1;k<size;k++){
                int sum =arr[k]+arr[i] +arr[j];
                if(sum==x){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                }
            }
        }
    }

}
