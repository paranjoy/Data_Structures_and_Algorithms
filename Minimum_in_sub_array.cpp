/*
Range Minimum Query
Given an array A of size N, there are two types of queries on this array.
1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
2) u x y: In this query you need to update A[x]=y.

Input:
First line of the test case contains two integers, N and Q, size of array A and number of queries.
Second line contains N space separated integers, elements of A.
Next Q lines contain one of the two queries.

Output:
For each type 1 query, print the minimum element in the sub-array A[l:r].

Contraints:
1≤N,Q,y≤10^5
1≤l,r,x≤N

Sample Input :
5 5
1 5 2 4 3
q 1 5
q 1 3
q 3 5
u 3 6
q 1 5
Sample Output :
1
1
2
1
*/

#include<bits/stdc++.h>
using namespace std;

int query(vector<int>&t, int start, int end, int i, int l, int r){
    
    if(l > end || r < start)
        return 99999999;
    if(l <= start  && r >= end)
        return t[i];
    
    int mid = (start + end)/2;
    
    int x = query(t,start,mid,2*i,l,r);
    int y = query(t,mid+1,end,2*i+1,l,r);
    
    return min(x,y);
}

void update(vector<int>&t, int start, int end, int i, int idx, int value){
    if(start == end){
        t[i] = value;
        return;
    }
    int mid = (start + end)/2;
    
    if(idx > mid){
        update(t,mid+1,end,2*i+1, idx, value);
    }
    else{
        update(t,start,mid,2*i, idx, value);
    }
    
    t[i] = min(t[2*i], t[2*i+1]);
    
}

void build(vector<int>&v, vector<int>&t, int start, int end, int i){
    if(start == end){
        t[i] = v[start];
        return;
    }
    
    int mid = (start+end)/2;
    
    build(v,t,start,mid,2*i);
    build(v,t,mid+1,end,2*i+1);
    
    t[i] = min(t[2*i], t[2*i + 1]);
}

int main() {
	int n , q;
    cin>>n>>q;
    vector<int>v;
    vector<int>t(4*n, 99999999);
    for(int i = 0; i < n ; i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
    build(v,t,0,n-1,1);
    while(q--){
        char ch; int a,b;
        cin>>ch>>a>>b;
        if(ch == 'q')
            cout<<query(t,0,n-1,1,a-1,b-1)<<endl;
        if(ch == 'u')
            update(t,0,n-1,1,a-1,b);
    }
    return 0;
}
