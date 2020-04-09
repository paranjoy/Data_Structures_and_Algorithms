/*
Aggressive Cows Problem
Send Feedback
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. 
The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance 
between any two of them is as large as possible. What is the largest minimum distance?

Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

Output
For each test case output one integer: the largest minimum distance.

Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/
//code
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool possible(ll *a,int n,int c,ll mid){
    int last = a[0],count =1;
    for(int i=1;i<n;i++){
        if((a[i]-last)>=mid){
            count++;
            last=a[i];
        }
        if(count==c)
            return true;
    }
  
    return false;
}

int main() {

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,c;
        cin>>n>>c;
        if(c>n)
            cout<<0<<endl;
        else if(c==n)
            cout<<1<<endl;
        else{
            ll a[n];
            for(int j =0;j<n;j++){
                cin>>a[j];
            }
            sort(a,a+n);
            ll min = a[0], max = a[n-1] -a[0];
            ll largest = -1;
            while(max>=min){
                ll mid  = min + (max-min)/2;
                if(possible(a,n,c,mid)){
                    min=mid+1;
                    largest=mid;
                }
                else
                    max = mid-1;
            }
            cout<<largest<<endl;
        }
    }
}
